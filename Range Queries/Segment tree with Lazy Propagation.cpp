#include <bits/stdc++.h>

using namespace std;

#define ll long long int

const int N = 2e5 + 5;
vector<ll> a(N), tree(4 * N), lazy(4 * N);

void build(int ind, int st, int en){
    if(st == en){
        tree[ind] = a[st];
        return;
    }
    int mid = (st + en) / 2;
    build(2 * ind + 1, st, mid);
    build(2 * ind + 2, mid + 1, en);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
}

void update(int ind, int st, int en, int l, int r, ll v){
    if(lazy[ind]){
        tree[ind] += (en - st + 1) * lazy[ind];
        if(st != en){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        tree[ind] += (en - st + 1) * v;
        if(st != en){
            lazy[2 * ind + 1] += v;
            lazy[2 * ind + 2] += v;
        }
        return;
    }
    int mid = (st + en) / 2;
    update(2 * ind + 1, st, mid, l, r, v);
    update(2 * ind + 2, mid + 1, en, l, r, v);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
}

void query(int ind, int st, int en, int l, int r, ll &sum){
    if(lazy[ind]){
        tree[ind] += (en - st + 1) * lazy[ind];
        if(st != en){
            lazy[2 * ind + 1] += lazy[ind];
            lazy[2 * ind + 2] += lazy[ind];
        }
        lazy[ind] = 0;
    }
    if(st > r || en < l) return;
    if(st >= l && en <= r){
        sum += tree[ind];
        return;
    }
    int mid = (st + en) / 2;
    query(2 * ind + 1, st, mid, l, r, sum);
    query(2 * ind + 2, mid + 1, en, l, r, sum);
    tree[ind] = tree[2 * ind + 1] + tree[2 * ind + 2];
}

int main(){
    
    int t; cin>>t;
    while(t--){
        for(int i=0; i<N; i++) a[i] = 0;
        for(int i=0; i<4*N; i++) tree[i] = 0;
        for(int i=0; i<4*N; i++) lazy[i] = 0;
        
        int n, q; cin>>n>>q;
        for(int i=0; i<n; i++) cin>>a[i];
        build(0, 0, n-1);
        while(q--){
            int qt; cin>>qt;
            if(qt == 0){
                int l, r; ll v;
                cin>>l>>r>>v;
                update(0, 0, n-1, l, r, v);
            }
            else if(qt == 1){
                int l, r;
                cin>>l>>r;
                ll sum = 0;
                query(0, 0, n-1, l, r, sum);
                cout<< sum << '\n';
            }
        }
    }
}
