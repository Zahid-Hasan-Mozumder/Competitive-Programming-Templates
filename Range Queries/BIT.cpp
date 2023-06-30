// BIT or Fenwick tree is a 1 based indexing tree
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
#include <bits/stdc++.h>
#include <climits>

using namespace std;

#define ll long long int
#define vll vector<ll>

int n, q;
vll a, tree;

void add(int i, ll x){
    while(i <= n){
        tree[i] += x;
        i += (i & -i);
    }
}

void rem(int i, ll x){
    while(i <= n){
        tree[i] -= x;
        i += (i & -i);
    }
}

void query(int i, ll &sum){
    while(i){
        sum += tree[i];
        i -= (i & -i);
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

    cin >> n >> q;
    a.clear(); tree.clear();
    a.resize(n + 1, 0); tree.resize(n + 1, 0);
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        add(i, a[i]);
    }
    while(q--){
        int qt; cin >> qt;
        if(qt == 1){
            int i; ll x;
            cin >> i >> x;
            i++;
            rem(i, x);
            a[i] -= x;
        }
        else if(qt == 2){
            int i; ll x;
            cin >> i >> x;
            i++;
            add(i, x);
            a[i] += x;
        }
        else{
            int i, j; cin >> i >> j;
            j++;
            ll sum_i = 0, sum_j = 0;
            query(i, sum_i);
            query(j, sum_j);
            ll sum = sum_j - sum_i;
            cout << sum << '\n';
        }
    }
}
