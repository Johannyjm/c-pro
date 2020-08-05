#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; ++i) cin >> s[i];
    
    sort(s.begin(), s.end(), greater<int>());
    while(s.back() == 0) s.pop_back();
    n = s.size();

    int q;
    cin >> q;
    for(int i = 0; i < q; ++i){
        int k;
        cin >> k;
        if(k == n) cout << 0 << endl;
        else cout << s[k]+1 << endl;
    }    


    return 0;

}
