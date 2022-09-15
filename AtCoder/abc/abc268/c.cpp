#include <iostream>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> p(n), indices(n);
    for(int i = 0; i < n; ++i){
        cin >> p[i];
        indices[p[i]] = i;
    }

    vector<int> cnt(n, 0);


    return 0;
}
