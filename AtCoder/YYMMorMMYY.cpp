#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    int pre = 10 * (s.substr(0, 2)[0] - '0') + (s.substr(0, 2)[1] - '0');
    int post = 10 * (s.substr(2)[0] - '0') + (s.substr(2)[1] - '0');

    bool pre_f = false;
    bool post_f = false;
    if(1 <= pre && pre <= 12) pre_f = true;
    if(1 <= post && post <= 12) post_f = true;

    if(pre_f){
        if(post_f) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }
    else{
        if(post_f) cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }


}