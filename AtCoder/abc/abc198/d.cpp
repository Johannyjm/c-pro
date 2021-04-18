#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    set<char> use;
    map<char, int> digits;
    for(char c: s1) use.insert(c);
    for(char c: s2) use.insert(c);
    for(char c: s3) use.insert(c);

    if(use.size() > 10){
        puts("UNSOLVABLE");
        return 0;
    }

//    for(auto v: digits) cout << v << " ";
//    cout << endl;

    vector<int> order;
    rep(i, 10) order.push_back(i);
        
    do{
        int ptr = 0;
        for(auto d: use){
            digits[d] = order[ptr];
            ++ptr;
        }

        if(digits[s1.front()] == 0) continue;
        if(digits[s2.front()] == 0) continue;
        if(digits[s3.front()] == 0) continue;


        ll n1 = 0;
        for(auto c: s1){
            n1 *= 10;
            n1 += digits[c];
        }
        ll n2 = 0;
        for(auto c: s2){
            n2 *= 10;
            n2 += digits[c];
        }
        ll n3 = 0;
        for(auto c: s3){
            n3 *= 10;
            n3 += digits[c];
        }

        if(n1 + n2 == n3){
            cout << n1 << "\n" << n2 << "\n" << n3 << endl;
            return 0;
        }

    } while(next_permutation(order.begin(), order.end()));

    puts("UNSOLVABLE");

    return 0;
}