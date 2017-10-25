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
//Iterator begin()= start;
 
 
//HSLAPixel * startpix=png.getPixel(start.x,start.y);
start_=new Point(start.x,start.y);
png_=&png;
tolerance_=tolerance;
/*for(unsigned int i=0;i<png_.width();i++){
    for(unsigned int j=0;j<png_height();j++){
        visited
        }
}*/
/////////////////////////////////////////visited.resize(png.width(), vector<bool>( png.height() , false ) );
DFSstack.push(start_);
}
 
/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator DFS::begin() {
  /** @todo [Part 1] */
 
//Point *fake=new Point(43,2);
 
 
  return ImageTraversal::Iterator(start_,this);//start_
}
 
/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator DFS::end() {
  /** @todo [Part 1] */
 
Point * end=NULL;
 
  return ImageTraversal::Iterator(end,this);//end
}
 
/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void DFS::add(const Point & point) {
  /** @todo [Part 1] */
/*Point * right;//x+1
Point * below;//y+1
Point * left;//x-1
Point * above;//y-1*/
 
unsigned int x=point.x;
unsigned int y=point.y;
if(x<=png_->width()){
Point * right=new Point(x+1,y);
DFSstack.push(right);
//check if already visited & tolerance
 
}
if(y<=png_->height()){
Point * below=new Point(x,y+1);
DFSstack.push(below);
//check if already visited & tolerance
 
}
if(1<=x){
Point * left=new Point(x-1,y);
DFSstack.push(left);
//check if already visited & tolerance
 
}
if(1<=y){
Point * above=new Point(x,y-1);
DFSstack.push(above);
//check if already visited & tolerance
 
}
}
 
/**
 * Removes and returns the current Point in the traversal.
 */
Point DFS::pop() {
  /** @todo [Part 1] */
  //return Point(0, 0);
//Point  * popped;
 
 
Point * popped=DFSstack.top();
DFSstack.pop();
return *popped;
}
 
/**
 * Returns the current Point in the traversal.
 */
Point DFS::peek() const {
  /** @todo [Part 1] */
Point * peaked=DFSstack.top();
 
return *peaked;
}
 
/**
 * Returns true if the traversal is empty.
 */
bool DFS::empty() const {
  /** @todo [Part 1] */
  return DFSstack.empty();
}

