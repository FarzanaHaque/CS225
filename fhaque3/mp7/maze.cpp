#include <vector>
#include "dsets.h"
#include "maze.h"
SquareMaze::SquareMaze(){}
void SquareMaze::makeMaze (int width,int height) {
	width=width;
	height=height;
	int sets=width*height;
	int last=width*height-1;
	forest.myarray.clear();
	forest.addelements(width*height);
//	int square=0;
	//walls=null;//= new vector <vector <int>>;
	walls={};
	/*for(int j=0;j<walls.size();j++){
		delete walls[j];
	}*/
	for(int i=0;i<width*height;i++){
		//vector<int> temp {1,1};
		//temp.push_back(1);
		//temp.push_back(1);
		walls.push_back({1,1});
	}
	while(sets!=1){
		int square=rand()%(width*height);
		int dir=rand()%2;//0 means right, 1 means down
		if(walls[square][dir]==0) dir=1-dir;//that wall was already removed, try other one
		///if(walls[square][dir]==0) {} //both walls were already removed
		if(walls[square][dir]==1){//remove this wall
			if(dir==0&&(square%width!=width-1)){//right and not a right sided square
				if(forest.find(square)!=forest.find(square+1)){
					forest.myarray[square+1]=square;
					//forest.setunion(square,square+1);
					walls[square][dir]=0;
					sets--;
				}
			}
			if(dir==1&&(square<width*(height-1))){//bottom and not a bottom sided square
				if(forest.find(square)!=forest.find(square+width)){
					forest.myarray[square+width]=square;
					//forest.setunion(square,square+width);
					walls[square][dir]=0;
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
if(x<0||x>=width||y<0||y>=height) return false;
if(dir==0&&x!=(width-1)&&walls[x+y*width][0]==0) return true;
if(dir==1&&y!=(height-1)&&walls[x+y*width[1]==0) return true;
if(dir==2&&x!=0){if(walls[x+y*width-1][0]=0) return true;}
if(dir==3&&y!=0){if(walls[x+(y-1)*width-1][1]=0) return true;}
return false;
}
void SquareMaze::setWall (int x, int y, int dir, bool exists){
//0 right, 1 down
if(x<0||x>=width||y<0||y>=height) return;
	if(dir==0&&x!=(width-1)){
		if(bool)walls[x+y*width][0]=1;
		else walls[x+y*width][0]=0;
	}
	if(dir==1&&y!=(height-1){
		if(bool)walls[x+y*width][1]=1;
		else walls[x+y*width][1]=0;
	} 
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
