#include "isomorphism.h"


vector <vector <int>> children;
vector <vector <int>> subtreeLabels;
vector <vector <int>> tree;
vector <vector <int>> L;
vector <int> map;
vector <int> pred;
int n;
//void tree_build(Tree A,Tree B)
void tree_build(Tree A)
{

  
  tree = A.getElements();
  n = tree.size();
}
vector <vector<int>> getTree()
{
return tree;
}

bool compare(int a, int b) {
    return subtreeLabels[a] < subtreeLabels[b];
}

bool equals(int a, int b) {
    return subtreeLabels[a] == subtreeLabels[b];
}

void generateMapping(int r1, int r2) {
    // to use if there are two trees 
    map.resize(n);
    map[r1] = r2 - n;
    sort(children[r1].begin(), children[r1].end(), compare);
    sort(children[r2].begin(), children[r2].end(), compare);
    for (int i = 0; i < (int) children[r1].size(); i++) {
        int u = children[r1][i];
        int v = children[r2][i];
        generateMapping(u, v);
    }
}

vector<int> findCenter(int offset = 0) {
    int cnt = n;
    vector<int> a;
    vector<int> deg(n);
    for (int i = 0; i < n; i++) {
        deg[i] = tree[i + offset].size();
        if (deg[i] <= 1) {
            a.push_back(i + offset);
            --cnt;
        }
    } 
    while (cnt > 0) {
        vector <int> na;
        for (int i = 0; i < (int) a.size(); i++) {
            int u = a[i];
            for (int j = 0; j < (int) tree[u].size(); j++) {
                int v = tree[u][j];
                if (--deg[v - offset] == 1) {
                    na.push_back(v);
                    --cnt;
                }
            }
        }
        a = na;
    }
    return a;
}

int dfs(int u, int p = -1, int depth = 0) {
    L[depth].push_back(u);
    int h = 0;
    for (int i = 0; i < (int) tree[u].size(); i++) {
        int v = tree[u][i];
        if (v == p)
            continue;
        pred[v] = u;
        children[u].push_back(v);
        h = max(h, dfs(v, u, depth + 1));
    }
    return h + 1;
}

bool rootedTreeIsomorphism(int r1, int r2) {
    L.assign(n,vector<int>());
    pred.assign(2 * n, -1);
    children.assign(2 * n, vector<int>());

    int h1 = dfs(r1);
    int h2 = dfs(r2);
    if (h1 != h2)
        return false;
    
    int h = h1 - 1;
    vector<int> label(2 * n);
    subtreeLabels.assign(2 * n, vector<int>());

    for (int i = h - 1; i >= 0; i--) {
        for (int j = 0; j < (int) L[i + 1].size(); j++) {
            int v = L[i + 1][j];
            subtreeLabels[pred[v]].push_back(label[v]); 
        }
        for (int j = 0; j < (int) L[i].size(); j++) {
            int v = L[i][j];
            sort(subtreeLabels[v].begin(), subtreeLabels[v].end());
        }

        sort(L[i].begin(), L[i].end(), compare);

        for (int j = 0, cnt = 0; j < (int) L[i].size(); j++) {
            if (j && !equals(L[i][j], L[i][j - 1]))
                ++cnt;
            label[L[i][j]] = cnt;
        }
    }
    if (!equals(r1, r2))
        return false;

    generateMapping(r1, r2);
    return true;
}


bool treeIsomorphism() {
    vector<int> c1 = findCenter();
    vector<int> c2 = findCenter(n);
    if (c1.size() == c2.size()) {
        if (rootedTreeIsomorphism(c1[0], c2[0]))
            return true;
        else if (c1.size() > 1)
            return rootedTreeIsomorphism(c1[1], c2[0]);
    }
    return false;
}

vector<pair<int,int>> get_subTree_isomorph()
{
    vector < pair < int , int > > subTreeIsomorph;
    vector < int > degre;
    
    for(int i = 0 ; i < tree.size() ; i++)
    {
            degre.push_back(tree[i].size());
    }

for(int i = 0 ; i < degre.size() ; i++)
    {
    for(int j = i ; j< degre.size(); j++)
        {
           if(degre[i] == degre[j] && degre[i]>1 && j!=i)
            {
                    if(rootedTreeIsomorphism(i,j))
                        { 
                            subTreeIsomorph.push_back({i,j}); 
                           // a++;
                        }
           }
        }
    }
  return  subTreeIsomorph;  
}

