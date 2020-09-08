#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;
char words[] = {'a', 'b', 'c'};

void output_bf(int n, string pass){
    if(n == 1){
        cout << pass << endl;
    }
    else{
        rep(i, 3) {
            output_bf(n-1, pass + words[i]);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    output_bf(n+1, "");


    return 0;
}