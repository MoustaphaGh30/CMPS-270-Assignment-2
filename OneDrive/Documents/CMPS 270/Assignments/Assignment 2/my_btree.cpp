#include <iostream>
/*
 TreeNode <T> *NewNode(T data)
 Requires: a data of any type.
 effects: a newly created node with null right and left.
    If we pass Null: NewNode (nullptr) nothing is created.
    If we pass a +ve integer: NewNode(1) Returns pointer to a node with data 1.
    If we pass a -ve integer: NewNode(-99) Returns pointer to a node with data -99.
    if we pass character as an int:NewNode('5') Returns pointer to a node with data '5'.
    If we pass a lowercase char:NewNode('f') Returns pointer to a node of value 'f'.
    If we pass an uppercase char: NewNode('L') Returns: pointer to a node with data 'L'.

 ______________________________________________________________________________________________
    void traversePreOrder()
    Requires: nothing
    Effects: prints the elements in Pre-order.
    void traversePostOrder()
    Requires: nothing
    Effects: prints the elements in Post-order.
    void traverseInOrder()
    Requires: nothing
    Effects: prints the elements in In-order.

_________________________________________________________________________________________________

    void AddNode(treeNode<T> *node)
    Requires: a TreeNode of type the tree.
    Effects: adds the node to an already existing Btree.
_________________________________________________________________________________________________
    void DeleteNode(T data)
    Requires: a data of type the same as tree.
    effects: searches for the node and deletes it if it has no children,
    otherwise it returns an error.
__________________________________________________________________________________________________
    void treeSize() and subTreesize(TreeNode <T> *root)
    Require: nothing
    treesize returns the size of the whole tree, 0 if the tree is empty.
    subtreeSize returns the size of the tree rooted at the specified node
 */
using namespace std;
template <typename T>
    struct treeNode{
        T *data;
        struct treeNode<T> * left;
        struct treeNode<T> * right;

    };

template <typename T>
treeNode <T> * New_Node(T data){
    if (data==NULL) {
        cout<<"Null data";
        return nullptr;
    }
    T *dataptr=new T;
    *dataptr=data;
    auto * Node_pointer= new treeNode<T>();
    Node_pointer->data=dataptr;
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
    private:
    int isEmpty(){
        return (overallRoot==nullptr);
    }
    treeNode<T>* insert(treeNode<T>* root, treeNode<T>*node)
    {
        if(root==nullptr)
        {
            root = node;
            return root;
        }
        else if (*(root->data)>=*(node->data))
        {
            root->left = insert(root->left,node);
        }
        else
        {
            root->right = insert(root->right,node);
        }
        return root;
    }
    treeNode<T>* search_Helper(treeNode<T> * root, T data)
    {
        if(root == nullptr)
            return nullptr;
        else if(*(root ->data) == data)
            return root;
        else if(data > *(root -> data))
            return search_Helper(root ->right,data);
        else if(data < *(root ->data))
            return search_Helper(root->left,data);
    }
    int treeSize_Helper(treeNode<T>* root)
    {
        if(root == nullptr)
            return 0;
        else
            return 1 + treeSize_Helper(root -> left) + treeSize_Helper(root -> right);
    }
    void PreOrder(treeNode<T> *Node){
        if (Node==nullptr)
        return;
        else {
            cout<<*(Node->data)<<"  ";
        PreOrder(Node->left);
        PreOrder(Node->right);
        }

    }
    void PostOrder(treeNode<T> *Node){
        if (Node== nullptr)
            return;
        else {
            PreOrder(Node->left);
            PreOrder(Node->right);
            cout<<*(Node->data)<<"  ";
        }
    }
    void inOrder(treeNode<T> *Node){
        if (Node== nullptr)
            return;
        else {
            PreOrder(Node->left);
            cout<<*(Node->data)<<"  ";
            PreOrder(Node->right);
        }
    }
    public:
    void traversePostOrder(){
         PostOrder(overallRoot);
     }
    void traversePreOrder(){
        PreOrder(overallRoot);
    }

     void traverseInOrder(){
         inOrder(overallRoot);
     }
    treeNode<T>* search(T data)
    {
        return search_Helper(overallRoot,data);
    }
    int treeSize()
    {
        return treeSize_Helper(overallRoot);
    }
    void addNode(treeNode<T>* node)
    {
        if(node == nullptr)
            cout << "Null passed!";
        else
            overallRoot =insert(overallRoot,node);
    }
    void deleteNode(T data)
    {
        treeNode<T>* node = search(data);
        if((node ==nullptr) || (node->left != nullptr) || (node->right != nullptr))
            cout<<" error, we have children!"<< endl;
        else
            delete(node);
    }
    int subtreeSize(T data)
    {
        treeNode<T>* node = search(data);
        char size =  treeSize_Helper(node);
        return size;
    }
};
int main(){
    //Btree<int> *tree=new Btree<int>();
    //The tree contains integers.
//     treeNode<int> *root= New_Node(4);
//     treeNode<int> *node1= New_Node(3);
//     treeNode<int> *node2= New_Node(5);
//     treeNode<int> *node3= New_Node(1);
//     treeNode<int> *node4=New_Node(8);
//     treeNode<int> *node5=New_Node(2);
//     tree->addNode(root);
//      tree->addNode(node1);
//      tree->addNode(node2);
//      tree->addNode(node3);
//      tree->addNode(node4);
//      tree->addNode(node5);
    Btree<char> *tree=new Btree<char>();
    //The tree contains chars.
     treeNode<char> *root= New_Node('b');
     treeNode<char> *node1= New_Node('A');
     treeNode<char> *node2= New_Node('1');
     treeNode<char> *node3= New_Node('?');
     treeNode<char> *node4=New_Node('<');
     treeNode<char> *node5=New_Node('*');
     tree->addNode(root);
      tree->addNode(node1);
      tree->addNode(node2);
      tree->addNode(node3);
      tree->addNode(node4);
      tree->addNode(node5);
    cout<<"PreOrder Traversal: ";
    tree->traversePreOrder();
    cout<<"\n";
    cout<<"PostOrder Traversal: ";
    tree->traversePostOrder();
    cout<<"\n";
    cout<<"InOrder Traversal: ";
    tree->traverseInOrder();
    cout<<"\n";
    cout<<"Size= "<<tree->treeSize();
    tree->deleteNode('?');
    cout<<"Size after deleting a node= "<<tree->treeSize();
     delete(node1);
     delete(node2);
     delete(node3);
    delete(node4);
    delete(node5);
     delete(root);
    return 0;
}