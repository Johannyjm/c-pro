#include <iostream>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int s, t, x;
    cin >> s >> t >> x;

    if(s < t){
        if(s <= x && x < t) puts("Yes");
        else puts("No");
    }
    else{
        if(x < t || s <= x) puts("Yes");
        else puts("No");
    }

    return 0;
}
