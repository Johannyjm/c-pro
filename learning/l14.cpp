// #include <iostream>
// #include <string>
// using namespace std;

// class Kitty{
// public:
//     char *str;
//     Kitty(char *str){
//         this->str = str;
//     }
//     void func(){
//         cout << this->str << endl;
//     }
// } obj[3] = {"abc", "def", "ghi"};

// int main(){
//     for(int i = 0; i < 3; ++i) obj[i].func();
// }

#include <iostream>
#include <string>
using namespace std;

class Kitty{
public:
    string str;
    Kitty(string s){
        this->str = s;
    }
    void func(){
        cout << this->str << endl;
    }
};

int main(){
    Kitty k("abc");
    k.func();

    Kitty obj[3] = {"defg", "ghih", "jklm"};
    for(int i = 0; i < 3; ++i) obj[i].func();

}