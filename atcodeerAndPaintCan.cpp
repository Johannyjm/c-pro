#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int can;
    set<int> pcan;

    for (int i = 0; i < 3; ++i){
        cin >> can;
        pcan.insert(can);
    }
    cout << pcan.size() << endl;

}