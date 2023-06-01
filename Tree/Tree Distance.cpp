// Problem link: https://cses.fi/problemset/result/6184106/
//----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int

#define pii pair<int, int>
#define pli pair<ll, int>
#define pil pair<int, ll>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pipii pair<int, pair<int, int>>
#define plpii pair<ll, pair<int, int>>
#define plpll pair<ll, pair<ll, ll>>
#define piipii pair<pair<int, int>, pair<int, int>>
#define vi vector<int>
#define vll vector<ll>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<ll>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvvll vector<vector<vector<ll>>>
#define vvs vector<vector<string>>
#define vpii vector<pair<int, int>>
#define vpll vector<pair<ll, ll>>
#define vpli vector<pair<ll, int>>
#define vpil vector<pair<int, ll>>
#define vpipii vector<pair<int, pair<int, int>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
//const ll mod = 998244353;
const int maxN = 5e6+5;
const int sz = 1e7+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

int mxDepth = -1;
int leftNode = -1;
int rightNode = -1;

void farthestNode(vvi &al, int depth, int p, int i, int &node){
    if(depth > mxDepth){
        mxDepth = depth;
        node = i;
    }
    for(auto v : al[i]){
        if(v == p) continue;
        farthestNode(al, depth + 1, i, v, node);
    }
}

void dfs(vvi &al, vi &dist, int depth, int p, int i){
    dist[i] = depth;
    for(auto v : al[i]){
        if(v == p) continue;
        dfs(al, dist, depth + 1, i, v);
    }
}

void zahid(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){

    zahid();

    int n; cin >> n;
    vvi al(n + 1);
    for(int i = 0; i < n - 1; i++){
        int u, v; cin >> u >> v;
        al[u].pb(v);
        al[v].pb(u);
    }
    mxDepth = -1;
    farthestNode(al, 0, -1, 1, leftNode);
    mxDepth = -1;
    farthestNode(al, 0, -1, leftNode, rightNode);
    vi dist1(n + 1, -1), dist2(n + 1, -1);
    dfs(al, dist1, 0, -1, leftNode);
    dfs(al, dist2, 0, -1, rightNode);
    for(int i = 1; i <= n; i++){
        cout << max(dist1[i], dist2[i]) << " ";
    }
    cout << '\n';
}
