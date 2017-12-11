#include "TreeNode.h"
#include <iostream>
#include <cmath>

// Part 1 code

void rotateRight(TreeNode *& root) {

    TreeNode *nuRoot = root->left_;
    root->left_ = nuRoot->right_;
    nuRoot->right_ = root;

    root = nuRoot;

    updateHeight(root);
    updateHeight(root->right_);
    return;
}


void rotateLeft(TreeNode *& root) {

    TreeNode *nuRoot = root->right_;
    root->right_ = nuRoot->left_;
    nuRoot->left_ = root;

    root = nuRoot;

    updateHeight(root);
    updateHeight(root->left_);
    return;
}

void rotateLeftRight(TreeNode* &root) {
    rotateLeft(root->left_);
    rotateRight(root);
}


void rotateRightLeft(TreeNode* &root) {
    rotateRight(root->right_);
    rotateLeft(root);
}

// Your Code

void insert(TreeNode* &root, int val) {
    // Your code here
/*
    // The following lines are to silence compiler warnings.  Delete it.
    val = 0;
    root = NULL;
*/
	if(root==NULL){
		root=new TreeNode(val);
		return;
	}
	else if(root->val_==val){return;}
	else if(root->val_>val)
		{insert(root->left_,val);
		rebalance(root);	
		}
	else if(root->val_<val)
		{insert(root->right_,val);
		rebalance(root);	
		}
	root->height_=1+fmax(heightOrNeg1(root->left_),heightOrNeg1(root->right_));
}

void rebalance(TreeNode* &root) {
    // The following line is to silence compiler warnings.  Delete it.
/*    root = NULL;
    return;*/
	TreeNode*right=root->right_;
	TreeNode*left=root->left_;
	int hr=heightOrNeg1(root->right_);
	int hl=heightOrNeg1(root->left_);
	if(hr-hl>=-1 && hr-hl <=1)
	{//balanced
	return;
	}
	if(hr>hl)
	{
	int hrr=heightOrNeg1(right->right_);
	int hrl=heightOrNeg1(right->left_);
		if(hrr>=hrl)
		{
		rotateLeft(root);
		}
		else rotateRightLeft(root);
	}
	else if(hr<hl)
	{
	int hlr=heightOrNeg1(left->right_);
	int hll=heightOrNeg1(left->left_);
		if(hll>=hlr)
		{
		rotateRight(root);
		}
		else rotateLeftRight(root);
	}
}

// Helper functions

int heightOrNeg1(TreeNode *root) {
    if (root==NULL)
        return -1;
    else
        return root->height_;
}

void updateHeight(TreeNode * node) {
    node->height_ = 1 + std::max(heightOrNeg1(node->right_), heightOrNeg1(node->left_));
}

using namespace std;

void show(TreeNode *t1) {
    if (t1==NULL) {
        cout << "x";
        return;
    }

    if (t1->left_ == NULL && t1->right_==NULL) {
        cout << t1->val_;
        return;
    }

    cout << "(" << t1-> val_ << " ";
    show(t1->left_);
    cout << " ";
    show(t1->right_);
    cout << ")";
}

void deleteTree(TreeNode* root)
{
    if (root == NULL) return;
    deleteTree(root->left_);
    deleteTree(root->right_);
    delete root;
    root = NULL;
}

