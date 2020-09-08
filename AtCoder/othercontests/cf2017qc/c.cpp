#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool isp(string s){
    int n = s.size();
    if(n == 1) return true;
    for(int i = 0; i < (n+1)/2; ++i){
        if(s[i] != s[n-1-i]) return false;
    }
    return true;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    string ex_x = "";
    for(int i = 0; i < n; ++i){
        if(s[i] == 'x') continue;
        ex_x += s[i];
    }

    if(!isp(ex_x)){
        cout << -1 << endl;
        return 0;
    }

    int m = ex_x.size();
    vector<int> num_x(m+1, 0);
    int ptr = 0;
    for(int i = 0; i < m; ++i){
        int num = 0;
        while(s[ptr] != ex_x[i]){
            ++num;
            ++ptr;
        }
        num_x[i] = num;
        ++ptr;
    }
    
    ptr = n-1;
    int num = 0;
    while(s[ptr] != ex_x[m-1]){
        ++num;
        --ptr;
    }
    num_x[m] = num;
    
    int res = 0;
    for(int i = 0; i < (m+1)/2; ++i){
        res += abs(num_x[i] - num_x[m-i]);
    }

    cout << res << endl;

    return 0;

}
