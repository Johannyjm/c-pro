#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];
    
    int r = 0;
    set<int> st;
    int res = 1;
    for(int l = 0; l < n; ++l){
        
        while(r < n){
            st.insert(a[r]);
            if(st.size() < r-l+1){
                res = max(res, (int)st.size());
                while(a[l] != a[r]){
                    st.erase(a[l]);
                    ++l;
                }
                ++l;
            }
            ++r;
        }
    }
    if(st.size() == n) cout << n << endl;
    else cout << res << endl;

    return 0;

}
