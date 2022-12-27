#include <bits/stdc++.h>

using namespace std;

#define ll long long int

int main(){

    int t;
    cin>>t;
    for(int cs=1; cs<=t; cs++){
        int n, q;
        cin>>n>>q;
        vector<int> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        int len = ceil(sqrt(n));
        vector<int> b(len, INT_MAX);
        for(int i=0; i<n; i++){
            b[i/len] = min(a[i], b[i/len]);
        }
        vector<int> op;
        while(q--){
            int l, r;
            cin>>l>>r;
            l--; r--;
            int ans = INT_MAX;
            for(int i=l; i<=r;){
                if(i%len==0 && i+len-1<=r){
                    ans = min(ans, b[i/len]);
                    i+=len;
                }
                else{
                    ans = min(ans, a[i]);
                    i++;
                }
            }
            op.push_back(ans);
        }
        cout<< "Case " << cs << ":" << '\n';
        for(int j=0; j<op.size(); j++)
            cout<< op[j] << '\n';
    }
}
