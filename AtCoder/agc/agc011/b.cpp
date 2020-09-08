#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    sort(a.begin(), a.end());

    ll sm = a[0];
    int border = 0;
    for(int i = 1; i < n; ++i){
        if(sm*2 < a[i]) border = i;

        sm += a[i];
    }

    cout << n - border << endl;

    return 0;
}
