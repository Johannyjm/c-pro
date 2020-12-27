#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<int> a = {1, 1, 2, 3, 4, 5, 6};

    set<int> st;
    do{
        if(a.back() %2 == 0) continue;
        int base = 6;
        int n = 0;
        int ptr = 0;
        while(base!=-1){
            n += a[ptr] * pow(10, base);
            ++ptr;
            --base;
        }
        cout << n << " ";
        st.insert(n);
    } while(next_permutation(a.begin(), a.end()));

    cout << st.size() << endl;

    return 0;
}