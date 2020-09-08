#include <iostream>
#include <vector>
using namespace std;

vector<int> d;
bool is_ok(int money){
    while(money){
        for(int elem: d){
            if(money % 10 == elem) return false;
        }
        money /= 10;
    }

    return true;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    d.resize(k);
    for(int i = 0; i < k; ++i) cin >> d[i];
    
    int money = n;
    while(1){
        if(is_ok(money)){
            cout << money << endl;
            return 0;
        }

        ++money;
    }

    return 0;
}

