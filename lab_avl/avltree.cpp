/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include <algorithm>
template <class K, class V>
V AVLTree<K, V>::find(const K& key) const
{
    return find(root, key);
}

template <class K, class V>
V AVLTree<K, V>::find(Node* subtree, const K& key) const
{
    if (subtree == NULL)
        return V();
    else if (key == subtree->key)
        return subtree->value;
    else {
        if (key < subtree->key)
            return find(subtree->left, key);
        else
            return find(subtree->right, key);
    }
}

template <class K, class V>
void AVLTree<K, V>::rotateLeft(Node*& t)
{
    functionCalls.push_back("rotateLeft"); // Stores the rotation name (don't remove this)
    //functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
//if(t==NULL) return;
//if(t->right==NULL) return;
//if(t->right->right==NULL) return;
/*Node * z=t;
Node *y= t->right;
Node *x=y->right;
z->right=y->left;
y->left=z;
y->right=x;
t=y;
z->height=1+max(heightOrNeg1(z->left),heightOrNeg1(z->right));
y->height=1+max(heightOrNeg1(y->left),heightOrNeg1(y->right));
*/
Node *y=t->right;
t->right=y->left;
y->left=t;

y->height=1+max(heightOrNeg1(y->left),heightOrNeg1(y->right));
t->height=1+max(heightOrNeg1(t->left),heightOrNeg1(t->right));
t=y;
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    //functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
   functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    //functionCalls.push_back("rotateLeft");
    // your code here
//if(t==NULL) return;
//if(t->left==NULL)return;
//if(t->left->left==NULL) return;
Node *z=t;
Node *y=t->left;
Node *x=y->left;
z->left=y->right;
y->right=z;

//implement height changes???
z->height=1+max(heightOrNeg1(z->left),heightOrNeg1(z->right));
y->height=1+max(heightOrNeg1(y->left),heightOrNeg1(y->right));
t=y;

/*Node *y=t->left;
t->left=y->right;
y->right=t;
t=y;
y->height=1+max(heightOrNeg1(y->left),heightOrNeg1(y->right));
t->height=1+max(heightOrNeg1(t->left),heightOrNeg1(t->right));*/

}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
    //functionCalls.push_back("rotateLeftRight");
    // your code here
rotateRight(t->right);
rotateLeft(t);
}

template <class K, class V>
void AVLTree<K, V>::rebalance(Node*& subtree)
{
    // your code here
Node *left=subtree->left;
Node *right=subtree->right;
if(heightOrNeg1(right)-heightOrNeg1(left)<=1 && heightOrNeg1(right)-heightOrNeg1(left)>=-1)return ;//balanced
int hr=heightOrNeg1(right);
int hl=heightOrNeg1(left);
if(hr>hl){//first rotation is left?
//can't be null because then it couldn't be bigger
	if(heightOrNeg1(right->right)>=heightOrNeg1(right->left)){
		rotateLeft(subtree);
	}
	else rotateRightLeft(subtree);
}
else{//left is bigger height
	if(heightOrNeg1(left->left)>=heightOrNeg1(left->right)){
		rotateRight(subtree);
	}
	else rotateLeftRight(subtree);
}
return;
}

template <class K, class V>
void AVLTree<K, V>::insert(const K & key, const V & value)
{
    insert(root, key, value);
}

template <class K, class V>
void AVLTree<K, V>::insert(Node*& subtree, const K& key, const V& value)
{
/*vector<K> inorder=getInorderTraversal(const subtree);
  for (vector<K>::iterator it = inorder.begin() ; it != inorder.end(); ++it)

}*/
    // your code here
//idk if i need to redo find but i'm gonna do it anyways
//do we not need const for the parameters?
	if(subtree==NULL){
Node * insertNode=new Node(key, value);
	subtree=insertNode;
	//return;
	}

	else if(key==subtree->key){
	return; //duplicated
	}
	if(key<subtree->key){

	insert(subtree->left, key, value);
//subtree->height=1+max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right)); 
//now time to rebalance and rotate???
rebalance(subtree);

	}
	if(key>subtree->key){
	insert(subtree->right, key, value);
//subtree->height=1+max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right)); 
//now time to rebalance and rotate???
rebalance(subtree);

	}
//insertNode->height=1+max(heightOrNeg1(insertNode->left),heightOrNeg1(insertNode->right)); //update height ORRRR
/*subtree->height=1+max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right)); 
//now time to rebalance and rotate???
rebalance(subtree);
*/
subtree->height=1+max(heightOrNeg1(subtree->left),heightOrNeg1(subtree->right));
return;
}

template <class K, class V>
void AVLTree<K, V>::remove(const K& key)
{
    remove(root, key);
}

template <class K, class V>
void AVLTree<K, V>::remove(Node*& subtree, const K& key)
{
    if (subtree == NULL)
        return;

    if (key < subtree->key) {
        // your code here
	remove(subtree->left,key);
	rebalance(subtree);
    } else if (key > subtree->key) {
        // your code here
	remove(subtree->right,key);
	rebalance(subtree);
    } else {//key=subtree
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
subtree=NULL;
delete subtree;
//update heights????????
return;
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
//smallest in the right hand side
		Node *IOP= subtree->left;
		while(IOP->right!=NULL){//IOP->height=IOP->height -1;
IOP=IOP->right;
}
		//copy key & data, delete node
		swap(IOP,subtree);
		remove(subtree->left,key);
        } else {
            /* one-child remove */
            // your code here
if(subtree->left!=NULL){
subtree=subtree->left;
}
if(subtree->right!=NULL){//subtree=subtree->right;
subtree=subtree->right;
		}
        }
        // your code here
subtree->height=1+max(heightOrNeg1(subtree->right),heightOrNeg1(subtree->left));
rebalance(subtree);
    }


}
