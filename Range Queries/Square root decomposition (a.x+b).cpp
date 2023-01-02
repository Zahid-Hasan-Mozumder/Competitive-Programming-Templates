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
#define si stack<int>
#define sll stack<ll>
#define qi queue<int>
#define qll queue<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define psi pair<string, int>
#define psl pair<string, ll>
#define piii pair<pair<int, int>, int>
#define pb push_back
#define pf push_front

const ll mod = 1e9+7;
const int maxN = 5e6+5;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;

struct iii{
    int ind;
    int x;
    int y;
};

bool cmp(iii &a, iii &b){
    return a.y < b.y;
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

    int n; cin>>n;
    vll arr(n+1); vector<iii> que;
    for(int i=1; i<=n; i++) cin>>arr[i];
    int q; cin>>q;
    for(int i=0; i<q; i++){
        int a, b;
        cin>>a>>b;
        que.pb({i, a, b});
    }
    sort(que.begin(), que.end(), cmp);
    vll res(q); vll csum(n+1, 0);
    int len = ceil(sqrt(n+1));
    int curr = 0;
    for(int i=0; i<q; i++){
        int ind = que[i].ind;
        int a = que[i].x;
        int b = que[i].y;
        if(b > len){
            ll ans = 0;
            for(int j=a; j<=n; ){
                ans += arr[j];
                j+=b;
            }
            res[ind] = ans;
        }
        else{
            if(b > curr){
                for(int j=0; j<=n; j++) csum[j] = 0;
                curr = b;
                for(int j=n; j>=1; j--){
                    csum[j] = arr[j];
                    if(j + curr <= n) csum[j] += csum[j + curr];
                }
            }
            res[ind] = csum[a];
        }
    }
    for(int i=0; i<q; i++) cout<< res[i] << '\n';
}
