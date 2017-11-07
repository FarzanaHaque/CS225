/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
//#include <algorithm>
template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */

double firstD=first[curDim];//(curDim);
double secondD=second[curDim];//(curDim);
if(firstD<secondD) return true;
if(secondD<firstD) return false;
else
if(first<second) return true;






    return false;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
//return true;
double pd=0;
double cbd=0;;

	for(int i=0;i<Dim;i++)
	{
	pd=pd+((potential[i]-target[i])*(potential[i]-target[i]));
	cbd=cbd+((target[i]-currentBest[i])*(target[i]-currentBest[i]));
	}

if(pd<cbd) return true;
else if(cbd<pd) return false;
else if(potential < currentBest) return true;
else return false;



}

/* function partition(list, left, right, pivotIndex)
     pivotValue := list[pivotIndex]
     swap list[pivotIndex] and list[right]  // Move pivot to end
     storeIndex := left
     for i from left to right-1
         if list[i] < pivotValue
             swap list[storeIndex] and list[i]
             increment storeIndex
     swap list[right] and list[storeIndex]  // Move pivot to its final place
     return storeIndex*/


template <int Dim>
int KDTree<Dim>::partition(int left, int right, int pivotIndex, int dim)// do we need need specific dimension as an input???? then we'd call smaller DimValue
{
	Point<Dim>  pivotValue = points[pivotIndex];
	//swap(&list[pivotIndex],&list[right]); // are the contents of the list points or pointers to points? I think first but does then do you have to put in & to properly swap?
	Point<Dim> rightp=points[right];
	points[pivotIndex]= rightp;
	points[right]=pivotValue;
	int storeIndex=left;
	for(int i=left;i<right;i++)
	{
		if(smallerDimVal(points[i],pivotValue, dim))//|| points[i] == pivotValue
		{
			Point<Dim> sI=points[storeIndex];
			Point<Dim> pointsI=points[i];
			points[i]=sI;
			points[storeIndex]=pointsI;
			storeIndex++;
		}
	}
	
	Point<Dim> rightp2=points[right];
	Point<Dim> sI2=points[storeIndex];
	points[right]=sI2;
	points[storeIndex]=rightp2;
	return storeIndex;	
///prob need to test :/
}

/*  function select(list, left, right, k)
     if left = right        // If the list contains only one element,
         return list[left]  // return that element
     pivotIndex  := ...     // select a pivotIndex between left and right,
                            // e.g., left + floor(rand() % (right - left + 1))
     pivotIndex  := partition(list, left, right, pivotIndex)
     // The pivot is in its final sorted position
     if k = pivotIndex
         return list[k]
     else if k < pivotIndex
         return select(list, left, pivotIndex - 1, k)
     else
         return select(list, pivotIndex + 1, right, k)
*/

template <int Dim>
void KDTree<Dim>::select(int left, int right, int k, int dim)// do we need need specific dimension as an input???? then we'd call smaller DimValue
{
if(left==right) return ;
int pivotIndex=partition(left,right,k,dim);
if(k==pivotIndex) return;
else if(k<pivotIndex) return select(left,pivotIndex-1,k,dim);
else return select(pivotIndex +1, right,k,dim);

}

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
points=newPoints;
if (newPoints.empty()) return;
int size=newPoints.size()-1;
KDhelper(0,size,0);
}
template <int Dim>
void KDTree<Dim>::KDhelper(int a,int b,int d)
{
if(a==b) return;
int medium= (a+b)/2; /// since it's int division, don't care about floor right?
select(a,b,medium,d);
//Recurse on the indices between a though m−1, and m+1 through b using splitting dimension (d+1)modk.
if(a<medium)KDhelper(a,medium-1,(d+1)%(Dim));
if(medium<b)KDhelper(medium+1,b,(d+1)%(Dim));
}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
	Point <Dim> middle=points[(points.size()-1)/2];//top node, curr best guess
	Point<Dim> neighbor= NNhelper(0,points.size()-1,0,query,middle);
	return neighbor;
}
template <int Dim>
Point<Dim> KDTree<Dim>::NNhelper(int left,int right,int d,const Point <Dim> & query, const Point <Dim> & currentBest) const// why this const???
{
// need to make sure left & right alwyays stay within bounds
	if(currentBest==query) return currentBest; //exact match
	if(left==right)//leaf node
	{
		if(shouldReplace(query,currentBest,points[left]) )return points[left];
		else return currentBest;
	}
//now not a leaf, go to target how to deal 1 child null???????
	Point<Dim> best=currentBest;
	Point<Dim> target;
	int medium=(left+right)/2;
	bool ltree=false;
	bool rtree=false;
	if(smallerDimVal(query,currentBest,d)&&medium-1>=left) //target in left
	{
		target=NNhelper(left,medium-1,(d+1)%Dim,query,currentBest);
		ltree=true;
	        if(shouldReplace(query,currentBest,target)) best=target;
	} 
//target in right
	else if(smallerDimVal(currentBest,query,d)&&(medium+1)<=right)
	{
		target=NNhelper(medium+1,right,(d+1)%Dim,query,currentBest);
		rtree=true;
	        if(shouldReplace(query,currentBest,target)) best=target;
	}
if(shouldReplace(query,best,points[medium])) best=points[medium];//checks current node

//compare target with current best
//is the current already checked??????
//now check cutting plane stuff
	double bestd=0;
	for(int i=0;i<Dim;i++)
	{
		bestd=bestd+((query[i]-best[i])*(query[i]-best[i]));
	}

	double cutd=((query[d]-currentBest[d])*(query[d]-currentBest[d]));
	Point<Dim> Otree=best;
	if(cutd<=bestd)
	{//check other subtree that's not target
		if(ltree&&(medium+1)<=right)Otree=NNhelper(medium+1,right,(d+1)%Dim,query,best);
		else if(rtree&&medium-1>=left)Otree=NNhelper(left,medium-1,(d+1)%Dim,query,best);
		if(shouldReplace(query,best,Otree))best=Otree;
	}	
	return best;
}



/* returns found tree
Point<Dim> KDTree<Dim>::NNhelper(int left,int right,int d,const Point <Dim> & query, const Point <Dim> & currentBest) const// why this const???
{
//int middle=(left+right)/2;
Point <Dim> best=currentBest;
int dim=d;
Point <Dim> foundtree=currentBest;
int fakel=left;
int faker=right;
while(fakel<faker)//not leaf node
{
int fmedium=(fakel+faker)/2;
	if(smallerDimVal(query,foundtree,(dim+1)%Dim))
	{
		//go to left subtree
	faker=fmedium-1;
	fmedium=(fakel+faker)/2;
	foundtree=points[fmedium];

	}
	else if(smallerDimVal(foundtree,query,(dim+1)%Dim))
	{
		//go to right subtree
	fakel=fmedium+1;
	fmedium=(fakel+faker)/2;
	foundtree=points[fmedium];
	}	
if(foundtree==query)return foundtree;
if(shouldReplace(query,best,foundtree))best=foundtree;
}
//return foundtree;/// should just be the slice that would contain it

}
*/


