/*
 * Matrix.h
 *
 *  Created on: 18/03/2018
 *      Author: reda 
 */
#include "Tree.h"

Tree::Tree(vector<vector<int>> tree):tree_(tree.size())
{ 
num_arcs_ = 0;
// ici marche bien la lectue de l'arbre
  int i=0;

 for (const auto & a:tree)
    {
    int ind_col = 0;
    for(const auto & b:a)
    {   
        if(b != 0)
        {
        tree_[i].push_back(ind_col);
        //pour que TREE a une direction 
        // pour verifier si la totalité des deux arbre sont isomorph verouiiler le commentaire suivant par contre il marche pas bien pour calculer les structures isomorphic 
        //tree_[ind_col].push_back(i);        
        ++num_arcs_;    
        }
     ind_col++;
     }    
    i++;
    }
}

void Tree::AddArc(int from, int to) {
  tree_[from].push_back(to);
  ++num_arcs_;
}


int Tree::NumNodes() const {
  return tree_.size();
}

int Tree::NumArcs() const {
  return num_arcs_;
}

int Tree::OutDegree(int node) const {
  return tree_[node].size();
}

const vector<int>& Tree::Neighbors(int node) const {
  return tree_[node];
}

vector <vector <int>> & Tree::getElements()
{
return tree_;
}

void Tree::affiche_tree()
{
int pere = 0;
 for(const auto & a:tree_)
        {
        cout << "pere "<<pere++<<": ";
            for(const auto & b: a)
                cout << " " << b;
        cout << "\n";
        }
}


