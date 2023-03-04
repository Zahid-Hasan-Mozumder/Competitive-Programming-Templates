#include <bits/stdc++.h>
#include <climits>

using namespace std;

vector<int> rank, parent;

void initialize(int n){
    rank.resize(n+1, 0); 
    parent.resize(n+1);
    for(int i=1; i<=n; i++) parent[i] = i;
}

int findParent(int u){
    if(u == parent[u])
        return u;
    return parent[u] = findParent(parent[u]);
}

void unionByRank(int u, int v){
    int upu = findParent(u);
    int upv = findParent(v);
    if(upu == upv) return;
    if(rank[upu] < rank[upv]){
        parent[upu] = upv;
    }
    else if(rank[upu] > rank[upv]){
        parent[upv] = upu;
    }
    else{
        parent[upv] = upu;
        rank[upu]++;
    }
}

int main(){
    int n, q; cin>>n>>q;
    initialize(n);
    while(q--){
        int qt; cin>>qt;
        // 1 : Add an edge between this two nodes
        // 2 : Does this two nodes belong to the same component
        if(qt == 1){
            int u, v; cin>>u>>v;
            unionByRank(u, v);
        }
        else if(qt == 2){
            int u, v; cin>>u>>v;
            int upu = findParent(u);
            int upv = findParent(v);
            if(upu == upv) cout<< "Belongs to the same component" << '\n';
            else cout<< "Does not belong to the same component" << '\n';
        }
    }
}
