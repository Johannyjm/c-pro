#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    string s;
    cin >> n >> s;

    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            if(i % 2 == 0) puts("Takahashi");
            else puts("Aoki");
            return 0;
        }
    }
    
    return 0;
}
