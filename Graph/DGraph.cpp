#include <bits/stdc++.h>
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
int read(int &re) { return scanf("%d", &re); }
using namespace std;

const int MAXN = 202000;
int father[MAXN];
class DGraph {
private:
    int N;
    vector<set<int> > G,rG ;//= new set<int>[MAXN];
    //set<int> rG[MAXN];
    int root = -1;
public:
    DGraph(int NN = 0) {
        N = NN;
        G.resize(N+3); rG.resize(N+3);
        for (int i=1;i<=N;i++) {
            G[i].clear();
            rG[i].clear();
        }
        root = -1;
    }
    int getN() {
        return N;
    }
    void addEdge(int u, int v) {
        G[u].insert(v);
        rG[v].insert(u); // parent
      //  G[v].push_back(u);
    }
    int getRoot() {
        if (root == -1) {
            for (int i=1;i<=N;i++) {
                if (rG[i].empty()) {
                    root = i;
                    return root;
                }
            }   
        }
        return root;
    }
    set<int> &getNbr(int u) {
        return G[u];
    }
    int getDegree(int u) {
        return G[u].size();
    }
}G;
