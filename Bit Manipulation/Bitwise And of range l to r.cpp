ll rangeBitwiseAnd(ll n, ll m){
    ll ans = 0LL;
    for(ll bit=63; bit>=0; bit--){
        if( (m & (1LL << bit)) != (n & (1LL << bit)) ){
            break;
        }
        else{
            ans |= (m & (1LL << bit));
        }
    }
    return ans;
}
