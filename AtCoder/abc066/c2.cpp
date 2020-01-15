#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    vector<int> A(n);
    cin >> A[n/2];
    int ptr = n/2;
    int minus;
    
    if(n%2) minus = 1;
    else minus = -1;
    rep1(i, n){
        int a;
        cin >> a;
        ptr += i * minus;
        minus *= -1;
        A[ptr] = a;
    }

    rep(i, n) cout << A[i] << " ";
    cout << endl;
    

}