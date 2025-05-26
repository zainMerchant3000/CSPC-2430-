#include "BST.h"
#include <iostream>
#include <cmath>
using namespace std;


//A.Insert a node to BST
//You will need to ensure there are no duplicated in your insert function (i.e., the tree should refuse to insert a duplicate key).
BST::TreeNode* BST::insert(TreeNode* t, int x) {
    if (t == nullptr) {//if treeNode is empty
        //create new Node with null left and right child
        return new TreeNode(x);
    }//if
    else if (x < t->val) {//current node is greater than node to be inserted
        t->left = insert(t->left, x);//go to left subtree
        return t;
    }//else if
    else if (x > t->val) {//current node is less than node to be inserted
        t->right = insert(t->right, x);//go to right subtree
        return t;
    }//else if
    else {//neither smaller nor bigger (and current node is not null)
        //node checked is same/duplicate do nothing
        return t;
    }//else

}//insert




//B.	Search a value from BST
//If the user input value is one of the keys stored in your BST, return 1; otherwise, return -1.
int BST::search(TreeNode* t, int key) {
    if (t == nullptr) {
        return -1;
    }//if
    else if (key < t->val) {//is greater than key value
        return search(t->left, key);//go left
    }//else if
    else if (key > t->val) {//is less than key value
        return search(t->right, key);//go right
    }//else if
    else {//otherwise
        return 1;
        //value you are searching for neither greater or less or empty (must be same value)
    }//else

}//searchBST

int BST::leftMost(TreeNode* t) {//helper function that goes to leftMost (for successor)
    while (t != nullptr && t->left != nullptr) {//check if left child exists or if t itself is null
        t = t->left;//keep going left
    }//while
    return t->val;//return value of t that is found

}//leftMost

int BST::rightMost(TreeNode* t) {//helper function that goes to rightMost (for predeccessor)
    while (t != nullptr && t->right != nullptr) {//check if right child exists or if t itself is null
        t = t->right;//keep going right
    }//while
    return t->val;//return value of t that is found

}//rightMost




//C.Find the predecessor for a given value
//Input an existing value stored in your tree, and return the value stored in its predecessor node. 
//You do not need to consider the situation when the input value is not stored in your BST. 
//Only input the values already stored in your BST.
int BST::predecessor(TreeNode* t, int key, TreeNode* succ) {
    if (t == nullptr) {//if BST is empty
        return -1;//there cannot be successor if BST is empty
    }//if

    if (t->val == key) {//if we have found the key
        if (t->left != nullptr) {//if t has a left child (a left subtree of t exists)
        //there must be some value of n that is smaller than the current t
            return rightMost(t->left);// got to right most of left subtree to find predecessor
        }//if
    }//if
    else if (t->val > key) {//current value larger than key
        return predecessor(t->left, key, succ);//go left
    }//else if
    else {//otherwise t->val < key
        succ = t;//remember parent
        return predecessor(t->right, key, succ);//go right
    }//else
    if (succ == nullptr) {
        return -2;
    }//if
    else {
        return succ->val;//return
    }//else

}//predecessor




BST::TreeNode* BST::leftMostNode(TreeNode* t) {//helper function that goes to leftMost and returns node
    while (t != nullptr && t->left != nullptr) {
        t = t->left;
    }//while
    return t;

}//



//D.	Find the successor for a given node
//Input an existing value stored in your tree, and return the value stored in its successor node. You do not need to consider the situation when the input value is not stored in your BST. Only input the values already stored in your BST.
int BST::successor(TreeNode* t, int key, TreeNode* succ) {
    if (t == nullptr) {//if BST is empty
        return -1;//there cannot be successor if BST is empty
    }//if

    if (t->val == key) {//if we have found the key
        if (t->right != nullptr) {//if t has a right child (a right subtree of t exists)
        //there must be some value of n that is larger than the current t
            return leftMost(t->right);
        }//if

    }//if
    else if (t->val > key) {
        succ = t;//remember parent
        return successor(t->left, key, succ);
    }//else if
    else {//otherwise t->val < key
        return successor(t->right, key, succ);
    }//else
    if (succ == nullptr) {
        return -2;
    }//if
    else {
        return succ->val;
    }//else

}//successor


