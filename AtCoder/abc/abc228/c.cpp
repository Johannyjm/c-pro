#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n; ++i){
        int a, b, c;
        cin >> a >> b >> c;
        p[i] = a + b + c;
    }
    
    vector<int> score = p;
    sort(score.begin(), score.end(), greater<int>());
    int target = score[k-1];

    for(int i = 0; i < n; ++i){
        if(p[i] + 300 >= target) puts("Yes");
        else puts("No");
    }

    return 0;
}
