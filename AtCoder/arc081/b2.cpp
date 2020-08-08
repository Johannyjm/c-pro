#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    if(n == 1){
        cout << 3 << endl;
        return 0;
    }

    vector<int> mode; // 0: vertical, 1: horizontal
    for(int i = 0; i < s.size()-1; ++i){
        if(s[i] == s[i+1]){
            mode.push_back(1);
            ++i;
            if(i == s.size()-2) mode.push_back(0);
        }
        else{
            mode.push_back(0);
            if(i == s.size()-2) mode.push_back(0);
        }
    }

    ll res = (mode[0]==0)? 3: 6;
    ll prev = mode[0];
    for(int i = 1; i < mode.size(); ++i){
        ll curr = mode[i];
        
        if(prev==0 && curr==0) res = res*2 % mod;
        if(prev==0 && curr==1) res = res*2 % mod;
        if(prev==1 && curr==0) res = res*1 % mod;
        if(prev==1 && curr==1) res = res*3 % mod;
        
        prev = curr;
    }

    cout << res << endl;

    return 0;
}
