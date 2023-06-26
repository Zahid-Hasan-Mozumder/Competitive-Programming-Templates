bool is_pow_of_2(int x){
    if(x == 0) return false;
    if(x & (x - 1)) return false;
    else return true;
}
