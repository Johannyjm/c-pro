#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    float X;
    cin >> N >> X;

    vector<int> m(110);
    for(int i = 0; i < N; ++i) {
        cin >> m[i];
    }
    X -= accumulate(m.begin(), m.end());
    int res = N;

    res += X / min(m.begin(), m.end())

    cout << res << endl;


}