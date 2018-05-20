/*
 * Matrix.h
 *
 *  Created on: 18/03/2018
 *      Author: reda 
 */
#include "libs.h"

class Dag{
public: 
    Dag(vector < vector< int>>  tree);
    void delete_tree(int noeud);
    vector<vector<int>> toDAG(vector <pair<int,int>> iso);
    int getParent(int noeud);
    vector<vector<int>> getDag();
private:
    vector <vector <int>> tree;
};
