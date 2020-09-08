#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int l;
    cin >> l;
    vector<int> b(l);
    cin >> b[0];
    int xors = b[0];
    for(int i = 1; i < l; ++i){
        cin >> b[i];
        xors ^= b[i];
    }

    if(xors != 0){
        cout << -1 << endl;
        return 0;
    }

    cout << 0 << endl;
    int prev = 0;
    for(int i = 0; i < l-1; ++i){
        cout << (b[i]^prev) << endl;
        prev = b[i]^prev;
    }

    return 0;

}
