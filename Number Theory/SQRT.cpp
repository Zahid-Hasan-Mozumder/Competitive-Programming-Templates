int SQRT(int x){
    int ans = sqrt(x) + 2;
    while(ans * ans > x)
        ans--;
    return ans;
}