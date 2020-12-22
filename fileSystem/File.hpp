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

class Path; //表示文件路径
class FileTraverser;    //一个文件遍历器



class Path{
private:
    path p;
public:

    explicit Path(string str):p(str){}
    explicit Path(char* str):p(str){}
    explicit Path(path p):p(p){}

    //前进
    Path forward(string childName){
        string pa = toString();
        pa+=path::preferred_separator;
        pa+=childName;
        return Path(pa);
    }

    //后退
    Path backward(){
        return (Path)p.parent_path();
    }

    //是否是目录
    bool isDirectory(){
        return is_directory(p);
    }

    //是否是常规文件
    bool isFile(){
        return is_regular_file(p);
    }

    //路径是否存在
    bool exists(){
        return std::filesystem::exists(p);
    }

    //以字符串返回路径
    string toString(){
        return p.string();
    }

    //类型转换函数
    operator path(){
        return p;
    }

    //返回文件名
    path getFileName(bool withExtension = true){
        if(withExtension){
            return p.filename();
        }else{
            return p.stem();
        }
    }

    //返回文件扩展名（参数为是否带点号）
    string getExtension(bool withPoint = true){
        if(withPoint){
            return p.extension().string();
        }else{
            string e = p.extension().string();
            return e.substr(1,e.size()-1);
        }
    }

    //获取文件大小
    int getFileSize(){
        return file_size(p);
    }

    //删除文件
    bool remove(){
        return std::filesystem::remove(p);
    }

    //递归地删除所有文件
    bool removeAll(){
        return remove_all(p);
    }

    //复制文件或目录
    void copyTo(Path pa){
        copy(p,(path)pa);
    }

    //复制文件
    void copyFile(Path pa){
        copy_file(p,(path)pa);
    }

    //创建目录
    bool mkdir(bool recursive = true){
        if(recursive){
            //如果递归
            return create_directories(p);
        }else{
            return create_directory(p);
        }
    }

    //遍历该路径下的所有文件,返回链表
    list<Path> listFiles(){
        list<Path> fileList;

        for(auto& child:directory_iterator(p)){
            fileList.push_back((Path)child);
        }
        return fileList;
    }

    //按文本文件打开文件
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

    //获取系统临时文件路径
    static Path tempDirectory(){
        return (Path)temp_directory_path();
    }

    //获取当前文件所在的路径
    static Path currentPath(){
        return Path(current_path());
    }
};

ostream& operator<<(ostream& out,Path pa){
    return out<<pa.toString();
}

/*
 * 文件遍历器，将会按照指定规则遍历一个指定的文件夹的子文件及子文件夹
 * */
class FileTraverser{
public:
    using FileFilter = function<bool(Path)>;
private:
    Path root;
    Path temp;
    list<Path> fileList;
    list<FileFilter> filters;

    //文件过滤器是否允许该文件通过
    bool filterAccept(const Path& p){
        bool ret = true;
        for(auto &filter:filters){
            ret &= filter(p);
        }
        return ret;
    }

    //搜索文件，返回符合条件的路径链表
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

    //启动文件搜索过滤器
    void start(){
        fileList.clear();
        traverseFile();
    }

    //获取遍历结果
    list<Path> getResult(){
        return fileList;
    }

    //获取树根
    Path getRoot(){
        return root;
    }

    //文件过滤器的组合
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