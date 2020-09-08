#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int a, b;
    cin >> a >> b;
    int add = 0;
    int num = 1;

    do {
        add += num;
        ++num;
    } while (num < b-a);

    cout << add - a << endl;

}