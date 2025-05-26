#include <iostream>
using namespace std;
class BST
{
private:
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode* parent;//for successor and predecessor
        //creates TreeNode with null left and right child and value
        TreeNode(int val, TreeNode* left = nullptr, TreeNode* right = nullptr) {
            //constructor for each TreeNode (node) in Bst 
               //
            this->val = val;
            this->left = left;
            this->right = right;
        }//TreeNode constructor
    };//struct TreeNode
    TreeNode* root;

public:
    BST() {//no argument constructor
        root = nullptr;//will create empty tree
    }//end of constructor

    void insertNode(int x) {
        //insertNode function prototype
        root = insert(root, x);
    }//insertNode

    void deleteBst(int x) {
        //deleteNode function prototype
        root = deleteNode(root, x);//passing root and value to be deleted
        //returning reconstructed tree after deletion
        
    }//insertNode



    int searchBST(int x) {//searchBST 
        //insertNode function prototype
        int val = search(root, x);//passing root and value to search for
        if (val == 1) {//if value returned is 1 the value exists in tree
            cout << endl << "the value exists" << endl;
        }//if
        else {//otherwise value does not exist in tree
            cout << endl << "the value does not exist" << endl;
        }//else
        return val;
    }//insertNode


    void nodesInBst() {
        //nodes in Bst
        int nodes = numberOfNodes(root);
        cout << endl << "number of Nodes: " << nodes << endl;
    }//nodesInBst

    void heightBst() {
        int heightOfTree = height(root);
        cout << endl << "height of BST: " << heightOfTree << endl;
    }//heightBst

    void destroyBst() {
        //insertNode function prototype
        root = destroyTree(root);
    }//insertNode

    void balancedBst() {
        //insertNode function prototype
        int balance = balanceCheck(root);
        cout << endl << "checking if tree is balanced: " << endl;
        if (balance == 1) {//must be balanced
            cout << endl << "the tree is balanced " << endl;
        }//if
        else {
            cout << endl << "the tree is not balanced " << endl;
        }//else
    }//insertNode





    void inorderDisplay() {
        inorder(root);
    }//inorderDisplay

    void preorderDisplay() {
        preorder(root);
    }//preOrderDisplay

    void postorderDisplay() {
        postorder(root);
    }//postorderDisplay

    int successorBST(int x) {
        //insertNode function prototype
        int val = successor(root, x, nullptr);
        cout << endl << "value of successor: " << val << endl;
        return val;
    }//insertNode

    int predecessorBst(int x) {
        //insertNode function prototype
        int val = predecessor(root, x, nullptr);
        cout << endl << "value of predecessor: " << val << endl;
        return val;
    }//predecessor



    TreeNode* insert(TreeNode*, int x);//insert
    int search(TreeNode*, int val);//function to search for Node value in BST
    //return integer value to determine whether value is found/not found
    //creating member functions for BST traversals
    int numberOfNodes(TreeNode*);//function that calculates amount of nodes
    int predecessor(TreeNode*, int val, TreeNode*);//function that looks for node right before
    //inputted node in inorder traversal
    //in BST
    int successor(TreeNode*, int val, TreeNode*);
    TreeNode* deleteNode(TreeNode*, int x);//function to delete node
    int balanceCheck(TreeNode*);//function to check if tree is balanced
    int height(TreeNode*);
    void inorder(TreeNode*);
    void preorder(TreeNode*);
    void postorder(TreeNode*);
    int leftMost(TreeNode*);
    TreeNode* leftMostNode(TreeNode*);//function to destroy tree return nullptr
    TreeNode* destroyTree(TreeNode*);//function to destroy tree return nullptr
    int rightMost(TreeNode*);
};//class








