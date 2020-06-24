#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<pair<int, int>> vp;
    vp.push_back(make_pair(0, 1));
    vp.push_back(make_pair(2, 3));
    vp.push_back(make_pair(4, 5));

    rep(i, vp.size()) cout << i << ": " << vp[i].first << " " << vp[i].second << endl;

    vp.pop_back();

    rep(i, vp.size()) cout << i << ": " << vp[i].first << " " << vp[i].second << endl;


    

    vector<int> num;
    // num.push_back(3);
    // num.push_back(4);
    // num.push_back(5);

    // cout << num[num.size()-1] << endl;
    // cout << num.back() << endl;
    // cout << num.back() << endl;
    // cout << num.front() << endl;

    num = {1, 2, 1, 5, 8, 13, 78, 534, 2, 46, 8, 56, 3, 5, 5, 5, 5, 5, 5, 5, 5};
    sort(num.begin(), num.end());

    rep(i, num.size()) cout << num[i] << " ";
    cout << endl;

    cout << upper_bound(num.begin(), num.end(), 8) - num.begin() << endl;

    // reverse(num.begin(), num.end());
    rep(i, num.size()) cout << num[i] << " ";
    cout << endl;
    cout << lower_bound(num.begin(), num.end(), 8) - num.begin() << endl;

    // cout << lower_bound(num.begin(), num.end(), 2) - num.begin() << endl;
    // cout << num.end() - lower_bound(num.begin(), num.end(), 2) << endl;
    // cout << upper_bound(num.begin(), num.end(), 2) - num.begin() << endl;
    // cout << num.end() - upper_bound(num.begin(), num.end(), 2) << endl;
    

    return 0;
}