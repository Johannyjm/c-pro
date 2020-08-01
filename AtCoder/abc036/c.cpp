#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<pair<int, int>> ai(n);
    for(int i = 0; i < n; ++i){
        int a;
        cin >> a;
        ai[i] = make_pair(a, i);
    }

    sort(ai.begin(), ai.end());

    vector<int> b(n);
    int ptr = 0;
    b[ai[0].second] = ptr;
    int prev = ai[0].first;
    for(int i = 1; i < n; ++i){
        if(ai[i].first != prev) ++ptr;

        b[ai[i].second] = ptr;
        prev = ai[i].first;
    }

    for(int i = 0; i < n; ++i) cout << b[i] << endl;
}
