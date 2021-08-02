#include <iostream>
#include <iomanip>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    double a, b;
    cin >> a >> b;

    cout << setprecision(20);
    cout << (a-b)/3 + b << endl;

    return 0;
}
