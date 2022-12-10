vector<ll> luckyNum;

void generate(ll curr){
    if(curr > 1e9)
        return;
    ll first = curr*10 + 4;
    ll second = curr*10 + 7;
    luckyNum.pb(first);
    luckyNum.pb(second);
    generate(first);
    generate(second);
}

void generateLuckyNum(){
    ll curr = 0;
    generate(curr);
    sort(luckyNum.begin(), luckyNum.end());
}