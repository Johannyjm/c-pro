#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    ll n, k;
    cin >> n >> k;

    ll numerator = 1;
    numerator += 6 * (k-1) * (n-k);
    numerator += 3 * (n-1);

    ll denominator = n*n*n;

    cout << setprecision(20);
    cout << (double) numerator / (double) denominator << endl;

    return 0;
}
