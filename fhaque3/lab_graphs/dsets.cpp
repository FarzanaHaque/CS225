/* Your code here! */
#include <vector>
#include "dsets.h"
void DisjointSets::addelements (int num){
        for(int i=0;i<num;i++){
                myarray.push_back(-1);
        }
}

int DisjointSets::find (int elem) {
        if(myarray[elem]<0) return elem;
        else {return find(myarray[elem]);}
}

void DisjointSets::setunion(int a, int b){
        int root1=find(a);
        int root2=find(b);
        int newsize=myarray[root1]+myarray[root2];
        if(myarray[root1]<myarray[root2]){
                myarray[root2]=root1;
                myarray[root1]=newsize;
        }
        else{
                myarray[root1]=root2;
                myarray[root2]=newsize;
        }
}

int DisjointSets::size(int elem) {
        if(myarray[elem]<0) return -1*myarray[elem];
        else return 1;
}




