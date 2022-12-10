int CEIL(int a, int b){
    if(a < 0 && b > 0){
        return 1; 
    }
    return ((a + b - 1) / b);
}