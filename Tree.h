/*
 * Matrix.h
 *
 *  Created on: 18/03/2018
 *      Author: reda 
 */
#include "Matrix.h"

class Tree {
public:
Tree( vector< vector <int> > matrice);
int NumNodes() const;
int NumArcs() const;
void AddArc(int from, int to);
   // Returns the number of arcs originating from "node".
  // In the example above, OutDegree(1) = 3, OutDegree(4) = 0.
int OutDegree(int node) const;
const vector<int>& Neighbors(int node) const;
vector <vector <int>> & getElements();
void affiche_tree();
private:
 vector<vector<int>> tree_;
 int num_arcs_;
};

