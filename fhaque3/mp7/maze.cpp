#include <vector>
#include "dsets.h"
#include "maze.h"
SquareMaze::SquareMaze(){}
void SquareMaze::makeMaze (int width,int height) {
	int last=width*height-1;
	forest.myarray.clear();
	forest.addelements(width*height);
	int square=0;
	for(int i=0;i<width*heigh;i++){
		neighbors[i]=new vector<int>;
		if(i-1>=0){
		neighbors[i].push(i-1);
		}
		if(i-width>=0) neighbors[i].push(i-row);
		if(i+1<width*height) neighbors[i].push(i+1);
		if(i+widht<width*height) neighbors[i].push(i+width);

	}




}

bool SquareMaze::canTravel (int x, int y, int dir) const {
return true;
}
void SquareMaze::setWall (int x, int y, int dir, bool exists){
}

vector< int > SquareMaze::solveMaze (){
return vector<int>();
}
 
PNG * SquareMaze::drawMaze () const{
//PNG fake=PNG();
PNG *faker=NULL;//= & PNG();
return faker;
}

 
PNG * SquareMaze::drawMazeWithSolution (){
//PNG fake=PNG();
PNG *faker=NULL;//= & PNG();
return faker;
}
