#include <iterator>
#include <cmath>
#include <list>
#include <stack>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "DFS.h"


//we want to pop the most recently added, aka stack, std::stack

/**
 * Initializes a depth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 */
DFS::DFS(const PNG & png, const Point & start, double tolerance) {  
  /** @todo [Part 1] */
/*Point * right;//x+1
Point * below;//y+1
Point * left;//x-1
Point * above;//y-1*/
int x=start->x;
int y=start->y;
if(x<=width){
Point * right=new Point(x+1,y);
DFSstack.push(right);
//check if already visited & tolerance

}
if(y<=height){
Point * below=new Point(x,y+1);
DFSstack.push(below);
//check if already visited & tolerance

}
if(0<=x-1){
Point * left=new Point(x-1,y);
DFSstack.push(left);
//check if already visited & tolerance

}
if(0<=y-1){
Point * above=new Point(x,y-1);
DFSstack.push(above);
//check if already visited & tolerance

}
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
}

/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  return Point(0, 0);
}

/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
  return Point(0, 0);
}

/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return true;
}
