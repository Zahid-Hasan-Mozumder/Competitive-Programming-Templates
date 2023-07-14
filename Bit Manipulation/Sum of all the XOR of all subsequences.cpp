int xorSum(vi &a, int n){
    int orr = 0;
    for (int i = 0; i < n; i++) orr |= arr[i];
    int ans = orr * pow(2, n-1);
    return ans;
}
