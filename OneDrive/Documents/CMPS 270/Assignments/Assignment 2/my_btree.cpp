#include <iostream>
#include <queue>
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
    // if (data==) {
    //     cout<<"Null data";
    //     return nullptr;
    // }
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
        queue<treeNode<T>*> q;
    q.push(root);
 
    while (!q.empty()) {
        treeNode<T>* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = node;
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = node;
            return root;
        }
    }
        // else if (*(root->data)>=*(node->data))
        // {
        //     root->left = insert(root->left,node);
        // }
        // else
        // {
        //     root->right = insert(root->right,node);
        // }
        return root;
    }
    treeNode<T> *search_Helper(treeNode<T> * root, T data)
    {   
        if(root!=nullptr){
            if (*(root->data)==data)
            return root;
            else {
                treeNode<T> *foundNode=search_Helper(root->left,data);
                if (foundNode==nullptr)
                foundNode=search_Helper(root->right,data);
            }
        }
        else 
        return nullptr;

    }
    treeNode<T> *delete_helper(treeNode<T> *root, T data){
        if (root==nullptr)
        return nullptr;
        root->left=delete_helper(root->left,data);
        root->right=delete_helper(root->right,data);
        if(root->left==nullptr&&root->right==nullptr&&*(root->data)==data)
        return nullptr;
        return root;
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
            cout << "Null passed!"<<endl;
        else
            overallRoot =insert(overallRoot,node);
    }
    treeNode<T> *deleteNode(T data)
    {
       return delete_helper(overallRoot,data);
    }
    int subtreeSize(T data)
    {
        treeNode<T>* node = search(data);
        char size =  treeSize_Helper(node);
        return size;
    }
};
int main(){
    Btree<int> *tree=new Btree<int>();
    //The tree contains integers.
    treeNode<int> *root= New_Node(0);
    treeNode<int> *node1= New_Node(3);
    treeNode<int> *node2= New_Node(5);
    treeNode<int> *node3= New_Node(1);
    treeNode<int> *node4=New_Node(8);
    treeNode<int> *node5=New_Node(2);
//     tree->addNode(root);
//      tree->addNode(node1);
//      tree->addNode(node2);
//      tree->addNode(node3);
//      tree->addNode(node4);
//      tree->addNode(node5);
    // Btree<char> *tree=new Btree<char>();
    // //The tree contains chars.
    //  treeNode<char> *root= New_Node('b');
    //  treeNode<char> *node1= New_Node('A');
    //  treeNode<char> *node2= New_Node('1');
    //  treeNode<char> *node3= New_Node('?');
    //  treeNode<char> *node4=New_Node('<');
    //  treeNode<char> *node5=New_Node('*');
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
    treeNode<int> *findnode=tree->search(5);
    cout<<"  "<<*(findnode->data)<<endl;
     tree->deleteNode(2);
     cout<<"Size after deleting a node= "<<tree->treeSize()<<"\n";
    // cout<<"PostOrder Traversal: ";
    // tree->traversePostOrder();
     delete(node1);
     delete(node2);
     delete(node3);
    delete(node4);
    delete(node5);
     delete(root);
    return 0;
}