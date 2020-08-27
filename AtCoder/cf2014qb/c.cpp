#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    int n = s1.size() / 2;

    vector<int> cnt1(26, 0), cnt2(26, 0), cnt3(26, 0);
    for(int i = 0; i < 2*n; ++i){
        ++cnt1[s1[i] - 'A'];
        ++cnt2[s2[i] - 'A'];
        ++cnt3[s3[i] - 'A'];
    }
    
    int n1 = n;
    int n2 = n;

    for(int i = 0; i < 26; ++i){
        if(cnt1[i] > cnt3[i]) cnt1[i] = cnt3[i];
        if(cnt2[i] > cnt3[i]) cnt2[i] = cnt3[i];

        int sub1 = cnt3[i] - cnt2[i];
        int sub2 = cnt3[i] - cnt1[i];

        n1 -= sub1;
        n2 -= sub2;
    }

    if(n1 < 0 || n2 < 0) cout << "NO" << endl;
    else cout << "YES" << endl;

    return 0;
}
