#ifndef LNODE_H
#define LNODE_H

#include <string>
#include "Node.h"
using namespace std;

class LNode: public Node {
    private:
        //string name_;
        //Node *lookingAt_;
    public:
        /*Node();
        virtual ~Node();
        void setName(string s);
        string getName();
        Node *getLookingAt();
        void setLookingAt(Node *);
        virtual void lookAtMeEven(Node **arr, int n) = 0;*/
	~LNode();
        void lookAtMeEven(Node **arr,int n);

};

#endif
