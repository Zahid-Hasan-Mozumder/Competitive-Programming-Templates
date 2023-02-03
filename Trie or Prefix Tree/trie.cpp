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

struct node{
    char data;
    int cnt;
    node *child[26];
    node(char x){
        data = x;
        cnt = 1;
        for(int i=0; i<26; i++) child[i] = NULL;
    }
};

node *root = new node('\0');

void add(string s){
    node *curr = root;
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - 'a';
        if(curr->child[ind] != NULL){
            curr = curr->child[ind];
            curr->cnt++;
        }
        else{
            curr->child[ind] = new node(s[i]);
            curr = curr->child[ind];
        }
    }
}

void sub(string s){
    node *curr = root;
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - 'a';
        curr = curr->child[ind];
        curr->cnt--;
    }
}

int search(string s){
    node *curr = root;
    for(int i=0; i<s.size(); i++){
        int ind = s[i] - 'a';
        if(curr->child[ind] == NULL){
            return 0;
        }
        else{
            curr = curr->child[ind];
        }
    }
    return curr->cnt;
}


int main(){

    int t; cin>>t;
    while(t--){
        string a, b;
        cin>>a>>b;
        if(a == "add"){
            add(b);
        }
        else if(a == "remove"){
            sub(b);
        }
        else if(a == "find"){
            int ans = search(b);
            cout<< ans << '\n';
        }
    }
}
