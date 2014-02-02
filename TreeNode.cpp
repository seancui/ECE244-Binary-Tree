//function and and class definition for TreeNode class
#include "TreeNode.h"

TreeNode::TreeNode(DBentry* _entryPtr){
    entryPtr = _entryPtr; //points to Dbentry object
    left = NULL; //sets pointers to children to NULL
    right = NULL;
}

TreeNode::~TreeNode(){
    delete entryPtr; //deletes DBentry object that the TreeNode points to
}

void TreeNode::setLeft(TreeNode* newLeft){
    left = newLeft;
}

void TreeNode::setRight(TreeNode* newRight){
    right = newRight;
}

TreeNode* TreeNode::getLeft() const{
    return left;
}

TreeNode* TreeNode::getRight() const{
    return right;
}

DBentry* TreeNode::getEntry() const{
    return entryPtr;
}

DBentry* TreeNode::maximum(){
    if (right == NULL) //if the right is NULL it is at the farthest right node
        return entryPtr;
    else
        return right->maximum(); //otherwise go farther right
}

bool TreeNode::remove(string name, TreeNode*& cur){
    if (name < entryPtr->getName()){ //if the required name is less than the current DBentry's name go left
        if (left != NULL)
            return left->remove(name, left);
    }
    if (name > entryPtr->getName()){//if the required name is greater than the current DBentry's name go right
        if (right != NULL)
            return right->remove(name, right);
    }

    //at this point the correct position has been found
    if (cur->getEntry()->getName() == name){
        if ((left == NULL) && (right == NULL)){ //if cur does not have children
            cur = NULL;
            delete this;
            return true; //means that it has been deleted
        }
        else if ((left == NULL) && (right != NULL)){ //if cur has only a child on right
            cur = right;
            right = NULL;
            delete this;
            return true;
        }
        else if ((left != NULL) && (right == NULL)){ //if cur has only child on left
            cur = left;
            left = NULL;
            delete this;
            return true;
        }
        else{ //if cur has 2 children
            DBentry* tmp = left->maximum(); //finds right most node on left subtree
            left->remove(tmp->getName(), left);
            entryPtr = tmp; //sets entry pointer to point to tmp
            return true;
        }
    }
    else
        return false;
}
