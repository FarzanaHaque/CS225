/**
 * @file NimLearner.cpp
 * CS 225 - Fall 2017
 */

#include "NimLearner.h"


/**
 * Constructor to create a game of Nim with `startingTokens` starting tokens.
 *
 * This function creates a graph, `g_` representing all of the states of a
 * game of Nim with vertex labels "p#-X", where:
 * - # is the current player's turn; p1 for Player 1, p2 for Player2
 * - X is the tokens remaining at the start of a player's turn
 *
 * For example:
 *   "p1-4" is Player 1's turn with four (4) tokens remaining
 *   "p2-8" is Player 2's turn with eight (8) tokens remaining
 *
 * All legal moves between states are created as edges with initial weights
 * of 0.
 *
 * @param startingTokens The number of starting tokens in the game of Nim.
 */
NimLearner::NimLearner(unsigned startingTokens) : g_(true) {
//	g_.setVertexName(g_.getStartingVertex(),"p1-10");
	//vector<Vertex> vertices;
	for(unsigned i=0; i<=startingTokens;i++){
		Vertex next=g_.insertVertex();
		Vertex next2=g_.insertVertex();
		g_.setVertexLabel(next,"p1-"+std::to_string(i));
		g_.setVertexLabel(next2,"p2-"+std::to_string(i));
		//vertices.push_back(next);
		//vertices.push_back(next2);
	}
	//Vertex cur=vertices[0];
	for(unsigned i=startingTokens;i>1;i--){
		Vertex p1i=g_.getVertexByLabel("p1-"+std::to_string(i));
		Vertex p2i=g_.getVertexByLabel("p2-"+std::to_string(i));
		Vertex p1neg1=g_.getVertexByLabel("p1-"+std::to_string(i-1));
		Vertex p1neg2=g_.getVertexByLabel("p1-"+std::to_string(i-2));
		Vertex p2neg1=g_.getVertexByLabel("p2-"+std::to_string(i-1));
		Vertex p2neg2=g_.getVertexByLabel("p2-"+std::to_string(i-2));
		g_.insertEdge(p1i,p2neg1);
		g_.insertEdge(p1i,p2neg2);
		g_.insertEdge(p2i,p1neg1);
		g_.insertEdge(p2i,p1neg2);
		g_.setEdgeWeight(p1i,p2neg1,0);
		g_.setEdgeWeight(p1i,p2neg2,0);
		g_.setEdgeWeight(p2i,p1neg1,0);
		g_.setEdgeWeight(p2i,p1neg1,0);
	}
	Vertex p11=g_.getVertexByLabel("p1-1");
	Vertex p21=g_.getVertexByLabel("p2-1");
	Vertex p10=g_.getVertexByLabel("p1-0");
	Vertex p20=g_.getVertexByLabel("p2-0");	
	g_.insertEdge(p11,p20);
	g_.insertEdge(p21,p10);
	g_.setEdgeWeight(p11,p20,0);
	g_.setEdgeWeight(p21,p10,0);
}

/**
 * Plays a random game of Nim, returning the path through the state graph
 * as a vector of `Edge` classes.  The `origin` of the first `Edge` must be
 * the vertex with the label "p1-#", where # is the number of starting
 * tokens.  (For example, in a 10 token game, result[0].origin must be the
 * vertex "p1-10".)
 *
 * @returns A random path through the state space graph.
 */
std::vector<Edge> NimLearner::playRandomGame() const {
  vector<Edge> path;

  return path;
}


/*
 * Updates the edge weights on the graph based on a path through the state
 * tree.
 *
 * If the `path` has Player 1 winning (eg: the last vertex in the path goes
 * to Player 2 with no tokens remaining, or "p2-0", meaning that Player 1
 * took the last token), then all choices made by Player 1 (edges where
 * Player 1 is the source vertex) are rewarded by increasing the edge weight
 * by 1 and all choices made by Player 2 are punished by changing the edge
 * weight by -1.
 *
 * Likewise, if the `path` has Player 2 winning, Player 2 choices are
 * rewarded and Player 1 choices are punished.
 *
 * @param path A path through the a game of Nim to learn.
 */
void NimLearner::updateEdgeWeights(const std::vector<Edge> & path) {

}


/**
 * Returns a constant reference to the state space graph.
 *
 * @returns A constant reference to the state space graph.
 */
const Graph & NimLearner::getGraph() const {
  return g_;
}
