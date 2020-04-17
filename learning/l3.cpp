#include<iostream>

class Kitty{
    public:
        Kitty();
} obj;

Kitty::Kitty(){
    std::cout << "Kitty on yout lap" << std::endl;
}


int main(){
    std::cout << 1 << std::endl;

    Kitty obj;
    return 0;

}