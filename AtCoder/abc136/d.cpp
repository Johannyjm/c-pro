#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    s = s + 'R';

    vector<int> pos;
    int r = 0;
    int l = 0;
    char prev = 'R';
    rep(i, s.size()){
        
        if(s[i] == 'R'){
            if(prev == 'R') ++r;
            else{
                pos.push_back(r-1);
                pos.push_back(-1);
                pos.push_back(l-1);
                prev = 'R';
                r = 1;
                l = 0;
            }
        }
        else ++l;

        prev = s[i];

    }
    for (auto ele: pos){
        cout << ele;
    }
    cout << endl;

    int le = 0;
    int ri = 0;
    bool flg = false;
    for(int p: pos){
        if(p != -1){
            if(flg) {
                ri = p;
                rep(i, le) cout << 0 << " ";
                cout << 1 + le/2 + (ri+1)/2 << " ";
                cout << 1 + (le+1)/2 + ri/2 << " ";
                rep(i, ri) cout << 0 << " ";

                le = 0;
                ri = 0;
                flg = false;
            }
            else le = p;
        }
        else flg = true;
        
    }
    cout << endl;
}