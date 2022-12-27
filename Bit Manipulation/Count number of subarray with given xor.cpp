#define ll long long int

ll subarrayXor(vector<int> &a, int n, int m){
    ll ans = 0;
    int cumXor = 0;
    vector<int> mp(4*n, 0);
    for (int i=0; i<n; i++){
        cumXor ^= a[i];
        int temp = m ^ cumXor;
        ans += (ll)mp[temp];
        if(cumXor == m)
            ans++;
        mp[cumXor]++;
    }
    return ans;
}
