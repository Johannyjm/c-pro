#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int r, d, x;
    cin >> r >> d >> x;
    int current = x;

    for(int _ = 0; _ < 10; _++){
        int next = current*r - d;
        cout << next << endl;
        current = next;
    }
}