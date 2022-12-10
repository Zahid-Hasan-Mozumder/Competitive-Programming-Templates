vector<vector<ll>> pascalNum(1e3+2, vector<ll>(1e3+2, 0));
void generatePascalNum(){
    for(int i=0; i<=1e3; i++){
        for(int j=0; j<=1e3; j++){
            if(i==j){
                pascalNum[i][j] = 1;
                break;
            }
            if(j == 0) pascalNum[i][j] = 1;
            else pascalNum[i][j] = pascalNum[i-1][j] + pascalNum[i-1][j-1];
        }
    }
}
ll _nCr(ll a, ll b){
    return pascalNum[a][b];
}