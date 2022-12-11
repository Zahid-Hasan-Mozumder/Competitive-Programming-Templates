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

vector<pair<int, int>> primeFact;
void pff(int n){
      for(int i=0; i<primes.size(); i++){
            int cnt = 0;
            int curr = primes[i];
            while(curr <= n){
                cnt += (n / curr);
                curr *= primes[i];
                if(curr > n) primeFact.pb({primes[i], cnt});
         	}
      }
}