#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> a(5);
    rep(i, 5) cin >> a[i];

    sort(a.begin(), a.end());
    set<int> st;
    do{
        st.insert(a[0]+a[1]+a[2]);
    }while(next_permutation(a.begin(), a.end()));

    auto itr = st.end();
    --itr;
    --itr;
    --itr;
    cout << *itr << endl;

    return 0;
}