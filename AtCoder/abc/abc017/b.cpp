#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string x;
    cin >> x;

    int ptr = 0;
    while(ptr<x.length()-1){
        if(x[ptr] == 'o' || x[ptr] == 'k' || x[ptr] == 'u') ++ptr;
        else if(x[ptr] == 'c' && x[ptr+1] == 'h') ptr += 2;
        else{
            puts("NO");
            return 0;
        }
    }
    puts("YES");
}