#include <iostream>
#include <string>
using namespace std;

string strswp(string a, string b){
    int n = a.size();
    int idx = -1;
    for(int i = 0; i < n; ++i){
        if(a[i] != b[i]){
            idx = i;
            break;
        }
    }
    if(idx == -1) return b;
    
    int idx2 = -1;
    for(int i = 0; i < n; ++i){
        if(i > idx && a[idx] == b[i]){
            idx2 = i;
            break;
        }
    }

    string ret = "";
    for(int i = 0; i < n; ++i){
        if(i == idx) ret += b[idx2];
        else if(i == idx2) ret += b[idx];
        else ret += b[i];
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;

    if(a.size()==1 || b.size()==1){
        cout << "NO" << endl;
        return 0;
    }
    
    bool dub = false;
    int cnta[26] = {};
    int cntb[26] = {};
    for(int i = 0; i < a.size(); ++i){
        ++cnta[a[i] - 'a'];
        ++cntb[b[i] - 'a'];
        if(cnta[a[i] - 'a'] > 1) dub = true;
    }

    for(int i = 0; i < 26; ++i){
        if(cnta[i] != cntb[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    if(a == b){
        if(dub) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }

    string b_ = strswp(a, b);
    if(a == b_){
        cout << "YES" << endl;
        return 0;
    }

    string b__ = strswp(a, b_);
    if(a == b__){
        if(dub) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }

    string b___ = strswp(a, b__);
    if(a == b___) cout << "YES" << endl;
    else cout << "NO" << endl;


    return 0;
}
