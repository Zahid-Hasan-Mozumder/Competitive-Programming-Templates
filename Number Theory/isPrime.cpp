bool isPrime(ll n){
    if(n == 1)
        return true;

    for(ll i=2; i*i<=n; i++)
    {
        if(n%i == 0)
            return false;
    }
    return true;
}