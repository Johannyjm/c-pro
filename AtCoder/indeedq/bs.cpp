#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; ++i) cin >> s[i];

    int idx = lower_bound(s.begin(), s.end(), 7) - s.begin();
    cout << idx << " " << s[idx] << endl;

    return 0;
}
