#include <iostream>
#include <string>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int deg, dis;
    cin >> deg >> dis;

    string res1;
    deg *= 10;
    if(1125 <= deg && deg < 3375) res1 = "NNE";
    else if(3375 <= deg && deg < 5625) res1 = "NE";
    else if(5625 <= deg && deg < 7875) res1 = "ENE";
    else if(7875 <= deg && deg < 10125) res1 = "E";
    else if(10125 <= deg && deg < 12375) res1 = "ESE";
    else if(12375 <= deg && deg < 14625) res1 = "SE";
    else if(14625 <= deg && deg < 16875) res1 = "SSE";
    else if(16875 <= deg && deg < 19125) res1 = "S";
    else if(19125 <= deg && deg < 21375) res1 = "SSW";
    else if(21375 <= deg && deg < 23625) res1 = "SW";
    else if(23625 <= deg && deg < 25875) res1 = "WSW";
    else if(25875 <= deg && deg < 28125) res1 = "W";
    else if(28125 <= deg && deg < 30375) res1 = "WNW";
    else if(30375 <= deg && deg < 32625) res1 = "NW";
    else if(32625 <= deg && deg < 34875) res1 = "NNW";
    else res1 = "N";

    int res2;
    dis *= 100;
    dis /= 60;
    if(dis % 10 < 5) dis -= dis % 10;
    else{
        dis -= dis % 10;
        dis += 10;
    }

    if(0 <= dis && dis <= 20){
        res2 = 0;
        res1 = "C";
    }
    else if(30 <= dis && dis <= 150) res2 = 1;
    else if(160 <= dis && dis <= 330) res2 = 2;
    else if(340 <= dis && dis <= 540) res2 = 3;
    else if(550 <= dis && dis <= 790) res2 = 4;
    else if(800 <= dis && dis <= 1070) res2 = 5;
    else if(1080 <= dis && dis <= 1380) res2 = 6;
    else if(1390 <= dis && dis <= 1710) res2 = 7;
    else if(1720 <= dis && dis <= 2070) res2 = 8;
    else if(2080 <= dis && dis <= 2440) res2 = 9;
    else if(2450 <= dis && dis <= 2840) res2 = 10;
    else if(2850 <= dis && dis <= 3260) res2 = 11;
    else if(3270 <= dis) res2 = 12;
    
    cout << res1 << " " << res2 << endl;

    return 0;
}
