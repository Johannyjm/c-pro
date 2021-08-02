#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    vector<string> s(4);
    for(int i = 0; i < 4; ++i) cin >> s[i];

    sort(s.begin(), s.end());

    if(s[0] == "2B" && s[1] == "3B" && s[2] == "H" && s[3] == "HR") puts("Yes");
    else puts("No");


    

    return 0;
}
