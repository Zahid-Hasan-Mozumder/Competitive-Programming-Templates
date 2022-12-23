vector<string> ss;
void generate_SubStrings(string s){
    int sz = s.size();
    while(true){
        if(sz <= 0) break;
        for(int i=0; i<=s.size()-sz; i++){
            ss.pb(s.substr(i, sz));
        }
        sz--;
    }
}
