#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    pair<pair<string, int>, int> p[n];
    for (int i = 0; i < n; ++i){
        string city;
        int score;
        cin >> city >> score;

        p[i] = make_pair(make_pair(city, -score), i);
    }
    sort(p, p+n);

    for (int i = 0; i < n; ++i) cout << p[i].second + 1 << endl;
}