/**
 * @file graph_tools.cpp
 * This is where you will implement several functions that operate on graphs.
 * Be sure to thoroughly read the comments above each function, as they give
 *  hints and instructions on how to solve the problems.
 */

#include "graph_tools.h"

/**
 * Finds the minimum edge weight in the Graph graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @return the minimum weighted edge
 *
 * @todo Label the minimum edge as "MIN". It will appear blue when
 *  graph.savePNG() is called in minweight_test.
 *
 * @note You must do a traversal.
 * @note You may use the STL stack and queue.
 * @note You may assume the graph is connected.
 *
 * @hint Initially label vertices and edges as unvisited.
 */
int GraphTools::findMinWeight(Graph& graph)
{
    /* Your code here! */

vector <Vertex> allv= graph.getVertices();
vector<Edge> alledges= graph.getEdges();
//auto ite=alledges.start();
Edge minedge;
int minweight=-1;
//for(auto ite=alledges.start();it++;it!=alledge.start())
for(size_t i=0;i<alledges.size();i++)
{
	Edge temp=alledges[i];
	graph.setEdgeLabel(temp.source,temp.dest,"UNEXPLORED");
}

for(size_t i2=0;i2<allv.size();i2++){
	graph.setVertexLabel(allv[i2],"UNEXPLORED");
}

//vertex v= graph.GetStartingVertex;

queue <Vertex> q;
q.push(graph.getStartingVertex());
//graph.setVertexLabel
while(!q.empty()){
	Vertex v=q.front();
	q.pop();
	vector <Vertex> adjvector= graph.getAdjacent(v);	
	for(size_t j=0;j<adjvector.size();j++){
		Vertex w=adjvector[j];
		if(graph.getVertexLabel(w)=="UNEXPLORED"){
			graph.setEdgeLabel(v,w,"DISCOVERY");
			graph.setVertexLabel(w,"VISITED");
			q.push(w);
			Edge thisedge=graph.getEdge(v,w);
			if(minweight<0){//first edge visited
				minedge=thisedge;
				minweight=thisedge.weight;
				graph.setEdgeLabel(v,w,"MIN"); //set label only at end so we don't have undo the previous one each time?
				
			}
		
			else if(minweight>thisedge.weight){
				graph.setEdgeLabel(minedge.dest,minedge.source,"VISITED");
				graph.setEdgeLabel(v,w,"MIN");
				minweight=thisedge.weight;
				minedge=thisedge;
			}
		}
		else if (graph.getEdgeLabel(v,w)=="UNEXPLORED"){
			graph.setEdgeLabel(v,w,"CROSS");
			Edge thisedge=graph.getEdge(v,w);
			if(minweight<0){//first edge visited
				minedge=thisedge;
				minweight=thisedge.weight;
				graph.setEdgeLabel(v,w,"MIN"); //set label only at end so we don't have undo the previous one each time?
				
			}
		
			else if(minweight>thisedge.weight){
				graph.setEdgeLabel(minedge.dest,minedge.source,"VISITED");
				graph.setEdgeLabel(v,w,"MIN");
				minweight=thisedge.weight;
				minedge=thisedge;
			}
		}
	
	}

}
//graph.setEdgeLabel(minedge.dest,minedge.source,"MIN");
return minweight;
}

/**
 * Returns the shortest distance (in edges) between the Vertices
 *  start and end.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to search
 * @param start - the vertex to start the search from
 * @param end - the vertex to find a path to
 * @return the minimum number of edges between start and end
 *
 * @todo Label each edge "MINPATH" if it is part of the minimum path
 *
 * @note Remember this is the shortest path in terms of edges,
 *  not edge weights.
 * @note Again, you may use the STL stack and queue.
 * @note You may also use the STL's unordered_map, but it is possible
 *  to solve this problem without it.
 *
 * @hint In order to draw (and correctly count) the edges between two
 *  vertices, you'll have to remember each vertex's parent somehow.
 */
int GraphTools::findShortestPath(Graph& graph, Vertex start, Vertex end)
{
    /* Your code here! */


vector <Vertex> allv= graph.getVertices();
vector<Edge> alledges= graph.getEdges();
//auto ite=alledges.start();
//for(auto ite=alledges.start();it++;it!=alledge.start())
for(size_t i=0;i<alledges.size();i++)
{
	Edge temp=alledges[i];
	graph.setEdgeLabel(temp.source,temp.dest,"UNEXPLORED");
}

for(size_t i2=0;i2<allv.size();i2++){
	graph.setVertexLabel(allv[i2],"UNEXPLORED");
}


unordered_map <Vertex,Vertex> m;

queue <Vertex> q;
q.push(start);
//graph.setVertexLabel
while(!q.empty()){
	Vertex v=q.front();
	q.pop();
	vector <Vertex> adjvector= graph.getAdjacent(v);	
	for(size_t j=0;j<adjvector.size();j++){
		Vertex w=adjvector[j];
		if(graph.getVertexLabel(w)=="UNEXPLORED"){
			//graph.setEdgeLabel(v,w,"DISCOVERY");
			graph.setVertexLabel(w,"VISITED");
			q.push(w);
			Edge thisedge=graph.getEdge(v,w);
			m[w]=v;
		}

	
	}

}

Vertex temp=end;
int count=0;
while(temp!=start){
	count++;
	graph.setEdgeLabel(temp,m[temp],"MINPATH");
	temp=m[temp];
}


    return count;
}

/**
 * Finds a minimal spanning tree on a graph.
 * THIS FUNCTION IS GRADED.
 *
 * @param graph - the graph to find the MST of
 *
 * @todo Label the edges of a minimal spanning tree as "MST"
 *  in the graph. They will appear blue when graph.savePNG() is called.
 *
 * @note Use your disjoint sets class from MP 7.1 to help you with
 *  Kruskal's algorithm. Copy the files into the libdsets folder.
 * @note You may call std::sort instead of creating a priority queue.
 */
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

