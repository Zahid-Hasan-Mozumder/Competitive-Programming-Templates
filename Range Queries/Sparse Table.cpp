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
#define pipll pair<int, pair<ll, ll>>
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
#define vpipll vector<pair<int, pair<ll, ll>>>
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vplpii vector<pair<ll, pair<int, int>>>
#define vplpll vector<pair<ll, pair<ll, ll>>>
#define vvpil vector<vector<pair<int, ll>>>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9 + 7;
//const ll mod = 998244353;
const int N = 2e6 + 2;
const int sz = 1e6 + 2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

int n; 
vi a, log_2;
vvi spt;

int query(int l, int r){
    int len = r - l + 1;
    int x = log_2[len];
    return min(spt[l][x], spt[r - (1 << x) + 1][x]);
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

    cin >> n;
    a.clear(); a.resize(n);
    log_2.clear(); log_2.resize(n + 1, 0);
    for(int i = 2; i <= n; i++){
        log_2[i] = log_2[i / 2] + 1;
    }
    spt.clear(); spt.resize(n, vi(log_2[n] + 1, INT_MAX));
    for(int i = 0; i < n; i++){
        cin >> a[i];
        spt[i][0] = a[i]; 
    }
    for(int j = 1; j <= log_2[n]; j++){
        for(int i = 0; i <= n - (1 << j); i++){
            spt[i][j] = min(spt[i][j - 1], spt[i + (1 << (j - 1))][j - 1]);
        }
    }
    int q; cin >> q;
    while(q--){
        int l, r; cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}
