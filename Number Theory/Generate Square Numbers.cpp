vector<ll> powNum;
void generatePowNum(){
    for(lli i=0; i<=1e6; i++){
        lli curr = i * i;
        powNum.pb(curr);
    }
}