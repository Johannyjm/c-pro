#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, q;
    cin >> n >> q;

    vector<int> sm(n+1, 0);
    for(int i = 0; i < q; ++i){
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        
        ++sm[l];
        --sm[r+1];
    }

    for(int i = 0; i < n; ++i) sm[i+1] += sm[i];

    for(int i = 0; i < n; ++i){
        if(sm[i]%2 == 1) cout << 1;
        else cout << 0;
    }
    cout << endl;

    return 0;
}  
