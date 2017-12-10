#include <vector>
#include "dsets.h"
#include "maze.h"
SquareMaze::SquareMaze(){}
void SquareMaze::makeMaze (int width,int height) {
	width_=width;
	height_=height;
	int sets=width*height;
	int last=width*height-1;
	forest.myarray.clear();
	forest.addelements(width*height);
//	int square=0;
	walls= vector <vector <int>>();
	//walls={};
	/*for(int j=0;j<walls.size();j++){
		delete walls[j];
	}*/
	visited=vector<int>();
	for(int i=0;i<width*height;i++){///wouldn't it be faster to do a O(1) intialization dude??
		vector<int> temp {1,1};
		temp.push_back(1);
		temp.push_back(1);
		walls.push_back(temp);
		visited.push_back(false);
		dist.push_back(-inf);
	}
	while(sets!=1){
		int square=rand()%(width*height);
		int dir=rand()%2;//0 means right, 1 means down
		if(walls[square][dir]==0) dir=1-dir;//that wall was already removed, try other one
		///if(walls[square][dir]==0) {} //both walls were already removed
		if(walls[square][dir]==1){//remove this wall
			if(dir==0&&(square%width!=width-1)){//right and not a right sided square
				if(forest.find(square)!=forest.find(square+1)){
					//forest.myarray[square+1]=square;
					forest.setunion(square,square+1);
					walls[square][dir]=0;//no wall here
					sets--;
				}
			}
			if(dir==1&&(square<width*(height-1))){//bottom and not a bottom sided square
				if(forest.find(square)!=forest.find(square+width)){
					//forest.myarray[square+width]=square;
					forest.setunion(square,square+width);
					walls[square][dir]=0;//no wall here
					sets--;
				}
			}
		}
	}

/*	for(int i=0;i<width*heigh;i++){
		neighbors[i]=new vector<int>;
		if(i-1>=0){
		neighbors[i].push(i-1);
		}
		if(i-width>=0) neighbors[i].push(i-row);
		if(i+1<width*height) neighbors[i].push(i+1);
		if(i+widht<width*height) neighbors[i].push(i+width);

	}

	queue <int> q;
	q.push(square);
	//graph.setVertexLabel
	while(!q.empty()){
		int s=q.front();
		q.pop();
		vector <int> nv= neighbors[s];
		int j=rand()%(nv.size());	
		//for(size_t j=0;j<nv.size();j++){
		int others=nv[j];
		in
		if(forest.find(s)==forest.find(others)){
			
		}
			if(graph.getVertexLabel(w)=="UNEXPLORED"){
				//graph.setEdgeLabel(v,w,"DISCOVERY");
				graph.setVertexLabel(w,"VISITED");
				q.push(w);
				Edge thisedge=graph.getEdge(v,w);
				m[w]=v;
			}

	
		//}

	}

*/
}

bool SquareMaze::canTravel (int x, int y, int dir) const {
/*
    dir = 0 represents a rightward step (+1 to the x coordinate)
    dir = 1 represents a downward step (+1 to the y coordinate)
    dir = 2 represents a leftward step (-1 to the x coordinate)
    dir = 3 represents an upward step (-1 to the y coordinate)
*///cant't go off or go through wall
if(x<0||x>=width_||y<0||y>=height_) return false;
if(dir==0&&x!=(width_-1)&&walls[x+y*width_][0]==0) return true;
if(dir==1&&y!=(height_-1)&&walls[x+y*width_][1]==0) return true;
if(dir==2&&x!=0){if(walls[x+y*width_-1][0]==0) return true;}
if(dir==3&&y!=0){if(walls[x+(y-1)*width_][1]==0) return true;}
return false;
}
void SquareMaze::setWall (int x, int y, int dir, bool exists){
//0 right, 1 down
	if(x<0||x>=width_||y<0||y>=height_) return;
	if(dir==0&&x!=(width_-1)){
		if(exists)walls[x+y*width_][0]=1;
		else walls[x+y*width_][0]=0;
	}
	if(dir==1&&y!=(height_-1)){
		if(exists)walls[x+y*width_][1]=1;
		else walls[x+y*width_][1]=0;
	} 
}

vector< int > SquareMaze::solveMaze (){


/*Solves this SquareMaze.

For each square on the bottom row (maximum y coordinate), there is a distance from the origin (i.e. the top-left cell), which is defined as the length (measured as a number of steps) of the only path through the maze from the origin to that square.

Select the square in the bottom row with the largest distance from the origin as the destination of the maze. solveMaze() returns the winning path from the origin to the destination as a vector of integers, where each integer represents the direction of a step, using the same encoding as in canTravel().

If multiple paths of maximum length exist, use the one with the destination cell that has the smallest x value.

Hint: this function should run in time linear in the number of cells in the maze.

Returns
    a vector of directions taken to solve the maze */

	vector<int> ret= vector<int>();
	int dest=width_*(height_-1); //the leftest square on bottom row
	int curr=0;
	queue <int> q;
	q.push(curr);
	vector<int> temp=vector<int>();
	while(q!=empty){
	
		//manhattan heuristic???
		/*
		function heuristic(node) =
		    dx = abs(node.x - goal.x)
		    dy = abs(node.y - goal.y)
		    return D * (dx + dy)
		*/
		curr=q.front();
		q.pop();
		if(!visited[curr]){
			
		}	
	}
	return ret;
}


/*
void GraphTools::findMST(Graph& graph)
{
vector<Vertex> vertices = graph.getVertices();
	DisjointSets vertexSet;
	vertexSet.addelements(vertices.size());
	vector<Edge> edges = graph.getEdges();
	std::sort(edges.begin(), edges.end());
	for(unsigned i = 0; i < edges.size(); i++)	{
		Vertex a = edges[i].source;
		Vertex b = edges[i].dest;
		if(vertexSet.find(a) != vertexSet.find(b))	{
			vertexSet.setunion(a, b);
			graph.setEdgeLabel(a, b, "MST");
		}
	}
} 
*/

 
PNG * SquareMaze::drawMaze () const{


/*Draws the maze without the solution.

First, create a new PNG. Set the dimensions of the PNG to (width*10+1,height*10+1). where height and width were the arguments to makeMaze. Blacken the entire topmost row and leftmost column of pixels, except the entrance (1,0) through (9,0). For each square in the maze, call its maze coordinates (x,y). If the right wall exists, then blacken the pixels with coordinates ((x+1)*10,y*10+k) for k from 0 to 10. If the bottom wall exists, then blacken the pixels with coordinates (x*10+k, (y+1)*10) for k from 0 to 10.

The resulting PNG will look like the sample image, except there will be no exit from the maze and the red line will be missing.

Returns
    a PNG of the unsolved SquareMaze 
*/
PNG * image=new PNG(width_*10+1,height_*10+1);
//for(

return image;





//PNG fake=PNG();
/*PNG *faker=NULL;//= & PNG();
return faker;*/
}

 
PNG * SquareMaze::drawMazeWithSolution (){
//PNG fake=PNG();
PNG *faker=NULL;//= & PNG();
return faker;
}
