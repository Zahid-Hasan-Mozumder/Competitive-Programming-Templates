#include <bits/stdc++.h>

using namespace std;

#define vi vector<int>
#define pb push_back

void merge(vi &a, vi &cnt, int s, int m, int e){
    vector<int> l, r;
    for(int i=s; i<=m; i++) l.pb(a[i]);
    for(int i=m+1; i<=e; i++) r.pb(a[i]);
    int i = 0, j = 0, k = s;
    while(i < l.size() && j < r.size()){
        if(l[i] > r[j]){
            a[k] = r[j];
            cnt[m + 1 + j] += (l.size() - i);
            j++;
        }
        else{
            a[k] = l[i];
            i++;
        }
        k++;
    }
    while(i < l.size()){
        a[k] = l[i];
        i++;
        k++;
    }
    while(j < r.size()){
        a[k] = r[j];
        j++;
        k++;
    }
}

void countInv(vi &a, vi &cnt, int s, int e){
    if(s < e){
        int mid = (s + e) / 2;
        countInv(a, cnt, s, mid);
        countInv(a, cnt, mid + 1, e);
        merge(a, cnt, s, mid, e);
    }
}

int main(){

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vi a(n), cnt(n, 0);
        for(int i=0; i<n; i++) cin>>a[i];
        countInv(a, cnt, 0, n-1);
        int ans = 0;
        for(int i=0; i<n; i++) ans += cnt[i];
        cout<< ans << '\n';
    }
}
