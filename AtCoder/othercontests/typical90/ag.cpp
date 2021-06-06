#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int h, w;
    cin >> h >> w;

    if(h<2 || w<2) cout << h*w << endl;
    else cout << ((h+1)/2) * ((w+1)/2) << endl;

    return 0;
}
