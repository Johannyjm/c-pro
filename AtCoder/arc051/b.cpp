#include <iostream>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int k;
    cin >> k;

    int a = 1;
    int b = 1;
    for(int i = 0; i < k; ++i){
        int tmp = a + b;
        b = a;
        a = tmp;
    }

    cout << a << " " << b << endl;
}
