#include "libs.h"
#include "Tree.h"

// if you like to read two trees and merge them in one to apply Isomorphism test 
//void tree_build(Tree A,Tree B);


void tree_build(Tree A);

void generateMapping(int r1, int r2);

vector <int> findCenter(int);

int dfs(int , int , int );

bool rootedTreeIsomorphism(int r1, int r2);

bool treeIsomorphism();

vector<pair<int,int>> get_subTree_isomorph();

vector <vector <int>> getTree();
