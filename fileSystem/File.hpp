#ifndef PATH
#define PATH
#include <filesystem>
#include <list>
#include <iostream>
#include <functional>
#include <fstream>
#include <sstream>
using namespace std;
using namespace std::filesystem;

class Path; //��ʾ�ļ�·��
class FileTraverser;    //һ���ļ�������



class Path{
private:
    path p;
public:

    explicit Path(string str):p(str){}
    explicit Path(char* str):p(str){}
    explicit Path(path p):p(p){}

    //ǰ��
    Path forward(string childName){
        string pa = toString();
        pa+=path::preferred_separator;
        pa+=childName;
        return Path(pa);
    }

    //����
    Path backward(){
        return (Path)p.parent_path();
    }

    //�Ƿ���Ŀ¼
    bool isDirectory(){
        return is_directory(p);
    }

    //�Ƿ��ǳ����ļ�
    bool isFile(){
        return is_regular_file(p);
    }

    //·���Ƿ����
    bool exists(){
        return std::filesystem::exists(p);
    }

    //���ַ�������·��
    string toString(){
        return p.string();
    }

    //����ת������
    operator path(){
        return p;
    }

    //�����ļ���
    path getFileName(bool withExtension = true){
        if(withExtension){
            return p.filename();
        }else{
            return p.stem();
        }
    }

    //�����ļ���չ��������Ϊ�Ƿ����ţ�
    string getExtension(bool withPoint = true){
        if(withPoint){
            return p.extension().string();
        }else{
            string e = p.extension().string();
            return e.substr(1,e.size()-1);
        }
    }

    //��ȡ�ļ���С
    int getFileSize(){
        return file_size(p);
    }

    //ɾ���ļ�
    bool remove(){
        return std::filesystem::remove(p);
    }

    //�ݹ��ɾ�������ļ�
    bool removeAll(){
        return remove_all(p);
    }

    //�����ļ���Ŀ¼
    void copyTo(Path pa){
        copy(p,(path)pa);
    }

    //�����ļ�
    void copyFile(Path pa){
        copy_file(p,(path)pa);
    }

    //����Ŀ¼
    bool mkdir(bool recursive = true){
        if(recursive){
            //����ݹ�
            return create_directories(p);
        }else{
            return create_directory(p);
        }
    }

    //������·���µ������ļ�,��������
    list<Path> listFiles(){
        list<Path> fileList;

        for(auto& child:directory_iterator(p)){
            fileList.push_back((Path)child);
        }
        return fileList;
    }

    //���ı��ļ����ļ�
    string readAsText(){
        char buffer[255];
        stringstream ss;
        ifstream inFile;
        inFile.open(toString(),ios::in);
        while(!inFile.eof()) {
            inFile.getline(buffer, 255);
            ss<<buffer<<endl;
        }
        return ss.str();
    }

    //��ȡϵͳ��ʱ�ļ�·��
    static Path tempDirectory(){
        return (Path)temp_directory_path();
    }

    //��ȡ��ǰ�ļ����ڵ�·��
    static Path currentPath(){
        return Path(current_path());
    }
};

ostream& operator<<(ostream& out,Path pa){
    return out<<pa.toString();
}

/*
 * �ļ������������ᰴ��ָ���������һ��ָ�����ļ��е����ļ������ļ���
 * */
class FileTraverser{
public:
    using FileFilter = function<bool(Path)>;
private:
    Path root;
    Path temp;
    list<Path> fileList;
    list<FileFilter> filters;

    //�ļ��������Ƿ�������ļ�ͨ��
    bool filterAccept(const Path& p){
        bool ret = true;
        for(auto &filter:filters){
            ret &= filter(p);
        }
        return ret;
    }

    //�����ļ������ط���������·������
    void traverseFile(){
        for(auto &child:temp.listFiles()){
            if(filterAccept(child)){
                fileList.push_back(child);
            }
            if(child.isDirectory()){
                temp = child;
                traverseFile();
            }
        }
    }
public:

    explicit FileTraverser(const Path& root):root(root),temp(root){}
    void addFilter(const FileFilter& filter){
        filters.push_back(filter);
    }

    //�����ļ�����������
    void start(){
        fileList.clear();
        traverseFile();
    }

    //��ȡ�������
    list<Path> getResult(){
        return fileList;
    }

    //��ȡ����
    Path getRoot(){
        return root;
    }

    //�ļ������������
    static FileFilter combineFilter(initializer_list<FileFilter> filters){
        return [&](Path p)->bool{
            bool b = true;
            for(auto &filter:filters){
                b = b & filter(p);
            }
            return b;
        };
    }
};

#endif