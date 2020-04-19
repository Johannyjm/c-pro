// #include <iostream>
// using namespace std;

// int main(){
//     int i = 100;
//     int &ref = i;
//     ++ref;

//     cout << i << " : " << ref << '\n';
//     cout << &i << " : " << &ref << '\n';

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Kitty{
// public:
//     char *s;
// } obj;

// int main(){
//     Kitty &ref = obj;
//     ref.s = "Kitty on your lap";

//     cout << obj.s << endl;

//     cout << ref.s << endl;
// }

// #include <iostream>
// using namespace std;

// class Kitty{
// public:
//     char *s;
//     Kitty();
//     ~Kitty();
// } obj;

// Kitty::Kitty(){
//     cout << "ABC" << '\n';
// }

// Kitty::~Kitty(){
//     cout << s << '\n';
// }

// void func(Kitty obj){
//     obj.s = "Di_Gi_Gharat";
// }

// int main(){
//     obj.s = "Kitty on your lap";
//     func(obj);
//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Kitty{
// public:
//     char *s;
//     ~Kitty();
// } obj;

// Kitty::~Kitty(){
//     cout << s << '\n';
// }

// void func(Kitty *obj){
//     obj->s = "Di_Gi_Gharat";
// }

// int main(){
//     obj.s = "Kitty on your lap";
//     func(&obj);
// }

#include <iostream>
#include <string>
using namespace std;

class Kitty{
public:
    string s;
    ~Kitty();
};

Kitty::~Kitty(){
    cout << "Dest" << '\n';
}

Kitty getKitty(string s){
    Kitty obj;
    obj.s = s;
    return obj;
}

int main(){
    Kitty obj = getKitty("Kitty on your lap");
    cout << 1 << endl;
    cout << obj.s << '\n';
    cout << 2 << endl;
}