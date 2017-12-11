#include "Exam.h"
#include "LNode.h"
#include <iostream>

using namespace std;

void populate(Node **arr, int n) {
	for(int i=0;i<n;i++){
		LNode * tempnode=new LNode;
		arr[i]=tempnode;
	}
}

void lookNext(Node **arr, int n) {
	for(int i=0;i<n-1;i++){
		/*LNode *older=arr[i];
		LNode *newer=older->getLookingAt();
		older->setLookingAt(newer->getLookingAt());*/
		LNode *older=new LNode;
		LNode *newer=new LNode;
		//LNode *newest=new LNode;
		/*older=arr[i];
		newer=arr[i+1];
		older->setLookingAt(newer);*/
		//older->setLookingAt((arr[i]->getLookingAt())->getLookingAt());
		
		
}
arr[n]=NULL;
}

void display(Node **arr, int n) {
    Node *x;
    for(int i=0; i<n; i++) {
        x = arr[i]->getLookingAt();
        if (x)
            cout << "Node " << arr[i] << " is looking at " << x << "." << endl;
        else
            cout << "Node " << arr[i] << " is looking at NULL." << endl;
    }
}
