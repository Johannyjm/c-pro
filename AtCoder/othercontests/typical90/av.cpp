#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    vector<ll> a(n), b(n);
    vector<ll> scores;

    for(int i = 0; i < n; ++i){
        cin >> a[i] >> b[i];

        scores.push_back(b[i]);
        scores.push_back(a[i] - b[i]);
    }

    sort(scores.begin(), scores.end(), greater<ll>());

    ll res = 0;
    for(int i = 0; i < k; ++i) res += scores[i];

    cout << res << endl;


    return 0;
}
