#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    if(n==1){
        if(s!="8") puts("No");
        else puts("Yes");
        return 0;
    }
    if(n==2){
        int num = (s[0]-'0')*10 + (s[1]-'0');
        int num2 = (s[1]-'0')*10 + (s[0]-'0');
        if(num%8 == 0 || num2%8 == 0) puts("Yes");
        else puts("No");
        return 0;
    }

    vector<int> cnt(10, 0);
    rep(i, n){
        ++cnt[s[i] - '0'];
    }
    // cnt[0] += max(0, 3-n);

    for(int i = 8; i < 1000; i += 8){
        int one = i%10;
        int two = i/10%10;
        int three = i/100;
        // cout << one << " " << two << " " << three << endl;
        vector<int> cnt2(10, 0);
        cnt2[one]++;
        cnt2[two]++;
        cnt2[three]++;

        if(cnt[one]>=cnt2[one] && cnt[two]>=cnt2[two] && cnt[three]>=cnt2[three]){
            puts("Yes");
            return 0;
        }
    }

    puts("No");

    return 0;
}