#include <iostream>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, a, x, y;
    cin >> n >> a >> x >> y;

    // if(n <= a) cout << a * x << endl;
    // else cout << a*x + (n-a) * y << endl;
    
    if(n > a) cout << a * x + (n-a) * y;
    else cout << n * x;
    cout << endl;

    return 0;
}
