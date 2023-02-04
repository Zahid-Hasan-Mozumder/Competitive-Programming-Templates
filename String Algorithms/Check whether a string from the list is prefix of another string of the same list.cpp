// Problem link: https://lightoj.com/problem/consistency-checker
//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
#define piii pair<pair<int, int>, int>
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
#define vvpii vector<vector<pair<int, int>>>
#define vvpll vector<vector<pair<ll, ll>>>
#define vvpli vector<vector<pair<ll, int>>>
#define vvpil vector<vector<pair<int, ll>>>
#define si stack<int>
#define sll stack<ll>
#define qi queue<int>
#define qll queue<ll>
#define pb push_back
#define pf push_front
#define ff first
#define ss second

const ll mod = 1e9+7;
const int maxN = 1e6;
const int sz = 1e6+2;
const double pi = acos(-1.0);
const double PI = 3.1415926535897;


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

    int t; cin>>t;
    int cs = 1;
    while(t--){
        int n; cin>>n;
        vector<string> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        unordered_set<string> whole, prefix;
        bool flag = true;
        for(int i=0; i<n; i++){
            string curr = a[i];
            if(flag){
                if(prefix.find(curr) != prefix.end()){
                    flag = false;
                }
                if(flag){
                    string s;
                    s.pb(curr[0]);
                    for(int j=1; j<curr.size(); j++){
                        if(whole.find(s) != whole.end()){
                            flag = false;
                            break;
                        }
                        prefix.insert(s);
                        s.pb(curr[j]);
                    }
                }
                whole.insert(curr);
            }
            else{
                break;
            }
        }
        cout<< "Case " << cs << ": ";
        if(flag) cout<< "YES" << '\n';
        else cout<< "NO" << '\n';
        cs++;
    }
}