//E.Find the height of the tree
//Return the height of your BST. The return value should be an integer.
int BST::height(TreeNode* t) {
    int heightLeft;
    int heightRight;
    if (t == nullptr) {//if Tree does not exist
        return -1;//height is -1 (no tree)
    }//if
    //check left and right subtree see which one is bigger/longer?
    //(height is the longest path from node to leaf)
    else {
        //count length of path of right and left subtree of BST
        heightLeft = 1 + height(t->left);
        heightRight = 1 + height(t->right);

        //check which height is larger?
        if (heightLeft > heightRight) {//left subtree of root has longest path
            return heightLeft;
        }//if
        else if (heightLeft < heightRight) {//right subtree has longest path
            return heightRight;
        }//else if
        else {//both left and right subtree have same height (no longest height)
            return heightLeft;//return one of th heights does not matter which one?
        }//else

    }//else

}//height




//F.	Number of nodes in your tree
//Return the number of total nodes in your BST. The return value should be an integer.

int BST::numberOfNodes(TreeNode* t) {
    if (t == nullptr) {//if current node t is empty (we don't want to add anything)
        return 0;
    }//if
    else {//otherwise add nodes from left and right subtree
        return 1 + numberOfNodes(t->left) + numberOfNodes(t->right);// +1 add current node t + number of nodes in left and right subtree
    }//else
}//numberOfNodes


//G.	Delete a leaf node based on the value
//Delete a leaf node based on the value given by the user. After deleting the node, your BST should be reconstructed. You do not need to consider the situation when the input value is not stored in your BST or the input value is not a value in leaf nodes.
BST::TreeNode* BST::deleteNode(TreeNode* t, int x) {
    if (t != nullptr) {
      
    }
   
    TreeNode* subtree;//
    TreeNode* temp;
    if (t == nullptr) {
        return nullptr;
    }//if

    if (t->val > x) {
        t->left = deleteNode(t->left, x);
        return t;
    }//else if
    else if (t->val < x) {
        t->right = deleteNode(t->right, x);
        return t;
    }//else if
    else if (t->left != nullptr && t->right != nullptr) {//if node to be deleted
        //has two children left and right child
        temp = leftMostNode(t->right);
        t->val = temp->val;
        t->right = deleteNode(t->right, temp->val);
        return t;
    }//else if
    else if (t->left == nullptr && t->right == nullptr) {
        //no children 
        delete t;//can simply delete node (and return nullptr)
        return nullptr;
    }//else if
    else if (t->right == nullptr) {//has no right child (has left child)
        subtree = t->left;
        delete t;
        return subtree;
    }//else if
    else {//otherwise tree must have right child
        subtree = t->right;
        cout << endl << "subtree value: " << subtree->val << endl;
        delete t;
        return subtree;
    }//else
    
    //otherwise node to be deleted has 1 child or no children
}//deleteNode


//H.	Traverse the tree INORDER
void BST::inorder(TreeNode* t) {
    if (t == nullptr) {
        return;
    }//if
    //inorder ->  (left -> middle (current print) -> right)
    inorder(t->left);
    std::cout << t->val << std::endl;
    inorder(t->right);

}//inorder

//I.	Traverse the tree PREORDER
void BST::preorder(TreeNode* t) {
    if (t == nullptr) {
        return;
    }//if
    //preorder ->  (middle (current print) -> left -> right)
    std::cout << t->val << std::endl;
    preorder(t->left);
    preorder(t->right);


}//preorder

//J.	Traverse the tree POSTORDER
void BST::postorder(TreeNode* t) {

    // create base case for recursion (can't go anymore left or right when reach leaf node
    // current node has nullptr
    if (t == nullptr) {
        return;
    }//if
    //postorder ->  left -> right -> middle (current print)
    postorder(t->left);
    postorder(t->right);
    std::cout << t->val << std::endl;

}//postorder


//K.	Balance check
//Input the root note of this tree. If this BST is balanced, return 1; otherwise, return -1.
//balanced binary tree
//height and  check if balance is connected
int BST::balanceCheck(TreeNode* t) {
    if (t == nullptr) {
        return 1;//tree is empty  balanced
    }//if
    //store values of left and right subtree height from height function
    int leftHeight = height(t->left);
    int rightHeight = height(t->right);
    if (abs(leftHeight - rightHeight) <= 1 && balanceCheck(t->left) && balanceCheck(t->right)) {//if difference
        //of left and right height is less than 1 at any point in subtree (tree is balanced)
        return 1;
    }//if
    //otherwise tree is not balanced return -1
    return -1;//tree not balanced height of left and right subtree differ by more than 1


}//balanceCheck


//L.	Destroy the tree
//Return nullptr after the tree is destroyed successfully.
BST::TreeNode* BST::destroyTree(TreeNode* t) {
    if (t != nullptr) {//keep going until t is nullptr
        destroyTree(t->left);//destroy left subtree
        destroyTree(t->right);//destroy right subtree
        delete t;
    }//if
    return nullptr;//return empty tree (nullptr)
}//destroyTree




