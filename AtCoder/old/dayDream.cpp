// #include <iostream>
// #include <string>
// #include <algorithm>

#include <bits/stdc++.h>

using namespace std;


int main() {
    string divide[4] = {"dream", "dreamer", "erase", "eraser"};

    string S;
    cin >> S;

    reverse(S.begin(), S.end());
    for(int i = 0; i < 4; ++i) reverse(divide[i].begin(), divide[i].end());

    bool can = true;

    for(int i = 0; i < S.size();){
        bool can2 = false;

        for(int j = 0; j < 4; ++j){

            if(S.substr(i, divide[j].size()) == divide[j]){
                can2 = true;
                i += divide[j].size();
            }
        }
        if(!can2){
            can = false;
            break;
        }
    }
    if(can) cout << "YES" << endl;
    else cout << "NO" << endl;
}

// #include <iostream>
// #include <string>
// #include <algorithm>
// using namespace std;

// //string divide[4] = {"dream", "dreamer", "erase", "eraser"};

// int main() {
//     string S;
//     cin >> S;
//     string divide[4] = {"dream", "dreamer", "erase", "eraser"};

//     // 後ろから解くかわりにすべての文字列を「左右反転」する
//     reverse(S.begin(), S.end());
//     for (int i = 0; i < 4; ++i) reverse(divide[i].begin(), divide[i].end());

//     // 端から切っていく
//     bool can = true;
//     for (int i = 0; i < S.size();) {
//         bool can2 = false; // 4 個の文字列たちどれかで divide できるか
//         for (int j = 0; j < 4; ++j) {
//             string d = divide[j];
//             if (S.substr(i, d.size()) == d) { // d で divide できるか
//                 can2 = true;
//                 i += d.size(); // divide できたら i を進める
//             }
//         }
//         if (!can2) { // divide できなかったら
//             can = false;
//             break;
//         }
//     }

//     if (can) cout << "YES" << endl;
//     else cout << "NO" << endl;
// }