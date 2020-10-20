#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);



    

    vector<int> num;
    // num.push_back(3);
    // num.push_back(4);
    // num.push_back(5);

    // cout << num[num.size()-1] << endl;
    // cout << num.back() << endl;
    // cout << num.back() << endl;
    // cout << num.front() << endl;

    num = {2, 5, 8, 13, 78, 534, 2, 46, 8, 56, 3, 5, 5, 5};
    int n = num.size();
    sort(num.begin(), num.end());

    rep(i, n) cout << num[i] << " ";
    cout << endl;

    cout << upper_bound(num.begin(), num.end(), 3) - num.begin() << endl;

    // reverse(num.begin(), num.end());
    rep(i, n) cout << num[i] << " ";
    cout << endl;
    cout << lower_bound(num.begin(), num.end(), 3) - num.begin() << endl;

    rep(i, n) cout << num[i] << " ";
    // cout << endl;
    // cout << upper_bound(num.begin(), num.end(), 2) - num.begin() << endl;
    // cout << lower_bound(num.begin(), num.end(), 2) - num.begin() << endl;
    cout << endl << endl;
    vector<int> a = {1, 2,  3, 5};
    cout << upper_bound(a.begin(), a.end(), 2) - a.begin() << endl;
    cout << lower_bound(a.begin(), a.end(), 2) - a.begin() << endl;
    
    // cout << lower_bound(num.begin(), num.end(), 2) - num.begin() << endl;
    // cout << num.end() - lower_bound(num.begin(), num.end(), 2) << endl;
    // cout << upper_bound(num.begin(), num.end(), 2) - num.begin() << endl;
    // cout << num.end() - upper_bound(num.begin(), num.end(), 2) << endl;
    

    return 0;
}