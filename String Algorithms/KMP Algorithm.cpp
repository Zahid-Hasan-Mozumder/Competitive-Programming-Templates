#include <bits/stdc++.h>

using namespace std;

#define ll long long int

vector<int> create_lps(string x){
    vector<int> lps(x.size(), 0);
    int ind = 0;
    for(int i=1; i<x.size(); ){
        if(x[ind] == x[i]){
            lps[i] = ind + 1;
            ind++; i++;
        }
        else{
            if(ind != 0) ind = lps[ind - 1];
            else i++;
        }
    }
    return lps;
}

void kmp(string s, string x){
    vector<int> lps = create_lps(x);
    bool flag = false;
    int i = 0, j = 0;
    while(i < s.size()){
        if(s[i] == x[j]){
            i++; j++;
        }
        else{
            if(j != 0) j = lps[j - 1];
            else i++;
        }

        if(j == x.size()){
            flag = true;
            cout<< "Found at position: " << i - x.size() << '\n';
            j = lps[j-1];
        }
    }
    if(!flag) cout<< -1 << '\n';
}

int main(){
    string s; getline(cin, s);
    string x; getline(cin, x);
    kmp(s, x);
}
