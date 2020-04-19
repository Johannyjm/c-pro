#include<iostream>

class Kitty{
    public:
        char *str;
        Kitty(char *);
};

Kitty::Kitty(char *ch){
    str = ch;
}

int main(){
    Kitty obj("Kitty on your lap");

    std::cout << obj.str << std::endl;
}

// class Kitty{
//     public:
//         std::string str;
//         Kitty(std::string s);
// };

// Kitty::Kitty(std::string s){
//     str = s;
// }

// int main(){
//     Kitty obj("Kitty on your lap");

//     std::cout << obj.str << std::endl;
// }