#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> a(n);
    rep(i, n) cin >> a[i];

    set<int> st;
    for(int elem: a){
        while(elem%2==0){
            elem /= 2;
        }
        st.insert(elem);
    }

    cout << st.size() << endl;

    return 0;
}