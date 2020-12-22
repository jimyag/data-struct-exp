//
// Created by jimyag on 2020/11/25.
//
#include <iostream>

using namespace std;
constexpr int MaxSize = 1000;


typedef char ElemType;

typedef struct BiTNode {
    ElemType data;
    struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;

bool InitTree(BiTree &t) {
    t = new BiTNode;
    t->rChild = t->lChild = NULL;
    return true;
}


void CreateTree(BiTree &b, char str[]) {
    char ch;
    BiTree stack[MaxSize], p;               //stack[MaxSize]为指针数组，其每一个元素都为指向bitnode这种结构的指针，p为临时指针
    int top = -1, k, j = 0;                   //top为栈顶指针、k决定谁是左、右孩子、j为str指针

    while ((ch = str[j++]) != '\0') {
        switch (ch) {
            case '(':
                top++;
                stack[top] = p;           //根节点入栈
                k = 1;                    //1为左孩子
                break;
            case ',':
                k = 2;                   //2为右孩子
                break;
            case ')':
                top--;                  //根节点出栈
                break;
            default:
                p = new BiTNode;
                p->data = ch;
                p->lChild = p->rChild = NULL;

                if (b == NULL)        //树为空时
                    b = p;
                else                   //树非空时
                {
                    switch (k) {
                        case 1:
                            stack[top]->lChild = p;           //根节点的左孩子
                            break;
                        case 2:
                            stack[top]->rChild = p;          //根节点的右孩子
                            break;
                    }
                }
        }
    }
}

void PrintTree(BiTree b) {
    if (b) {
        cout << b->data;              //访问根节点
        if (b->lChild != NULL && b->rChild != NULL) {
            cout << "(";
            PrintTree(b->lChild);        //递归处理左子树
            if (b->rChild != NULL)
                cout << ",";
            PrintTree(b->rChild);       //递归处理右子树
            cout << ")";
        }
    }
}

BiTree FreeTree(BiTree b) {
    if (b != NULL) {
        FreeTree(b->lChild);        //递归释放左子树
        FreeTree(b->rChild);       //递归释放右子树

        free(b);               //释放根节点
        b = NULL;              //释放指向根节点的指针
    }

    return b;                   //return NULL;
}

bool bracketMatch(char arr[]) {
    char stack[MaxSize];
    char ch;
    int i = 0, Top = -1;
    while (arr[i] != '\0') {
        ch = arr[i];
        switch (ch) {
            case '(':
                ++Top;
                stack[Top] = ch;

                break;
            case ')':
                --Top;
                if (Top < -1)
                    return false;
                break;
            default :
                break;
        }
        i++;
    }
    if (-1 == Top) return true;
    return false;
}

int BTHeight(BiTree b) {
    int lChildH;
    int rChildH;
    if (b == NULL) return 0;
    else {
        lChildH = BTHeight(b->lChild);
        rChildH = BTHeight(b->rChild);
        return (lChildH>rChildH)?(lChildH+1):(rChildH+1);
    }
}

void PreOrder(BiTree b){
    if(b!= NULL){
        cout<<b->data<<" ";
        PreOrder(b->lChild);
        PreOrder(b->rChild);
    }
}

void InOrder(BiTree b){
    if(b!= NULL){
        InOrder(b->lChild);
        cout<<b->data<<" ";
        InOrder(b->rChild);
    }
}

void PostOrder(BiTree b){
    if(b!= NULL){
        PostOrder(b->lChild);
        PostOrder(b->rChild);
        cout<<b->data<<" ";
    }
}

int DisLeaf(BiTree b){
    static int num;
    if(b!= NULL){
        if(b->lChild== NULL&&b->rChild==NULL) {
            cout << b->data << " ";
            ++num;
        }
        DisLeaf(b->lChild);
        DisLeaf(b->rChild);
    }
    return num;
}
void DisBTree(BiTree b ){
    if(b!=NULL){
        cout<<b->data<<"";
        if(b->lChild!=NULL||b->rChild!=NULL){
            cout<<"(";
            DisBTree(b->lChild);
            if(b->rChild!=NULL)
                cout<<",";
            DisBTree(b->rChild);
            cout<<")";
        }
    }
}

BiTree FindNode(BiTree b,ElemType x){
    BiTNode *p;
    if(b==NULL) return NULL;
    else if(b->data==x)
        return b;
    else{
        p = FindNode(b->lChild,x);
        if(p!=NULL) return p;
        else return FindNode(b->rChild,x);
    }
}

int Nodes(BiTree b){
    int num1,num2;
    if(b==NULL) return 0;
    else
        return Nodes(b->lChild)+Nodes(b->rChild)+1;

}


int main() {
    char str[] = "A(B(D(,G)),C(E,F))";
    cout << "str: " << str << endl;//
    if(!bracketMatch(str)){
        cout<<"Error Exit!"<<endl;
        return 0;
    }
    BiTree root = NULL;            //不要忘记初始化
    CreateTree(root, str);
    cout<<"Tree : "<<endl;
    DisBTree(root);
    cout<<endl;
    cout<<"C child :"<<endl;
    if(FindNode(root,'C')!=NULL){
        cout<<"leftChild:"<<FindNode(root,'C')->lChild->data<<endl;
        cout<<"rightChild:"<<FindNode(root,'C')->rChild->data<<endl;
    }
    else{
        cout<<"Not Found"<<endl;
    }

    cout<<"F data :";
    cout<<FindNode(root,'F')->data<<endl;

    cout<<"Height: "<<BTHeight(root)<<endl;
    cout<<"Nodes:"<<endl;
    cout<<Nodes(root)<<endl;

    cout<<"leaf: ";
    cout<<DisLeaf(root);
    cout << endl;

    cout<<"PreOrder:";
    PreOrder(root);
    cout<<endl;

    cout<<"InOrder:";
    InOrder(root);
    cout<<endl;
    cout<<"PostOrder:";
    PostOrder(root);
    cout<<endl;
    cout<<"BTHeight:";
    cout<<BTHeight(root)<<endl;

    cout<<"display:";
    DisBTree(root);
    cout<<endl;


//
    root = FreeTree(root);
    if (root == NULL)
        cout << "Delete Successful" << endl;

    return 0;


}