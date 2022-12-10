vector<ll> twosPower;

void generateTwosPower(){
    twosPower.pb(1);
    ll curr = 1;
    for(int i=1; i<61; i++){
        curr *= 2;
        twosPower.pb(curr);
    }
}