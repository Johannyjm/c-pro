#include <iostream>
#include <vector>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n = 10;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    cout << a[a[a[0]]] << endl;

    return 0;
}
