#include<bits/stdc++.h>

using namespace std;

#define ll long long int
const ll mod = 1e6+3;

ll POW_MOD(ll a, ll b){
    if(b == 0)
        return 1;
    if(b == 1)
        return a;
    ll x = POW_MOD(a, b/2);
    if(b&1) return ((((x % mod) * (x % mod)) % mod) * (a % mod)) % mod;
    else return ((x % mod) * (x % mod)) % mod;
}

ll modInv(ll a){
    ll ans = POW_MOD(a, mod-2);
    return ans;
}

vector<ll> modFact(2e6+2);
void generateModFact(){
    modFact[0] = 1;
    for(int i=1; i<=2e6; i++){
        modFact[i] = ((modFact[i-1] % mod) * (i % mod)) % mod;
    }
}

ll mod_nCr(ll n, ll r){
	ll ans = modFact[n];
	ans %= mod;
	ans *= modInv(modFact[r]);
	ans %= mod;
	ans *= modInv(modFact[n-r]);
	ans %= mod;
	return ans;
}

int main(){
	
	generateModFact();

	int t = 1;
	cin>>t;
	for(int cs=1; cs<=t; cs++){
		ll n, k;
		cin>>n>>k;
		ll ans = mod_nCr(n, k);
		cout<< "Case " << cs << ": " << ans << '\n';
	}
}
