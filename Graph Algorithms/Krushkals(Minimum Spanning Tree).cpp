#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define vi vector<int>
#define vpii vector<pair<int, int>>
#define vpipii vector<pair<int, pair<int, int>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

int sum = 0;
vi rank, parent;
vpii mst;

void initialize(int n){
    rank.resize(n+1, 0); 
    parent.resize(n+1);
    mst.clear();
    sum = 0;
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

void krushkals(vpipii &edges, int n){
    initialize(n);
    for(auto it : edges){
        int w = it.ff, u = it.ss.ff, v = it.ss.ss;
        int upu = findParent(u), upv = findParent(v);
        if(upu == upv) continue;
        sum += w;
        mst.pb({u, v});
        unionByRank(u, v);
    }
}

int main(){
    int n, m; cin>>n>>m;
    vpipii edges;
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        edges.pb({w, {u, v}});
    }
    sort(edges.begin(), edges.end());
    krushkals(edges, n);
    cout<< sum << '\n';
    for(auto it : mst){
        cout<< it.ff << " " << it.ss << '\n';
    }
}
