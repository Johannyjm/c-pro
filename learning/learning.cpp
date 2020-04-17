#include<iostream>

class Kitty{
    private: 
        int point;

    public:
        void setPoint(int i);
        int getPoint();
};

void Kitty::setPoint(int i){
    point = i;
}

int Kitty::getPoint(){
    return point;
}


int main(){
    Kitty k;
    k.setPoint(10);

    int out = k.getPoint();
    std::cout << out << std::endl;
}