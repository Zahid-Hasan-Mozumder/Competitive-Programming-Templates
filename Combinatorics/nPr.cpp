ll fact(ll n){
    ll ans = 1;
    for(int i=1; i<=n; i++)
        ans *= i;
    return ans;
}

ll nPr(ll n, ll r){
    if(n<=0 || r > n)
        return 0;
    ll nf = fact(n);
    ll n_rf = fact(n-r);
    ll ans = nf / n_rf;
    return ans;
}