#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();

    int cnt = 0;
    for(char c: s){
        if(c == 'o') ++cnt;
    }

    if(cnt + (15 - n) >= 8) puts("YES");
    else puts("NO");

    return 0;
}
