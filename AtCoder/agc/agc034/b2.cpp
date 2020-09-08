#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<char> c;
int rec(int idx){
    int ret = 1;
    //left
    if(idx!=0 && c[idx-1] == 'A'){
        ret += rec(idx-1);
    }
    //right
    if(idx+4 < n && c[idx+3]=='B' && c[idx+4]=='C'){
        ret += rec(idx+2);
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    n = s.size();
    c.resize(n);
    for(int i = 0; i < n; ++i) c[i] = s[i];

    int res = 0;
    for(int i = 0; i < n-2; ++i){
        if(c[i]=='A' && c[i+1]=='B' && c[i+2]=='C') res += rec(i);
    }

    cout << res << endl;

    return 0;
}
