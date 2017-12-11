#include "TreeNode.h"

// Your function here

TreeNode *makeFullRight(int n) {
int counter=1;
TreeNode *head=new TreeNode();
TreeNode *curr=head;
curr->data_=counter;
if(n==1){
return head;
}
while(counter<=n-2){
TreeNode *left=new TreeNode();
curr->left_=left;
curr->left_->data_=counter+1;
TreeNode *right=new TreeNode();
curr->right_=right;
curr->right_->data_=counter+2;
/*curr->left_=new TreeNode();
curr->left_->data_=counter+2;
curr=curr->right_;*/
curr=curr->right_;
counter=counter+2;
}
return head;
}


// Methods and functions we provide following.
// You should not need to edit this code.

TreeNode::TreeNode(int data, TreeNode *left, TreeNode *right) :
    data_(data), left_(left), right_(right) {}

TreeNode::~TreeNode() {
    if (left_ != NULL)
        delete left_;
    if (right_ != NULL)
        delete right_;
}

bool equal(TreeNode *n1, TreeNode *n2) {
    if (n1 == NULL)
        return n2 == NULL;

    if (n2==NULL)
        return false;

    return (n1->getData() == n2->getData() &&
            equal(n1->getLeft(),n2->getLeft()) &&
            equal(n1->getRight(),n2->getRight()));
}

int TreeNode::getData() const {
    return data_;
}

TreeNode *TreeNode::getLeft() const {
    return left_;
}

TreeNode *TreeNode::getRight() const {
    return right_;
}

