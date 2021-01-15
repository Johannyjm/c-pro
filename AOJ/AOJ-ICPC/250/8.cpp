#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int pdfs(int, int, int);
int mdfs(int, int, int);

vector<string> s;
int pdfs(int l, int r, int p){
    int ret = 0;
    for(int i = l; i < r; ++i){
        if('0'<=s[i][p] && s[i][p]<='9'){
            ret += s[i][p] - '0';
        }
        else{
            int nr = r;
            for(int j = i+1; j < r; ++j){
                if(s[j].size() <= s[i].size()){
                    nr = j;
                    break;
                }
            }

            if(s[i][p] == '+') ret += pdfs(i+1, nr, p+1);
            if(s[i][p] == '*') ret += mdfs(i+1, nr, p+1);
        }
    }

    return ret;
}

int mdfs(int l, int r, int p){
    int ret = 1;
    for(int i = l; i < r; ++i){
        if('0'<=s[i][p] && s[i][p]<='9'){
            ret *= s[i][p] - '0';
        }
        else{
            int nr = r;
            for(int j = i+1; j < r; ++j){
                if(s[j].size() <= s[i].size()){
                    nr = j;
                    break;
                }
            }

            if(s[i][p] == '+') ret *= pdfs(i+1, nr, p+1);
            if(s[i][p] == '*') ret *= mdfs(i+1, nr, p+1);
        }
    }

    return ret;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while(1){
        int n;
        cin >> n;
        if(n == 0) break;

        s.clear();
        s.resize(n);
        rep(i, n) cin >> s[i];

        cout << pdfs(0, n, 0) << endl;


        // rep(i, n) cin >> s[i];
        // if('0'<=s[0][0] && s[0][0]<='9'){
        //     cout << s[0][0] - '0' << endl;
        //     continue;
        // }

        // stack<string> st;
        // stack<int> plus, mul;
        // st.push(s[0]){
        //     string op = st.top();
        //     st.pop();


        // }


    }

    return 0;
}