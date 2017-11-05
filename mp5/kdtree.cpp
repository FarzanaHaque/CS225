/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */
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

template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
}


template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
    return Point<Dim>();
}
