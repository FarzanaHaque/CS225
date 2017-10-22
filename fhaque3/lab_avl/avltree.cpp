/**
 * @file avltree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */

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
    // your code here
if(t==NULL) return;
if(t->right==NULL) return;
//if(t->right->right==NULL) return;
Node * z=t;
Node *y= t->right;
Node *x=y->right;
z->right=y->left;
y->left=z;
y->right=x;
t=y;
z->height=1+max(heightOrNeg1(z->left)+heightOrNeg1(z->right));
y->height=1+max(heightOrNeg1(y->left)+heightOrNeg1(y->right));
}

template <class K, class V>
void AVLTree<K, V>::rotateLeftRight(Node*& t)
{
    functionCalls.push_back("rotateLeftRight"); // Stores the rotation name (don't remove this)
    // Implemented for you:
    rotateLeft(t->left);
    rotateRight(t);
}

template <class K, class V>
void AVLTree<K, V>::rotateRight(Node*& t)
{
    functionCalls.push_back("rotateRight"); // Stores the rotation name (don't remove this)
    // your code here
if(t==NULL) return;
if(t->left==NULL)return;
//if(t->left->left==NULL) return;
Node *z=t;
Node *y=t->left;
Node *x=y->left;
z->left=y->right;
y->right=z;
t=y;
//implement height changes???
z->height=1+max(heightOrNeg1(z->left)+heightOrNeg1(z->right));
y->height=1+max(heightOrNeg1(y->left)+heightOrNeg1(y->right));


}

template <class K, class V>
void AVLTree<K, V>::rotateRightLeft(Node*& t)
{
    functionCalls.push_back("rotateRightLeft"); // Stores the rotation name (don't remove this)
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
if(height(right)-height(left)<=1 && height(right)-height(left)>=-1)return height(subtree);//balanced
int hr=height(right);
int hl=height(left);
if(hr>hl){//first rotation is left?
//can't be null because then it couldn't be bigger
	if(height(right->right)>=height(right->left)){
		rotateLeft(subtree);
	}
	else rotateLeftRight(subtree);
}
else{//left is bigger height
	if(height(left->left)>=height(left->right)){
		rotateRight(subtree);
	}
	else rotateRightLeft(subtree);
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
    // your code here
//idk if i need to redo find but i'm gonna do it anyways
Node *insertNode=Node(key, value);//do we not need const for the parameters?
	if(subtree==NULL){
	subtree=insertNode;
	return;
	}
/*vector<K> inorder=getInorderTraversal(const subtree);
  for (vector<K>::iterator it = inorder.begin() ; it != inorder.end(); ++it)

}*/

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
    } else if (key > subtree->key) {
        // your code here
    } else {
        if (subtree->left == NULL && subtree->right == NULL) {
            /* no-child remove */
            // your code here
        } else if (subtree->left != NULL && subtree->right != NULL) {
            /* two-child remove */
            // your code here
        } else {
            /* one-child remove */
            // your code here
        }
        // your code here
    }
}
