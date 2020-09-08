#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
typedef long long ll;

bool isnum(char c){
    return ('0' <= c && c <= '9');
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;

    vector<ll> orig(n, -1);
    map<int, vector<int>> same;
    for(int i = 0; i < n; ++i){
        if(isnum(s[i])) orig[i] = s[i] - '0';
        else same[s[i]].push_back(i);
        
        if(isnum(t[i])) orig[i] = t[i] - '0';
        else same[t[i]].push_back(i);
    }


    for(int i = 0; i < n; ++i){
        if(same[s[i]].size() > 1){
            int num = -1;
            for(auto elem: same[s[i]]){
                if(orig[elem] != -1) num = orig[elem];
            }

            if(num != -1){
                for(auto elem: same[s[i]]){
                    orig[elem] = num;
                }
            }
        }
    }

    ll res = 1;
    for(int i = 0; i < n; ++i){
        if(orig[i] == -1){
            if(i == 0) res *= 9;
            else res *= 10;

            for(auto elem: same[s[i]]){
                orig[elem] = -2;
            }
        }
    }


    cout << res << endl;

    return 0;
}
