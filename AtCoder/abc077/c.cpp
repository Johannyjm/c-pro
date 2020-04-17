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

    vector<int> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());

    vector<int> top_idx(n);
    vector<int> mid_idx(n);
    rep(i, n){
        int top = a[i];
        int l = 0;
        int r = n-1;

        if(b[l] > top) top_idx[i] = l;
        else if(b[r] < top) top_idx[i] = -1;
        else{
            int m;
            while(1){
                m = (l + r) / 2;

                if(b[m] > top) {
                    r = m;
                    if(abs(r-l) <= 1){
                        top_idx[i] = m;
                        break;
                    }
                }
                else {
                    l = m;
                    if(abs(r-l) <= 1){
                        top_idx[i] = m+1;
                        break;
                    }
                }
            }
        }

        int mid = b[i];
        l = 0;
        r = n-1;

        if(c[l] > mid) mid_idx[i] = l;
        else if(c[r] < mid) mid_idx[i] = -1;
        else{
            int m;
            while(1){
                m = (l + r) / 2;

                if(c[m] > mid) {
                    r = m;
                    if(abs(r-l) <= 1){
                        mid_idx[i] = m;
                        break;
                    }
                }
                else {
                    l = m;
                    if(abs(r-l) <= 1){
                        mid_idx[i] = m+1;
                        break;
                    }
                }
            }
        }
    }

    // rep(i, n) cout << top_idx[i] << " " << mid_idx[i] << endl;
    // cout << endl;

    vector<ll> mid_num(n);
    if(mid_idx[n-1] == -1) mid_num[n-1] = 0;
    else mid_num[n-1] = n - mid_idx[n-1];
    for(int i = n-2; i >= 0; --i){
        mid_num[i] = mid_num[i+1];
        if(mid_idx[i] != -1){
            mid_num[i] += n - mid_idx[i];
        }
    }

    // rep(i, n) cout << mid_num[i] << " ";
    // cout << endl;

    vector<ll> top_num(n);
    if(top_idx[n-1] == -1) top_num[n-1] = 0;
    else top_num[n-1] = mid_num[top_idx[n-1]];
    for(int i = n-2; i >= 0; --i){
        top_num[i] = top_num[i+1];
        if(top_idx[i] != -1){
            top_num[i] += mid_num[top_idx[i]];
        }
    }

    // rep(i, n) cout << top_num[i] << " ";
    // cout << endl;


    cout << top_num[0] << endl;

    return 0;
}