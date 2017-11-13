
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    /// @todo Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the left child.
    return 2*currentIdx;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the right child.
    return 2*currentIdx +1;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    /// @todo Update to return the index of the parent.
    return currentIdx/2;
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    /// @todo Update to return whether the given node has a child
if(currentIdx*2>=_elems.size())    
	return false;
else return true;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    /// @todo Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
   
size_t left= currentIdx*2;
size_t right=currentIdx*2+1;
if(higherPriority(_elems[left],_elems[right])) return left;
else return right;
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    /// @todo Implement the heapifyDown algorithm.
if(!hasAChild(currentIdx)) return;
size_t left=leftChild(currentIdx);
size_t right=rightChild(currentIdx);
size_t small;
if(higherPriority(_elems[left],_elems[right])) small=left;
else small=right;
if(higherPriority(_elems[small],_elems[currentIdx])){
        std::swap(_elems[small], _elems[currentIdx]);
        heapifyDown(small);
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx], _elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    /// @todo Depending on your implementation, this function may or may
    ///   not need modifying
_elems.push_back(T());

}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    /// @todo Construct a heap using the buildHeap algorithm
_elems.push_back(T());
for(size_t i=0;i<elems.size();i++){
_elems.push_back(elems[i]);
	}
for(size_t j=_elems.size()-1;j>0;j--)
	{
	heapifyDown(j);
	}
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    /// @todo Remove, and return, the element with highest priority
    return T();
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    /// @todo Return, but do not remove, the element with highest priority
  return _elems[1];  
/*return T();rst parameter has a higher priority than the second.

Compare is a template parameter and defaults to std::less, which creates a min-heap. So, if T = int and a = 3 and b = 5, higherPriority(a, b) = true (a < b, so a has higher priority) and higherPriority(b, a) = false (b > a, so b has lower priority) */
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    /// @todo Add elem to the heap
_elems.push_back(elem);
heapifyUp(_elems.size()-1);
}

template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    /// @todo Determine if the heap is empty
if(_elems.size()<=1) return true;
else return false;
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
