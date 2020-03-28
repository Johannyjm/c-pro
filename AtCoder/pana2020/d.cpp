#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int n;

void print_std(string res, char max_char, int num){
    
    if(num == n){
        for(char c = 'a'; c <= max_char+1; ++c){
            cout << res + c << endl;
        }
    }

    else {
        for(char c = 'a'; c <= max_char+1; ++c){
            print_std(res+c, max(max_char, c), num+1);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    if(n==1){
        puts("a");
        return 0;
    }
    --n;

    char max_char = 'a';
    print_std("a", max_char, 1);

    return 0;
}