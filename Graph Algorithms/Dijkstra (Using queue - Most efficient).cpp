#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define ppiii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vppiii vector<pair<pair<int, int>, int>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvpli vector<vector<pair<ll, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define sti stack<int>
#define stll stack<ll>
#define qi queue<int>
#define qll queue<ll>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

vll dist(sz, LLONG_MAX); 
vb taken(sz, false);
vi parent(sz, -1);

void dijkstra(vvpil &al, int src){
    queue<int> q;
    dist[src] = 0; parent[src] = -1;
    q.push(src);
    taken[src] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        taken[u] = false;
        for(int i=0; i<al[u].size(); i++)
        {
            int v = al[u][i].ff;
            ll cost_uv = al[u][i].ss;
            if(dist[u] + cost_uv <= dist[v])
            {
                dist[v] = dist[u] + cost_uv;
                parent[v] = u;
                if(!taken[v])
                {
                    taken[v] = true;
                    q.push(v);
                }
            }
        }
    }
}

void printPath(int des, int src){
    if(des != src) printPath(parent[des]);
    cout<< des << " ";
}

int main(){

    int n, m, k;
    cin>>n>>m>>k;
    vvpil al(n+1); 
    for(int i=0; i<m; i++){
        ll u, v, w;
        cin>>u>>v>>w;
        al[u].pb({v, w});
        al[v].pb({u, w});
    }
    int src; cin>>src;
    dijkstra(al, src);
    printPath(n, src);
}
