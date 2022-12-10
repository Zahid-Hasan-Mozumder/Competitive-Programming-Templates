ll GCD(ll a, ll b){
  ll temp;
  while(b){
    temp = a;
    a = b;
    b = temp % b;
  }
  return a;
}

ll LCM(ll a, ll b){
    return (a/GCD(a,b))*b;
}