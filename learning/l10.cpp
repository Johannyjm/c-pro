// #include<iostream>
// using namespace std;

// class Kitty{
// public:
//     char *str;
// } obj;

// int main(){
//     obj.str = "Di_Gi_Gharat";
//     Kitty *po = &obj;

//     po->str = "Kitty on your lap";

//     cout << obj.str << endl;
// }

// #include <iostream>
// using namespace std;

// class Kitty{
// public:
//     char *str;
// };

// int main(){
//     Kitty obj;
//     obj.str = "ABC";

//     cout << obj.str << endl;
//     Kitty *ptr;
//     ptr = &obj;

//     ptr->str = "DEF";
//     cout << obj.str << endl;

//     cout << endl;

//     cout << ptr->str << endl;
// }

#include <iostream>
using namespace std;

class Kitty{
public:
    char *s;
    Kitty(char *);
};

Kitty::Kitty(char *s){
    Kitty::s = s;
}

int main(){
    Kitty *ptr1, *ptr2, *ptr3, obj[3] = {
        Kitty("BCD"), 
        Kitty("CDE"), 
        Kitty("DEF")
    };

    // Kitty *ptr1, *ptr2, *ptr3;
    ptr1 = &obj[0];
    ptr2 = &obj[1];
    ptr3 = &obj[2];

    cout << ptr1->s << endl;
    ++ptr1;
    cout << ptr1->s << endl;

    cout << ptr2->s << endl;
    ++ptr2;
    cout << ptr2->s << endl;
}