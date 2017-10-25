
#include <iterator>
#include <cmath>
#include <list>
#include <queue>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */
start_=new Point(start.x,start.y);
png_=&png;
tolerance_=tolerance;
BFSqueue.push(start_);
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
//  return ImageTraversal::Iterator();
  return ImageTraversal::Iterator(start_,this);//start
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
 Point * end=NULL;
 
  return ImageTraversal::Iterator(end,this);//end
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */
/*Point * right;//x+1
Point * below;//y+1
Point * left;//x-1
Point * above;//y-1*/
 
unsigned int x=point.x;
unsigned int y=point.y;
if(x<=png_->width()){
Point *right=new Point(x+1,y);
BFSqueue.push(right);
//check if already visited & tolerance
 
}
if(y<=png_->height()){
Point * below=new Point(x,y+1);
BFSqueue.push(below);
//check if already visited & tolerance
 
}
if(1<=x){
Point * left=new Point(x-1,y);
BFSqueue.push(left);
//check if already visited & tolerance
 
}
if(1<=y){
Point * above=new Point(x,y-1);
BFSqueue.push(above);
//check if already visited & tolerance
 
}
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
Point * popped=BFSqueue.front();
BFSqueue.pop();
return *popped;
}

/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
Point * popped=BFSqueue.front();
return *popped;
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  return BFSqueue.empty();
}
