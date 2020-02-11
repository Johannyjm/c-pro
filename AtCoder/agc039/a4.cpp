#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    int k;
    cin >> s >> k;

    ll over = 0;
    if(s.front() != s.back()){
        rep(i, s.size()-1){
            if(s[i]==s[i+1]){
                ++over;
                s[i+1] = '0';
            }
        }

        cout << over * k << endl;
    }

    else{
        ll front = s.size();
        ll back = s.size();
        rep(i, s.size()){
            if(s[i]!=s.back()){
                front = i;
                break;
            }
        }

        for(int i = s.size()-1; i >= 0; --i){
            if(s[i] != s.front()){
                back = s.size() - i - 1;
                break;
            }
        }

        //cout << front << " " << back << endl;

        if(front == s.size()){ // all same
            cout << k*s.size()/2 << endl;
        }

        else{
            // [front, back)
            ll res = 0;
            string tmp1 = s;
            rep(i, s.size()-back){
                if(tmp1[i]==tmp1[i+1]){
                    ++res;
                    tmp1[i+1] = '0';
                }
            }

            // [back+front, back]
            string tmp2 = s.substr(s.size()-back, back) + s.substr(0, s.size()-back);

            rep(i, tmp2.size()-1){
                if(tmp2[i]==tmp2[i+1]){
                    ++over;
                    tmp2[i+1] = '0';
                }
            }
            cout << res + over * (k-1) + back/2 << endl;
        }

    }


    return 0;
}