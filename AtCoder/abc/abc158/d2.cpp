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
    cin >> s;
    int q;
    cin >> q;

    int rev = 0;
    vector<char> front, back;

    rep(i, q){
        int t;
        cin >> t;

        if(t==1) rev = 1 - rev;
        else{
            int f;
            char c;
            cin >> f >> c;

            if((f==1 && rev==0) || (f==2 && rev==1)) front.push_back(c);
            if((f==2 && rev==0) || (f==1 && rev==1)) back.push_back(c);
        }
    }

    if(rev==0){
        for(int i = front.size()-1; i >= 0; --i) cout << front[i];
        cout << s;
        rep(i, back.size()) cout << back[i];
    }
    else{
        reverse(s.begin(), s.end());

        for(int i = back.size()-1; i >= 0; --i) cout << back[i];
        cout << s;
        rep(i, front.size()) cout << front[i];
    }

    cout << endl;

    return 0;
}