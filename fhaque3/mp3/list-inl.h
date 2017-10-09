/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
#include <algorithm> 
template <class T>
List<T>::~List() {
  /// @todo Graded in MP3.1

clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear() {
  /// @todo Graded in MP3.1
        ListNode* curr = head_;
if(head_==NULL){delete[]head_; 
head_=NULL;
delete[]tail_;
tail_=NULL;
return;}
while(curr->next!=NULL){
curr=curr->next;
delete[] curr->prev;
curr->prev=NULL;
}
delete[] tail_;
tail_=NULL;
length_++;
}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata) {
  /// @todo Graded in MP3.1

ListNode * newnode=new ListNode(ndata);
//std::cout<<newnode<<std::endl;
//std::cout<<head_<<std::endl;
if(head_==NULL & tail_==NULL){
/*head_->next=tail_;
tail_->prev=head_;
head_->prev=NULL;*/
head_=newnode;
tail_=newnode;
length_++;
}
else{
newnode->next=head_;
head_=newnode;
head_->prev=NULL;
head_->next->prev=head_;
length_++;}
}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata) {

  /// @todo Graded in MP3.1
/*if(head_->next==NULL){head_->next=tail_;
tail_->prev=head_;
head_->prev=NULL;
tail_->next=NULL;}*/
ListNode * newnode=new ListNode(ndata);
if(head_==NULL & tail_==NULL){
/*head_->next=tail_;
tail_->prev=head_;
head_->prev=NULL;*/
head_=newnode;
tail_=newnode;
length_++;
}
else{
tail_->next=newnode;
newnode->prev=tail_;
tail_=newnode;
tail_->next=NULL;
length_++;
}
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode*& startPoint, ListNode*& endPoint) {
    /// @todo Graded in MP3.1
ListNode *endnext=endPoint->next;
if(startPoint==NULL || endPoint==NULL){return;}
if(startPoint==endPoint){
ListNode *oldprev=startPoint->prev;
ListNode *oldnext=startPoint->next;
startPoint->next=oldprev;
startPoint->prev=oldnext;
return;
}
ListNode *curr=startPoint;
while(curr!=endnext &&curr!=NULL){
ListNode *oldprev=curr->prev;
ListNode *oldnext=curr->next;
curr->next=oldprev;
curr->prev=oldnext;
curr=oldnext;
}



ListNode *oldend=endPoint;
ListNode *oldstart=startPoint;
startPoint=oldend;
endPoint=oldstart;
ListNode*beg=endPoint->next;
ListNode*end=startPoint->prev;
endPoint->next=end;
startPoint->prev=beg;

if(beg!=NULL)
beg->next=startPoint;
if(end!=NULL)
end->prev=endPoint;


//ListNode*enext=endPoint->next;
//ListNode*sprev=startPoint->prev;
//endPoint->next=oldend->next;
//startPoint->prev=oldstart->prev;
/*if(oldend->next!=NULL)oldend->next->prev=endPoint;

if(oldstart->prev!=NULL)oldstart->prev->next=startPoint;
*/
return;
}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.1
if(length_<=n){reverse();}
int l=length_;
ListNode *currold=head_;
ListNode *curr=head_;
//int elements=0;
//while(curr!=NULL){
/*if(n<l)elements=n;
else elements=l;*/

for(int i=0;i<n;i++){
curr=curr->next;
}
reverse(head_,curr);
currold=curr;
l=l-n;
while(l>=n){
for(int i=0;i<n;i++){
curr=curr->next;
}
reverse(currold,curr);
currold=curr;
l=l-n;
}




/*int elements=min(n,l);
ListNode *start=head_ ;
ListNode *end=head_ ; 
while(l>n){


for(int i=0;i<n;i++){
end=end->next;
}

reverse(start,end);*/
/*l=l-n;
end=end->next;
start=end;*/
//}

/*if(l<=n){
for(int i=0;i<l;i++){
end=end->next;
}

reverse(start,end);

}*/
return;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall() {
  /// @todo Graded in MP3.1
ListNode *curr=head_;
while(curr!=tail_||curr!=NULL){
	int i=0;
	if(i%2==1){
		curr=curr->next;			
	}
	if(i%2==0){
		curr->prev=curr->next;
		curr->next=curr->prev;
		insertBack(curr->data);
		curr=curr->next;
	}
	i++;
}

}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint) {
    if (splitPoint > length_)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head_, splitPoint);

    int oldLength = length_;
    if (secondHead == head_) {
        // current list is going to be empty
        head_ = NULL;
        tail_ = NULL;
        length_ = 0;
    } else {
        // set up current list
        tail_ = head_;
        while (tail_->next != NULL)
            tail_ = tail_->next;
        length_ = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head_ = secondHead;
    ret.tail_ = secondHead;
    if (ret.tail_ != NULL) {
        while (ret.tail_->next != NULL)
            ret.tail_ = ret.tail_->next;
    }
    ret.length_ = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint) {
    /// @todo Graded in MP3.2
    return NULL;
}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second) {
  /// @todo Graded in MP3.2
  return NULL;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort() {
    if (empty())
        return;
    head_ = mergesort(head_, length_);
    tail_ = head_;
    while (tail_->next != NULL)
        tail_ = tail_->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength) {
    /// @todo Graded in MP3.2
    return NULL;
}
