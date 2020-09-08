#include <bits/stdc++.h>
using namespace std;
int res = 0;

int grand_garden(int h[], int n){
    int min_h = 101;
    int min_h_idx = -1;

    if(n<2) return h[0];

    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if(h[i] < min_h) {
            min_h = h[i];
            min_h_idx = i;
        }
    }
    res += min_h;
    return 
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    int h[n];
    int min_h = 101;
    int min_h_idx = -1;
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
        if(h[i] < min_h) {
            min_h = h[i];
            min_h_idx = i;
        }
    }


}