#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());
    for(auto e: a){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}
