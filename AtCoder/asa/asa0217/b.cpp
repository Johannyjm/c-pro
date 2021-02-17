#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    int h = n / 3600;
    n %= 3600;
    int m = n / 60;
    n %= 60;
    int s = n;

    string res1 = "0";
    if(h < 10) res1 += char('0' + h);
    else{
        res1 = char('0' + h/10);
        res1 += char('0' + h%10);
    }

    string res2 = "0";
    if(m < 10) res2 += char('0' + m);
    else{
        res2 = char('0' + m/10);
        res2 += char('0' + m%10);
    }

    string res3 = "0";
    if(s < 10) res3 += char('0' + s);
    else{
        res3 = char('0' + s/10);
        res3 += char('0' + s%10);
    }

    cout << res1 << ":" << res2 << ":" << res3 << endl;

    return 0;
}
