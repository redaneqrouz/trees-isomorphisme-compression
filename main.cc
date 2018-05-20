/*
 * Matrix.h
 *
 *  Created on: 18/03/2018
 *      Author: reda 
 */

#include "isomorphism.h"
#include "dag.h"

int main(void)
{
  Matrix matrice1("txt_matrix");  
 // Matrix matrice2("txt_matrix2");  
 // vector <vector <int> > graph = matrice_.myMatrix();

  Tree arbre1(matrice1.myMatrix());
  tree_build(arbre1);

cout << "\naffichage des element isomorph";
vector <pair<int,int>>  subTree_iso = get_subTree_isomorph();

subTree_iso.erase(std::unique(subTree_iso.begin(), subTree_iso.end()), subTree_iso.end());

cout << "the two root of each subtree isomorph \n";
for(const auto& s : subTree_iso)
 {
    cout << "\first: " << s.first <<" second: " <<s.second;
 }
cout << "\n";
vector <vector <int>> dag_Tree = arbre1.getElements();

Dag dag(dag_Tree);

dag.toDAG(subTree_iso);


vector < vector <int>> dag_t = dag.getDag();

//vector < vector <int>> dag_t = delete_tree(dag_Tree,14);
cout << "\nget the dag\n";
int pere = 0;
 for(const auto & a:dag_t)
        {
        cout << "pere "<<pere++<<": ";
            for(const auto & b: a)
                cout << " " << b;
        cout << "\n";
        }
        
return 0;
}
