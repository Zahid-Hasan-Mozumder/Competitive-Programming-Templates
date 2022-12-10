const ll mod = 1e9+7;
vector<ll> modFact(2e6+2);

void generateModFact(){
    modFact[0] = 1;
    for(int i=1; i<=2e6; i++){
        modFact[i] = ((modFact[i-1] % mod) * (i % mod)) % mod;
    }
}
