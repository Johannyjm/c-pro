#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool can_win(string S, string T) {
    vector<int> countS(8, 0), countT(8, 0); // a, t, c, o, d, e, r, @
    for(char c : S) {
        if(c == '@') countS[7]++;
        else if(c == 'a') countS[0]++;
        else if(c == 't') countS[1]++;
        else if(c == 'c') countS[2]++;
        else if(c == 'o') countS[3]++;
        else if(c == 'd') countS[4]++;
        else if(c == 'e') countS[5]++;
        else if(c == 'r') countS[6]++;
    }
    for(char c : T) {
        if(c == '@') countT[7]++;
        else if(c == 'a') countT[0]++;
        else if(c == 't') countT[1]++;
        else if(c == 'c') countT[2]++;
        else if(c == 'o') countT[3]++;
        else if(c == 'd') countT[4]++;
        else if(c == 'e') countT[5]++;
        else if(c == 'r') countT[6]++;
    }
    for(int i = 0; i < 8; i++) {
        if(countS[i] != countT[i]) return false;
    }
    return true;
}

int main() {
    string S, T;
    cin >> S >> T;
    if(can_win(S, T)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}