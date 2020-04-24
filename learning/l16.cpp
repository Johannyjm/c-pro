// #include <iostream>
// using namespace std;

// class Kitty{
// public:
//     char *str;
//     Kitty(){
//         this->str = "abc";
//     }
//     Kitty(const Kitty &obj){
//         this->str = "def";
//     }
// } g_obj;

// int main(){
//     Kitty obj = g_obj;
//     cout << g_obj.str << endl;
//     cout << obj.str << endl;

//     return 0;
// }

// #include <iostream>
// using namespace std;

// class Kitty{
// public:
//     Kitty(){
//         cout << "abc" << endl;
//     }
//     Kitty(const Kitty &obj){
//         cout << "def" << endl;
//     }
// };

// Kitty getKitty(Kitty obj){
//     return obj;
// }

// int main(){
//     Kitty obj;
//     obj = getKitty(obj);
//     return 0;
// }

#include <iostream>
using namespace std;

class Kitty{
private:
    int *x;

public:
    Kitty();
    Kitty(const Kitty &);
    ~Kitty();
    void printX();
} g_obj;

Kitty::Kitty(){
    this->x = (int *)malloc(5 * sizeof(int));
    for(int i = 0; i < 5; ++i){
        *(this->x + i) = i * 2;
    }
}

Kitty::Kitty(const Kitty &obj){
    this->x = (int *)malloc(5 * sizeof(int));
    for(int i = 0; i < 5; ++i){
        *(this->x + i) = i;
    }
}

Kitty::~Kitty(){
    free(this->x);
}

void Kitty::printX(){
    for(int i = 0; i < 5; ++i) cout << *(x + i) << " ";
    cout << endl;
}

int main(){
    Kitty obj = g_obj;
    g_obj.printX();
    obj.printX();
    return 0;
}