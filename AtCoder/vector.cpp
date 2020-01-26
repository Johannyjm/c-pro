#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> num;
    num.push_back(3);
    num.push_back(4);
    num.push_back(5);

    cout << num[num.size()-1] << endl;
    cout << num.back() << endl;
    cout << num.back() << endl;
    cout << num.front() << endl;

    return 0;
}