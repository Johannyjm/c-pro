#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    vector<char> av, bv;
    for(int i = 0; i < a.size(); ++i){
        av.push_back(a[i]);
        bv.push_back(b[i]);
    }

    for(int i = 0; i < a.size(); ++i){
        cout << a[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < b.size(); ++i) cout << b[i] << " ";
    cout << endl;

    swap(a[0], a[3]);
    for(int i = 0; i < a.size(); ++i) cout << a[i] << " ";
    cout << endl;
    swap(a[0], a[3]);
    for(int i = 0; i < a.size(); ++i) cout << a[i] << " ";
    cout << endl;

}
