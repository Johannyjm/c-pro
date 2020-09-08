#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    int res = 0;

    for(int p = 0; p < 1000; ++p){
        char one = p / 100 + '0';
        char two = (p / 10) % 10 + '0';
        char three = p % 10 + '0';
        
        bool one_f = false;
        bool two_f = false;
        bool three_f = false;

        int ptr = 0;

        for (int i = 0; i < n-2; ++i){
            if(s[i] == one){
                one_f = true;
                ptr = i;
                break;
            }
        }

        for (int i = ptr+1; i < n-1; ++i){
            if(s[i] == two){
                two_f = true;
                ptr = i;
                break;
            }
        }

        for (int i = ptr+1; i < n; ++i){
            if(s[i] == three){
                three_f = true;
                ptr = i;
                break;
            }
        }

        if(one_f && two_f && three_f) res++;
    }
    cout << res << endl;
}