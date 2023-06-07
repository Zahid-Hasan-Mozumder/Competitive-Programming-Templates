int createPalindrome(int input, int b, bool isOdd){
    int n = input;
    int palin = input;
    if (isOdd) n /= b;
    while(n > 0){
        palin = palin * b + (n % b);
        n /= b;
    }
    return palin;
}
 
vector<int> p;
void generatePalindromes(int n){
    int number;
    for (int j = 0; j < 2; j++){
        int i = 1;
        while ((number = createPalindrome(i, 10, j % 2)) < n){
            p.push_back(number);
            i++;
        }
    }
    p.push_back(0);
    sort(p.begin(), p.end());
}
