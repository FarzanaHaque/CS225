#ifndef _MAZE_H_
#define _MAZE_H_

#include<vector>
#include<algorithm>
#include <iostream>

class SquareMaze {
	public:
	SquareMaze()
	void makeMaze (int width,int height) 
	bool canTravel (int x, int y, int dir) const 
	void setWall (int x, int y, int dir, bool exists)
	vector< int > solveMaze ()
	 
	PNG * drawMaze () const

	 
	PNG * drawMazeWithSolution ()


	private:

	//Graph g_;
	//Vertex startingVertex_;


};

#endif


