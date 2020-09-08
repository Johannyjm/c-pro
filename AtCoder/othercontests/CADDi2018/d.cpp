#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    int mx_idx = 0;
    int mx_val = 0;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        if(a[i] > mx_val){
            mx_idx = i;
            mx_val = a[i];
        }
    }

    if(mx_val%2 == 1){
        cout << "first" << endl;
        return 0;
    }

    long long othersm = 0;
    for(int i = 0; i < n; ++i){
        if(i == mx_idx) continue;
        othersm += a[i];
    }

    if(othersm%2 == 0) cout << "second" << endl;
    else cout << "first" << endl;

    return 0;
}
