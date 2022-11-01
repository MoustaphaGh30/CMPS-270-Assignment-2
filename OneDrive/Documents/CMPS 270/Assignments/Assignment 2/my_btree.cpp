#include <iostream>
using namespace std;
template <typename T>
    struct treeNode{
        T *data;
        struct treeNode<T> * left;
        struct treeNode<T> * right;

    };

template <typename T>
treeNode <T> * New_Node(T data){
    auto * Node_pointer= new treeNode<T>();
    Node_pointer->data=&data;
    Node_pointer->left=nullptr;
    Node_pointer->right=nullptr;
    return Node_pointer;
}
template <typename T>
class Btree{
    public:
    treeNode<T> *overallRoot;
     Btree() {
         overallRoot= nullptr;
     }
    int isEmpty(){
        return (overallRoot==nullptr);
    }
    void addNode(treeNode<T> *node){
        if (node->data==nullptr) {
            cout<<"Null data\n";
            return;
        }
        insert(overallRoot,node->data);
     }
    void insert(treeNode<T> *root,T *data){
        treeNode<T> *New_Node=new treeNode<T>();
        New_Node->data=data;
        int a=*(New_Node->data);
        New_Node->left=nullptr;
        New_Node->right=nullptr;
        if (isEmpty()) {
            overallRoot = New_Node;
        }
        else if(root->left== nullptr&&root->right== nullptr){
            root->left=New_Node;
        }
        else if (root->left==nullptr&&root->right!=nullptr){
            root->left= New_Node;
        }
        else if (root->left!=nullptr&&root->right==nullptr){
            root->right= New_Node;
        }
        else {
            insert(root->left,data);
            insert(root->right,data);
        }
    }
    void traversePreOrder(){
        PreOrder(overallRoot);
    }
    void PreOrder(treeNode<T> *Node){
        if (Node==nullptr)
        return;
        else {
            int a=*(Node->data);
        cout<<"   "<<a;
        PreOrder(Node->left);
        PreOrder(Node->right);
        }

    }

};
int main(){
    int x=4;
    int *y=&x;
    struct treeNode<int> *root=(new treeNode<int>());
    int a=4;
    int b=3;
    int c=5;
    int d=1;
    root->data=&a;
     //tree->traversePreOrder();
     treeNode<int> *node1=new treeNode<int>();
     node1->data=&b;
     treeNode<int> *node2=new treeNode<int>();
     node2->data=&c;
     treeNode<int> *node3=new treeNode<int>();
     node3->data=&d;
//    cout<<" "<<*(root->data)<<endl;
    Btree<int> *tree=new Btree<int>();
//     treeNode<int> *node4=new treeNode<int>();
//     treeNode<int> *node5=new treeNode<int>();
      tree->addNode(node1);
      tree->addNode(node2);
      tree->addNode(node3);
//      tree->addNode(*(node3->data));
//      tree->addNode(*(node4->data));
     tree->traversePreOrder();
     delete(node1);
     delete(node2);
     delete(node3);
     delete(root);
    return 0;
}