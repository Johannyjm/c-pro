#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int mx = 0;
    int cnt[26] = {};
    for(auto c: s){
        ++cnt[c - 'a'];
        mx = max(mx, cnt[c - 'a']);
    }

    int other = s.size() - mx;

    if(other >= (mx-1) * 2) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}
