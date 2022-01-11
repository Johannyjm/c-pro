#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x;
    cin >> n >> x;
    --x;

    vector<int> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        --a[i];
    }

    vector<bool> seen(n, false);
    int res = 0;
    int now = x;

    while(!seen[now]){
        ++res;
        seen[now] = true;
        now = a[now];
    }

    cout << res << endl;

    return 0;
}
