#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

#define ll long long int

#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvpli vector<vector<pair<ll, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define si stack<int>
#define sll stack<ll>
#define qi queue<int>
#define qll queue<ll>
#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

vll dist(sz, LLONG_MAX);
set<pli> pq;

void dijkstra(vvpil &al, int src){
    dist[src] = 0;
    while(!pq.empty())
    {
        int u = pq.begin()->ss;
        pq.erase(pq.begin());
        for(int i=0; i<al[u].size(); i++)
        {
            int v = al[u][i].ff;
            ll cost_uv = al[u][i].ss;
            if(dist[u] + cost_uv < dist[v])
            {
                pq.erase({dist[v], v});
                dist[v] = dist[u] + cost_uv;
                lastUpdate[v] = u;
                pq.insert({dist[v], v});
            }
        }
    }
}

int main(){
  
    int n, m;
    cin>>n>>m;
    vvpil al(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        al[u].pb({v, w});
        al[v].pb({u, w});
    }
    pq.insert({0, 1});
    dijkstra(al, 1);
}
