#include <iostream>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, x, y, z;
    cin >> n >> x >> y >> z;

    int res = 0;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        if(x <= a && y <= b && z <= a+b) ++res;
    }

    cout << res << endl;

    return 0;
}
