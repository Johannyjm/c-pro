#include <iostream>
#include <cmath>
#include <unordered_set>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long n, k;
    cin >> n >> k;

    long long base = k;
    if(k%2==0) base /= 2;

    unordered_set<int> use;
    while(base <= n){
        use.insert(base);
        base += k;
    }
    
    int res = pow(use.size(), 3);
    for(int i = 1; i <= n; ++i){
        if(use.find(i) != use.end()) continue;
        if(2*i % k == 0) ++res;
    }

    cout << res << endl;

}
