#include <string>
#include "LNode.h"
#include "Node.h"
using namespace std;

/*Node::Node() {
    lookingAt_ = NULL;
    name_ = "";
}

Node::~Node() { }

void Node::setName(string s) {
    name_ = s;
}

string Node::getName() {
    return name_;
}

Node *Node::getLookingAt() {
    return lookingAt_;
}

void Node::setLookingAt(Node *n) {
    lookingAt_ = n;
}*/
LNode::~LNode() { }
void LNode::lookAtMeEven(Node **arr,int n){
for(int i=0;i<n;i++){
if(i%2==0){
//LNode *z=arr[i];
arr[i]->setLookingAt(this);
}
}

}

