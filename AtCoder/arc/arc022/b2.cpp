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

    int l = 0;
    int res = 0;
    set<int> st;
    for(int r = 0; r < n; ++r){
        st.insert(a[r]);
        if(st.size() < r-l+1){
            while(a[l] !=a [r]){
                st.erase(a[l]);
                ++l;
            }
            ++l;
        }
        res = max(res, (int)st.size());
    }

    cout << res << endl;

    return 0;
}
