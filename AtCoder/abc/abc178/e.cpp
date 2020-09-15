#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> x(n), y(n);

    for(int i = 0; i < n; ++i){
        int xx, yy;
        cin >> xx >> yy;
        x[i] = xx + yy;
        y[i] = xx - yy;
    }

    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    cout << max(x.back()-x.front(), y.back()-y.front()) << endl;
    
    return 0;
}
