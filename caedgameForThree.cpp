#include <bits/stdc++.h>
using namespace std;

int main(){
    string SA, SB, SC;
    cin >> SA >> SB >> SC;

    char trash = SA[0];
    string winner;

    while(true){

        if(trash == 'a'){

            if(SA.size() == 0){
                winner = "A";
                break;
            }
            else{
                trash = SA[0];
                SA.erase(0, 1);
            }
        }

        if(trash == 'b'){

            if(SB.size() == 0){
                winner = "B";
                break;
            }
            else{
                trash = SB[0];
                SB.erase(0, 1);
            }
        }

        if(trash == 'c'){

            if(SC.size() == 0){
                winner = "C";
                break;
            }
            else{
                trash = SC[0];
                SC.erase(0, 1);
            }
        } 

    }
    cout << winner << endl;
}