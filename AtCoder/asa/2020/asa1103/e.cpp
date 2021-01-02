#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n = s1.size();

    vector<int> cnt1(26, 0), cnt2(26, 0), cnt3(26, 0);
    rep(i, n){
        ++cnt1[s1[i]-'A'];
        ++cnt2[s2[i]-'A'];
        ++cnt3[s3[i]-'A'];
    }


    // for(auto e: cnt1) cout << e << " ";
    // cout << endl;
    // for(auto e: cnt2) cout << e << " ";
    // cout << endl;
    // for(auto e: cnt3) cout << e << " ";
    // cout << endl;

    int use1 = 0;
    int use2 = 0;
    rep(i, 26){
        if(cnt3[i] == 0) continue;
        if(cnt1[i]+cnt2[i] < cnt3[i]){
            puts("NO");
            return 0;
        }

        if(cnt1[i]+cnt2[i] == cnt3[i]){
            use1 += cnt1[i];
            use2 += cnt2[i];
            cnt1[i] = 0;
            cnt2[i] = 0;
            cnt3[i] = 0;
        }

        if(cnt1[i]+cnt2[i] > cnt3[i]){
            int tmp1 = max(0, cnt3[i] - cnt2[i]);
            int tmp2 = max(0, cnt3[i] - cnt1[i]);
            use1 += tmp1;
            use2 += tmp2;
            cnt1[i] -= tmp1;
            cnt2[i] -= tmp2;
            cnt3[i] -= tmp1+tmp2;
        }
    }

    // cout << endl;
    // cout << use1 << " " << use2 << endl;
    // for(auto e: cnt1) cout << e << " ";
    // cout << endl;
    // for(auto e: cnt2) cout << e << " ";
    // cout << endl;
    // for(auto e: cnt3) cout << e << " ";
    // cout << endl;

    if(use1 <= n/2 && use2 <= n/2) puts("YES");
    else puts("NO");

    return 0;
}