// #include <iostream>
// #include <string>
// using namespace std;

// class Kitty{
// public:
//     string s;
// };

// void setKitty(Kitty &obj, string s){
//     obj.s = s;
// }

// int main(){
//     Kitty obj;
//     setKitty(obj, "Kitty on your lap");
//     cout << obj.s << endl;

//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;

class Kitty{
    int X;
public:
    int & getX();
} obj;

int & Kitty::getX(){
    return X;
}

int main(){
    obj.getX() = 10;
    cout << obj.getX() << '\n';
    
    return 0;
}