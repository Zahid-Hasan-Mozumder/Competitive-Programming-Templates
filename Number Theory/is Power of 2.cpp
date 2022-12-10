bool isPow2(ll n){
    ll cnt = 0;
    while(n){
        if(n & 1) cnt++;
        n>>=1; 
    }
    if(cnt == 1) return true;
    else return false;
}