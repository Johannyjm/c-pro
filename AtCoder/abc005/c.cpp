#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t, n;
    cin >> t >> n;
    map<int, int> mp;
    rep(i, n) {
        int a;
        cin >> a;
        ++mp[a];
    }

    int m;
    cin >> m;
    rep(i, m){
        int b;
        cin >> b;
        int ptr = 0;
        bool fail = false;
        while(mp[b-t+ptr] == 0){
            if(ptr == t){
                fail = true;
                break;
            }
            ++ptr;
        }

        if(fail){
            puts("no");
            return 0;
        }
        
        --mp[b-t+ptr];
    }

    puts("yes");    

    return 0;
}