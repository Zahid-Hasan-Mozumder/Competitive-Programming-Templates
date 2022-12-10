ll MOD(ll a, ll m){
    if(a >= 0){
        return a%m;
    }
    else{
        return ((a%m)+m)%m;
    }
}