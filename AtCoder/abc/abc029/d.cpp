#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string s;
    cin >> s;
    
    int n = s.size();
    vector<int> dp(n, 0);
    int smaller;
    int ones = 0;
    if(s[0] == '1'){
        smaller = 0;
        ++ones;
    }
    else smaller = 1;
    
    int now = s[0] - '0';
    for(int i = 1; i < n; ++i){
        int d = s[i] - '0';
        if(d == 1) ++ones;
        
        smaller = smaller * 10 + now;
        if(ones > 0) smaller += d * (ones-(d==1)) + (d > 1);
        else smaller += (d > 1);

        now *= 10;
        now += d;

    }

    cout << smaller + ones << endl;

    return 0;
}
