#include <iostream>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int y = 100;
    int x = 0;

    for(int r = 1; r <= 100; ++r){
        if(x + r + r > 1500){
            y += 200;
            x = 0;
        }
        x += r + r;

        cout << x-r << " " << y << endl;
    }

    return 0;
}
