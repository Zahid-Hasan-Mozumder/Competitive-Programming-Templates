string longDivision(string dividend, lli divisor){
    string result;
    lli carry = 0;
    for(int i=0; i<dividend.size(); i++){
        lli curr = carry * 10 + (dividend[i] - '0');
        result.push_back('0' + (curr / divisor));
        carry = curr % divisor;
    }
    string ans;
    int pos = -1;
    for(int i=0; i<result.size(); i++){
        if(result[i] != '0'){
            pos = i;
            break;
        }
    }
    for(int i=pos; i<result.size(); i++){
        ans.push_back(result[i]);
    }
    return ans;
}