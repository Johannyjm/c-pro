#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    if(n == 1){
        cout << 0 << endl;
        return 0;
    }

    int cnt = 0;
    for(int i = 0; i < n/2; ++i){
        if(s[i] != s[n-i-1]) ++cnt;
    }

    if(cnt==0 && n%2==1) cout << 25*(n-1) << endl;
    else if(cnt==1) cout << 25*n - 2 << endl;
    else cout << 25*n << endl;

    return 0;
}
