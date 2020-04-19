#include<iostream>
using namespace std;

class Kitty{
public:
    ~Kitty();
};

Kitty::~Kitty(){
    std::cout << "Kitty on your lap" << std::endl;

}

void createKitty(){
    Kitty obj;
}

signed main(){
    createKitty();
    createKitty();
    Kitty obj;

    cout << (119 << 23 | 1) << endl;
    return 0;
}