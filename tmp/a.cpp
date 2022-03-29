#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    set<vector<int>> st;
    for(int i = 0; i < n; ++i){
        int l;
        cin >> l;
        vector<int> a(l);
        for(int j = 0; j < l; ++j) cin >> a[j];

        st.insert(a);
    }

    cout << (int)st.size() << endl;

    return 0;
}
