#ifndef _MAZE_H_
#define _MAZE_H_

#include<vector>
#include<algorithm>
#include <iostream>
#include "cs225/PNG.h"
using cs225::PNG;
class SquareMaze {
	public:
	SquareMaze();
	void makeMaze (int width,int height);
	bool canTravel (int x, int y, int dir) const;
	void setWall (int x, int y, int dir, bool exists);
	std::vector< int > solveMaze ();
	 
	PNG * drawMaze () const;

	 
	PNG * drawMazeWithSolution ();
	vector<vector<int>> walls;
	int width_;
	int height_;
	//vector <bool> visited;
	//vector<int> solution;
	//unordered_map<int,int> ns; //newsquare
	//std::unordered_map<vertex,vector<int>> neighbors;
	//vector <int> dist;
	int end;
	private:
	DisjointSets forest;
	//PNG * mypng;
	//Graph g_;
	//Vertex startingVertex_;


};
//#include "maze.cpp"
#endif


