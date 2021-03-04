#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> b(n-1);
    for(int i = 0; i < n-1; ++i) cin >> b[i];

    int res = b.front() + b.back();
    for(int i = 0; i < n-2; ++i){
        res += min(b[i], b[i+1]);
    }

    cout << res << endl;

    return 0;
}