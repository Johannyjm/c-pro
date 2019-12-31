#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int bucket[1000] = {0};

    rep(i, n){
        int a;
        cin >> a;
        ++bucket[a-1];
    }

    bool mostflg = false;

    for(int i = 999; i >= 0; --i){
        if(bucket[i]){
            if(mostflg){
                cout << i+1 << endl;
                return 0;
            }
            else mostflg = true;
        }
    }
}