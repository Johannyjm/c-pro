#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;

    int n = s.size();
    vector<vector<int>> shdc(4, vector<int>(5, 0)); // s, h, d, c -> 10, j, q, k, a;

    map<char, int> cnv;
    cnv['S'] = 1;
    cnv['H'] = 2;
    cnv['D'] = 3;
    cnv['C'] = 4;
    cnv['1'] = 1;
    cnv['J'] = 2;
    cnv['Q'] = 3;
    cnv['K'] = 4;
    cnv['A'] = 5;

    map<int, char> cnv2;
    cnv2[0] = 'S';
    cnv2[1] = 'H';
    cnv2[2] = 'D';
    cnv2[3] = 'C';

    int from = 0;
    int num = 2;
    if(s[2] == '0') ++num;
    int compm = 0;
    int to = 0;
    int num_cards = 0;

    for(int i = num; i < n; ++i){
        if((s[i] == 'S' || s[i] == 'H' || s[i] == 'D' || s[i] == 'C') || i == n-1){
            if(i == n-1) ++num;

            string card = s.substr(from, num);
            ++num_cards;
            // cout << card << endl;

            if(cnv[card[1]] > 0){
                ++shdc[cnv[card[0]]-1][cnv[card[1]]-1];

                bool comp = false;
                rep(j, 4){
                    int sm = 0;
                    rep(k, 5) sm += shdc[j][k];
                    if(sm == 5) {
                        comp = true;
                        compm = j;
                        to = from + num;
                        break;
                    }
                }
                if(comp) break;
            }

            from = i;
            num = 0;
        }
        ++num;

    }

    int ptr = 0;
    while(ptr < to){
        if(s[ptr] == cnv2[compm]) {
            if(s[ptr+1] == '1') ptr += 3;
            else ptr += 2;
        }
        else {
            cout << s[ptr] << s[ptr+1];
            if(s[ptr+1] == '1'){
                cout << s[ptr+2];
                ptr += 3;
            }
            else ptr += 2;
        }
    }
    
    // for(int i = to; i < n; ++i) cout << s[i];
    if(num_cards == 5) cout << 0 << endl;
    else cout << endl;

    return 0;
}