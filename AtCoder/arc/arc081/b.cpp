#include <iostream>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s, _;
    cin >> s >> _;

    if(s.size() == 1){
        cout << 3 << endl;
        return 0;
    }

    vector<int> ord; // 0: vertical, 1: hirizontal
    for(int i = 0; i < s.size()-1; ++i){
        if(s[i] != s[i+1]){
            ord.push_back(0);
            if(i+1 == s.size()-1) ord.push_back(0);
        }
        else{
            ord.push_back(1);
            ++i;
        }
    }
    if(s[s.size()-2] != s.back()) ord.push_back(0);
    for(int i = 0; i < ord.size(); ++i) cout << ord[i] << " ";
    cout << endl;

    ll res;
    if(ord[0]==0) res = 3;
    else res = 6;
    int prev = ord[0];
    for(int i = 1; i < ord.size(); ++i){
        if(prev==0 && ord[i]==0) res = res*2 % mod;
        if(prev==1 && ord[i]==1) res = res*6 % mod;
        if(prev==0 && ord[i]==1) res = res*2 % mod;
        prev = ord[i];
    }

    cout << res << endl;

    return 0;
}
