#include <iostream>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    long long res = 0;
    for(int i = 0; i < n; ++i){
        long long a, b;
	cin >> a >> b;

	res += min(a/2, b);
    }

    cout << res << endl;

    return 0;
}
