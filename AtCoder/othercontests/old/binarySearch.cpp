#include <bits/stdc++.h>
using namespace std;

vector<int> a = {1, 14, 32, 51, 51, 51, 243, 419, 750, 910};

int binary_search(int key){
    int left = 0;
    int right = (int)a.size() - 1;

    while(right >= left){
        int mid = left + (right - left) / 2;
        
        if(a[mid] == key) return mid;
        else if(a[mid] > key) right = mid - 1;
        else if(a[mid] < key) left = mid + 1;
    }

    return -1;
}

int main(){

    cout << binary_search(51) << endl;
    cout << binary_search(1) << endl;
    cout << binary_search(910) <<endl;

}