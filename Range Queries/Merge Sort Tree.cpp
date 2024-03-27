/*
Given an array a of n numbers and q queries. The queries will be 2 types,
 -> 1 ind x : You have to change the a[ind] to x.
 -> 2 l r k : You have to print the number of elements strictly greater than k
              in the subarray a[l...r]
*/
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define vvvi vector<vector<vector<int>>>
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
const double pi = acos(-1.0);
const double PI = 3.1415926535897;
const double eps = 1e-6;

int n, q;
vi a;
vvi tree;

void build(int ind, int st, int en){
    if(st == en){
        tree[ind].pb(a[st]);
        return;
    }
    int mid = (st + en) / 2;
    build(2 * ind + 1, st, mid);
    build(2 * ind + 2, mid + 1, en);

    // Using the concept of merge sort on left subtree and right subtree
    int i = 0, j = 0;
    while(i < tree[2 * ind + 1].size() && j < tree[2 * ind + 2].size()){
        if(tree[2 * ind + 1][i] <= tree[2 * ind + 2][j]){
            tree[ind].pb(tree[2 * ind + 1][i]);
            i++;
        }
        else{
            tree[ind].pb(tree[2 * ind + 2][j]);
            j++;
        }
    }
    while(i < tree[2 * ind + 1].size()){
        tree[ind].pb(tree[2 * ind + 1][i]);
        i++;
    }
    while(j < tree[2 * ind + 2].size()){
        tree[ind].pb(tree[2 * ind + 2][j]);
        j++;
    }
}

void update(int ind, int st, int en, int in, int x){
    if(st > in || en < in) return;
    if(st == en){
        a[in] = x;
        tree[ind][0] = x;
        return;
    }
    int mid = (st + en) / 2;
    update(2 * ind + 1, st, mid, in, x);
    update(2 * ind + 2, mid + 1, en, in, x);

    // Using the concept of merge sort on left subtree and right subtree
    tree[ind].clear();
    int i = 0, j = 0;
    while(i < tree[2 * ind + 1].size() && j < tree[2 * ind + 2].size()){
        if(tree[2 * ind + 1][i] <= tree[2 * ind + 2][j]){
            tree[ind].pb(tree[2 * ind + 1][i]);
            i++;
        }
        else{
            tree[ind].pb(tree[2 * ind + 2][j]);
            j++;
        }
    }
    while(i < tree[2 * ind + 1].size()){
        tree[ind].pb(tree[2 * ind + 1][i]);
        i++;
    }
    while(j < tree[2 * ind + 2].size()){
        tree[ind].pb(tree[2 * ind + 2][j]);
        j++;
    }
}

int query(int ind, int st, int en, int l, int r, int k){
    if(st > r || en < l) return 0;
    if(st >= l && en <= r)
    {
        int len = en - st + 1;
        int lo = 0, hi = len - 1;
        while(lo <= hi)
        {
            int m = (lo + hi) / 2;
            if(tree[ind][m] <= k) lo = m + 1;
            else hi = m - 1;
        }
        return len - lo;
    }
    int mid = (st + en) / 2;
    return query(2 * ind + 1, st, mid, l, r, k) + query(2 * ind + 2, mid + 1, en, l, r, k);
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

    cin >> n >> q;
    a.clear(); a.resize(n);
    tree.clear(); tree.resize(4 * n);
    for(int i = 0; i < n; i++) cin >> a[i];
    build(0, 0, n - 1);
    while(q--){
        int qt; cin >> qt;
        if(qt == 1){
            int i, x;
            cin >> i >> x;
            i--;
            update(0, 0, n - 1, i, x);
        }
        else{
            int l, r, k;
            cin >> l >> r >> k;
            l--; r--;
            cout << query(0, 0, n - 1, l, r, k) << '\n';
        }
    }
}
