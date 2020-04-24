// #include <iostream>
// using namespace std;

// void Kitty(){
//     cout << "abc" << endl;
// }

// void Kitty(char *str){
//     cout << str << endl;
// }

// int main(){
//     Kitty();
//     Kitty("def");
//     Kitty();
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Kitty{
// public:
//     char *str;
//     Kitty(){
//         this->str = "abc";
//     }
//     Kitty(char *str){
//         this-> str = str;
//     }
// } obj, ary[3] = {"def", "ghi", "jkl"};

// int main(){
//     cout << obj.str << endl;
//     for(int i = 0; i < 3; ++i) cout << ary[i].str << endl;
//     return 0;
// }

#include <iostream>
using namespace std;

void Kitty(double x){
    cout << "double: " << x << endl;
}

void Kitty(float x){
    cout << "float: " << x << endl;
}

int main(){
    Kitty(10.0d);
    Kitty(10.0f);
    Kitty(10);
    return 0;
}