#include<bits/stdc++.h>

using namespace std;

#define ll long long int

ll CSOD(ll n){
	ll sum = 0;
	for(ll i=1; i*i<=n; i++){
		ll a = ((n / i) - (i - 1)) * i;
		ll b = ((n/i) * (n/i + 1) / 2) - (i * (i + 1) / 2);
		sum += (a + b);
	}
	return sum;
}

int main(){
	ll n; cin>>n;
	ll ans = CSOD(n);
	cout<< ans << '\n';
}
