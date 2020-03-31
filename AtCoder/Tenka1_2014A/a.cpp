#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

string num2string(int n){
    string ret = "";

    while(n){
        char d = '0' + n%10;
        ret = d + ret;
        n /= 10;
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 1000;
    set<string> num;
    rep1(i, n+1){
        num.insert(num2string(i));
    }

    for(auto number: num){
        cout << number << endl;
    }

}