#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.size();
    string cnvd = "";
    for(int i = 0; i < n-1; ++i){
        if(s[i] == 'B' && s[i+1] == 'C'){
            cnvd += 'D';
            ++i;
        }
        else cnvd += s[i];
    }
    
    n = cnvd.size();
    int base = -1;
    int res = 0;
    for(int i = 0; i < n; ++i){
        if(cnvd[i] == 'A' || cnvd[i] == 'D'){
            if(base == -1){
                base = i;
                if(cnvd[i]=='D') ++base;
            }
            else{
                if(cnvd[i]=='D'){
                    res += i-base;
                    ++base;
                }
            }
        }
        else{
            base = -1;
        }
    }

    cout << res << endl;
}
