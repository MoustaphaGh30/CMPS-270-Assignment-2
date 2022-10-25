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
    struct treeNode<T> * Node_pointer=(treeNode<T>*)malloc(sizeof(treeNode<T>));
    Node_pointer->data=*data;
    Node_pointer->left=NULL;
    Node_pointer->right=NULL;
    return Node_pointer;
}
#define struct treeNode;
// template <typename T>
// class Btree{
//     public:
//     treeNode<T> *overallRoot;
//     Btree(){
//         overallRoot=nullptr;
//     }
//     // Btree(struct treeNode root){
//     //     overallRoot=*root;
//     // }
//    // template <typename T>
//     void addNode(T data){
//         if (overallRoot==NULL)
//         {
//             treeNode<T> *overallRoot=New_Node(*data);
//             return;
//         }
//         else if (overallRoot->left==NULL&&overallRoot->right!=NULL){
//             treeNode<T> *addNode=New_Node(*data);
//             overallRoot->left=addNode;
//         }
//         else if (overallRoot->left!=NULL&&overallRoot->right==NULL){
//             treeNode<T> addNode=New_Node(*data);
//             overallRoot->right=addNode;
//         }
//         else {
//             addNode(overallRoot->left,data);
//             addNode(overallRoot->right,data);
//         }
//     }
//    // template <typename T>
//     void traversePreOrder(treeNode<T> *Node){
//         if (Node==NULL)
//         return;
//         else {
//         cout<<" "<<Node->data;
//         traversePreOrder(Node->left);
//         traversePreOrder(Node->right);
//         }

//     }

// };
int main(){
    treeNode<int> *root=New_Node(4);
    cout<<root->data;
    // Btree <int>tree;
    // tree.overallRoot=root;
    // treeNode<int> *node1=New_Node(1);
    // treeNode<int> *node2=New_Node(2);
    // treeNode<int> *node3=New_Node(3);
    // treeNode<int> *node4=New_Node(4);
    // treeNode<int> *node5=New_Node(5);
    // tree.addNode(*(node1->data));
    // tree.addNode(*(node2->data));
    // tree.addNode(*(node3->data));
    // tree.addNode(*(node4->data));
    // tree.traversePreOrder(tree.overallRoot);
    // free(node1);
    // free(node2);
    // free(node3);
    // free(node4);
    // free(node5);
     free(root);
    return 0;
}