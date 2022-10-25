#include <iostream>
using namespace std;
template <typename T>
    struct treeNode{
        T *data;
        struct treeNode<T> * left;
        struct treeNode<T> * right;
        treeNode(T *dataa, treeNode<T> leftt, treeNode<T> rightt) {
            data=dataa;
            left=leftt;
            right=rightt;
        }

    };

template <typename T>
treeNode <T> * New_Node(T data){
    auto * Node_pointer=new treeNode<T>();
    Node_pointer->data=&data;
    Node_pointer->left=nullptr;
    Node_pointer->right=nullptr;
    return Node_pointer;
}
template <typename T>
class Btree{
    public:
    treeNode<T> *overallRoot;
    explicit Btree(treeNode<T> *root){
        this->overallRoot=root;
    }
    int isEmpty(){
        return (overallRoot==NULL);
    }
    void addNode(T data){
        this->overallRoot=insert(this->overallRoot,data);
    }   
    treeNode<T> *insert(treeNode<T> *root,T data){
        if (isEmpty()) {
            overallRoot = root;
            return overallRoot;
        }
        if (root==nullptr)
        {
            root=New_Node(data);
            return root;
        }
        else if (root->left==nullptr&&root->right!=nullptr){
            //treeNode<T> *added_Node=New_Node(data);
            root->left= insert(root->left,data);
        }
        else if (root->left!=nullptr&&root->right==nullptr){
            //treeNode<T> *added_Node=New_Node(data);
            root->right= insert(root->right,data);
        }
       // else {
          //  insert(root->left,data);
         //   insert(root->right,data);
        //}
        return root;
    }
    void traversePreOrder(){
        PreOrder(overallRoot);
    }
    void PreOrder(treeNode<T> *Node){
        if (Node==nullptr)
        return;
        else {
        printf("%d",*(Node->data));
        PreOrder(Node->left);
        PreOrder(Node->right);
        }

    }

};
int main(){
    int x=4;
    int *y=&x;
    struct treeNode<int> root=new treeNode(y,NULL,NULL);
    cout<<" "<<*(root->data)<<endl;
     auto *tree=new Btree<int>(root);
     tree->addNode(*(root->data));
     int *a=tree->overallRoot->data;
     cout<<*a;
     //tree->traversePreOrder();
//     treeNode<int> *node1=New_Node(1);
//     treeNode<int> *node2=New_Node(2);
//     treeNode<int> *node3=New_Node(3);
//     treeNode<int> *node4=New_Node(4);
//     treeNode<int> *node5=New_Node(5);
//     //cout<<" "<<*(node1->data);
//      tree->addNode(*(node1->data));
//      tree->addNode(*(node2->data));
//      tree->addNode(*(node3->data));
//      tree->addNode(*(node4->data));
//     tree->traversePreOrder(tree->overallRoot);
//     delete(node1);
//     delete(node2);
//     delete(node3);
//     delete(node4);
//     delete(node5);
     delete(root);
    return 0;
}