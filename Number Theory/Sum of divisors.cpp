#define ll long long int
#define pb push_back

const int sz = 1e6+2;
vector<bool> mark(sz, 0);

vector<int> primes;
void SEIVE(){
    mark[0] = 1;
    mark[1] = 1;
    for(int i=4; i<sz; i+=2)
        mark[i] = 1;
    for(int i=3; i*i<sz; i+=2){
        if(!mark[i]){
            for(int j=i*i; j<sz; j+=(i*2)){
                mark[j] = 1;
            }
        }
    }
    primes.pb(2);
    for(int i=3; i<sz; i+=2){
        if(!mark[i])
            primes.pb(i);
    }
}

ll SOD(ll n){
    ll sum = 1;
    for(int i=0; i<primes.size() && primes[i]*primes[i]<=n; i++){
        ll curr = 1;
        if(n % primes[i] == 0){
            while(n % primes[i] == 0){
                curr *= primes[i];
                n /= primes[i];
            }
            curr *= primes[i];
            if(curr > 1) sum *= (curr - 1) / (primes[i] - 1);
        }
        if(n == 1) break;
    }
    if(n > 1) sum *= (1+n);
    return sum;
}
