#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pipii pair<int, pair<int, int>>
#define vi vector<int>
#define vb vector<bool>
#define vpii vector<pair<int, int>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

void prims(vvpii al, int n){
    vb vis(n, false);
    vpii mst;
    priority_queue<pipii, vpipii, greater<pipii>> pq;
    int sum = 0;
    pq.push({0, {0, -1}});
    while(!pq.empty()){
        auto it = pq.top();
        int w = it.ff;
        int i = it.ss.ff;
        int p = it.ss.ss;
        pq.pop();
        if(!vis[i]){
            vis[i] = true;
            if(p != -1) mst.pb({p, i});
            sum += w;
            for(auto it : al[i]){
                if(!vis[it.ff]){
                    pq.push({it.ss, {it.ff, i}});
                }
            }
        }
    }
}

int main(){
    int n, m; cin>>n>>m;
    vvpii al(n);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        al[u].pb({v, w});
        al[v].pb({u, w});
    }
    prims(al, n);
}
