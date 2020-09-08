#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<string> s(5);
    rep(i, 5) cin >> s[i];

    string res = "";
    int LEN = 4;
    rep(i, n){
        int start = i * LEN;
        int end = start + LEN;

        if(s[2].substr(start, 4) == ".#.#"){
            res += '0';
        }
        else if(s[1].substr(start, 4) == ".##."){
            res += '1';
        }
        else if(s[1].substr(start, 4) == "...#"){
            if(s[2].substr(start, 4) == ".###"){
                if(s[3].substr(start, 4) == ".#..") res += '2';
                else res += '3';
            }
            else res += '7';
        }
        else if(s[1].substr(start, 4) == ".#.#"){
            if(s[4].substr(start, 4) == "...#") res += '4';
            else{
                if(s[3].substr(start, 4) == ".#.#") res += '8';
                else res += '9';
            }
        }

        else{
            if(s[3].substr(start, 4) == "...#") res += '5';
            else res += '6';
        }

    }

    cout << res << endl;

    return 0;
}