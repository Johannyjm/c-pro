#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    int n;
    cin >> n;
    
    set<pair<int, int>> st;
    for(int i = 0; i < n; ++i){
        int a, b;
        cin >> a >> b;

        if(a < b) swap(a, b);
        st.insert(make_pair(a, b));
    }

    cout << st.size() << endl;
}
