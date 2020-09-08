#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    set<int> st;

    st.insert(1);
    st.insert(5);
    st.insert(2);
    st.insert(3);
    st.insert(5);

    for(auto ele: st){
        cout << ele << endl;
    }
    
    cout << endl;
    cout << st.size() << endl;
    
    cout << binary_search(st.begin(), st.end(), 2) << endl;

    set<pair<int, int>> stp;
    pair<int, int> pa = make_pair(1, 2);
    pair<int, int> pa2 = make_pair(3, 4);
    
    stp.insert(pa);
    stp.insert(pa2);

    cout << binary_search(stp.begin(), stp.end(), make_pair(1, 2)) << endl;
    cout << binary_search(stp.begin(), stp.end(), make_pair(2, 2)) << endl;


    cout << endl << endl;

    unordered_set<int> ust;

    ust.insert(2);
    ust.insert(3);
    ust.insert(5);
    ust.insert(2);

    cout << ust.count(1) << endl;
    cout << ust.count(2) << endl;
    cout << ust.count(5) << endl;
    

    return 0;
}