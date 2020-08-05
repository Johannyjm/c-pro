#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    for(int i = 0; i < n; ++i) cin >> b[i];
    long long sm_a = 0;
    long long sm_b = 0;
    for(int i = 0; i < n; ++i){
        if(a[i] < b[i]) sm_a -= b[i]-a[i];
        if(b[i] < a[i]) sm_b -= a[i]-b[i];
    }

    if(sm_a<=sm_b && 2*sm_b-sm_a>=0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;

}
