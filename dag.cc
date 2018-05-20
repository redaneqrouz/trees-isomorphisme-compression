/*
 * Matrix.h
 *
 *  Created on: 18/03/2018
 *      Author: reda 
 */

#include "dag.h"
#include <queue>

Dag:: Dag(vector <vector <int>> arbre)
{
tree = arbre;
}

int Dag::getParent(int noeud)
{
for(int i=0;i<tree.size();i++)
    {
    for(const int & leaf:tree[i])
        {
        if(leaf == noeud)
            return i;
        }
    }
    return -1;
}

void Dag::delete_tree(int noeud)
{   
    //delete_tree marche bien 
    int parent = getParent(noeud);
    int vertix = noeud;
    queue <int> to_delete;
    
    to_delete.push(vertix);
    
    //delete all the vertix of noeud 

  while(!to_delete.empty())
    {
       int noeud_t = to_delete.front();
       to_delete.pop();
       parent = getParent(noeud_t);
       tree[parent].erase(std::remove(tree[parent].begin(), tree[parent].end(), noeud_t),  tree[parent].end());
       for(int voisin_t : tree[noeud_t])
        {
            to_delete.push(voisin_t);
        }
    }
}

vector<vector<int>> Dag::toDAG(vector <pair<int,int>> iso)
{
// first thing to do is merging all the subTree isomorphe 
    
for(const auto & isom: iso)
    {
        int father = getParent(isom.second);
        delete_tree(isom.second);
        tree[father].push_back(isom.first);
    }
//second thing to do is merging all the leaves
    //finding the leaves this part is working fine 
vector <int> leaves;
for(int i=0;i<tree.size();i++)
{
    if(tree[i].size() == 0)
        leaves.push_back(i);
}
//erase non connexe element 

 //int SIZE_LEAVES = leaves.size();
 
int fouille_dag = leaves[0];

cout << "\nthe vertix picked: "<<fouille_dag;

cout << "\n\\n\n";

for(int i=0;i<leaves.size();i++)
        {
            if(fouille_dag != leaves[i])
            {
            int pf = getParent(leaves[i]);
            if(pf != -1)
            {
          // tree[pf].erase(leaves[pf]);
            //tree[pf].erase (tree[pf].begin()+leaves[i]);
           tree[pf].erase(std::remove(tree[pf].begin(), tree[pf].end(), leaves[i]),  tree[pf].end());
           //    tree[pf].erase (tree[pf].begin()+leaves[i]);
                tree[pf].push_back(fouille_dag);
            }
            }
        }
   //remove non connexe element 
   vector <vector <int >> arbre;
 return tree;
}

vector<vector<int>> Dag::getDag()
{
    return tree;
}

