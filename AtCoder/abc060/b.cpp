#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b, c;
    cin >> a >> b >> c;

    int amul = a + a;
    int bmod = a%b;

    if(a%b==c || amul%b==c){
        puts("YES");
        return 0;
    }

    while(amul%b != bmod){
        amul += a;
        if(amul%b == c){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}