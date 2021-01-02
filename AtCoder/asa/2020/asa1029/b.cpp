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

    vector<int> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];

    int den = 1;
    rep1(i, n+1) den *= i;

    double num = 0;
    vector<int> order;
    rep(i, n) order.push_back(i);
    double xf, yf, xt, yt;
    do{
       double sm = 0;
       xf = x[order[0]];
       yf = y[order[0]];
       rep1(i, n){
           xt = x[order[i]];
           yt = y[order[i]];
           double d2 = (xf-xt)*(xf-xt) + (yf-yt)*(yf-yt);
           sm += pow(d2, 0.5);
       }

       num += sm;

       xf = xt;
       yf = yt;
    } while(next_permutation(order.begin(), order.end()));

    cout << setprecision(20);
    cout << num / (double)den << endl;

    return 0;
}