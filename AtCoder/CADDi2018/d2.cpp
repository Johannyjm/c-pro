#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    int a;
    for(int i = 0; i < n; ++i){
        cin >> a;
        if(a%2 == 1){
            cout << "first" << endl;
            return 0;
        }
    }
    cout << "second" << endl;

    return 0;
}
