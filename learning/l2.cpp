#include<iostream>

class Kitty{
    private:
        int point;
    public:
        void setPoint(int i){
            this->point = i;
        }
        int getPoint(){
            return this->point;
        }

};


int main(){
    Kitty k;

    k.setPoint(10);
    std::cout << k.getPoint() << std::endl;
}