#include <bits/stdc++.h>
#include <cmath>
#include <climits>
#include <sstream>
#include <string>

using namespace std;

#define ll long long int

#define vi vector<int>
#define vll vector<lli>
#define vb vector<bool>
#define vvi vector<vector<int>>
#define vvll vector<vector<lli>>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vvpii vector<vector<pair<int, int>>>
#define si stack<int>
#define sll stack<lli>
#define qi queue<int> 
#define qll queue<lli>
#define pii pair<int, int>
#define pll pair<lli, lli>
#define psi pair<string, int>
#define psl pair<string, lli>
#define piii pair<int, pair<int, int>>
#define pb push_back
#define pf push_front

const ll mod = 1e9+7;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

int len = 0;

bool cmp(piii &a, piii &b){
    if(a.second.first/len == b.second.first/len)
        return a.second.second > b.second.second;
    return a.second.first/len < b.second.first/len;
}

bool cmp2(pii &a, pii &b){
    return a.first < b.first;
}

int main(){

    int n; cin>>n;
    vector<int> a(n); vector<pii> ans; map<int, int> mp;
    for(int i=0; i<n; i++) cin>>a[i];
    int q; cin>>q;
    vector<piii> que;
    for(int i=0; i<q; i++){
        int l, r;
        cin>>l>>r;
        l--; r--;
        que.pb({i, {l, r}});
    }
    len = ceil(sqrt(n));
    sort(que.begin(), que.end(), cmp);
    int cnt = 0;
    int l = 0, r = -1;
    for(int i=0; i<que.size(); i++){
        int ind = que[i].first;
        int st = que[i].second.first;
        int en = que[i].second.second;
        while(r < en){
            r++;
            mp[a[r]]++;
            if(mp[a[r]]==1) cnt++;
        }
        while(r > en){
            mp[a[r]]--;
            if(mp[a[r]] == 0) cnt--;
            r--;
        }
        while(l < st){
            mp[a[l]]--;
            if(mp[a[l]] == 0) cnt--;
            l++;
        }
        while(l > st){
            l--;
            mp[a[l]]++;
            if(mp[a[l]] == 1) cnt++;
        }
        ans.pb({ind, cnt});
    }
    sort(ans.begin(), ans.end(), cmp2);
    for(int i=0; i<ans.size(); i++){
        cout<< ans[i].second << '\n';
    }
}
