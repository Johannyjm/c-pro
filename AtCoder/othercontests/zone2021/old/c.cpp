#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
#define rep1(i, n) for(int i = 1; i < (n); ++i)
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    string res = "";

    deque<char> dq;
    int rev = 0;
    for(char c: s){
        if(c == 'R'){
            rev = 1 - rev;
        }
        else{
            if(rev == 0){
                if(!dq.empty() &&dq.back() == c) dq.pop_back();
                else dq.push_back(c);
            }
            else{
                if(!dq.empty() && dq.front() == c) dq.pop_front();
                else dq.push_front(c);
            }
        }
    }

    if(rev == 1){
        while(!dq.empty()){
            cout << dq.back();
            dq.pop_back();
        }
    }
    else{
        while(!dq.empty()){
            cout << dq.front();
            dq.pop_front();
        }
    }
    cout << endl;

    return 0;
}