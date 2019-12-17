#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n, l;
    cin >> n >> l;

    int min = 1e9;
    int eat;
    int sum = 0;
    for (int i = 0; i < n; ++i){
        int score = l + i;
        if(abs(score) < min){
            min = abs(score);
            eat = score;
        }
        sum += score;
    }
    cout << sum - eat << endl;
}