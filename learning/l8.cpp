// #include<iostream>
// using namespace std;

// class Kitty{
// public:
//     int num;
// } obj[10];

// int main(){
//     for(int i = 0; i < 10; ++i){
//         obj[i].num = i;
//         cout << obj[i].num << '\n';
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

class Kitty{
public:
    int num;
};

int main(){
    Kitty k[10];
    for(int i = 0; i < 10; ++i){
        k[i].num = i;
    }

    for(int i = 0; i < 10; ++i){
        cout << k[i].num << endl;
    }
}