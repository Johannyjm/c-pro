#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string a, b;
    cin >> a >> b;
    int n = a.size();
    if(n == 1){
        cout << "NO" << endl;
        return 0;
    }

    vector<char> av, bv;

    vector<int> acnt(26, 0), bcnt(26, 0);
    for(int i = 0; i < n; ++i){
        if(a[i] != b[i]){
            av.push_back(a[i]);
            bv.push_back(b[i]);

            ++acnt[a[i] - 'a'];
            ++bcnt[b[i] - 'a'];
        }
    }

    for(int i = 0; i < 26; ++i){
        if(acnt[i] != bcnt[i]){
            cout << "NO" << endl;
            return 0;
        }
    }

    int m = av.size();
    if(m > 6){
        cout << "NO" << endl;
        return 0;
    }

    if(m == 0){
        for(int i = 0; i < n; ++i){
            ++acnt[a[i] - 'a'];
            if(acnt[a[i] - 'a'] > 1){
                cout << "YES" << endl;
                return 0;
            }
        }
        cout << "NO" << endl;
        return 0;
    }
    
    bool unique = true;
    for(int i = 0; i < 26; ++i){
        if(acnt[i] > 1){
            unique = false;
        }
    }

    if(unique){
        vector<int> ac(26, 0);
        for(int i = 0; i < n; ++i){
            ++ac[a[i] - 'a'];
            if(ac[a[i] - 'a'] > 1 && a[i] == b[i]){
                av.push_back(a[i]);
                av.push_back(a[i]);
                bv.push_back(b[i]);
                bv.push_back(b[i]);
                break;
            }
        }
    }


    for(int i = 0; i < m-1; ++i){
        for(int j = i+1; j < m; ++j){
            vector<char> av1 = av;
            swap(av1[i], av1[j]);

            for(int ii = 0; ii < m-1; ++ii){
                for(int jj = ii+1; jj < m; ++jj){
                    vector<char> av2 = av1;
                    swap(av2[ii], av2[jj]);

                    for(int iii = 0; iii < m-1; ++iii){
                        for(int jjj = iii+1; jjj < m; ++jjj){
                            vector<char> av3 = av2;
                            swap(av3[iii], av3[jjj]);

                            if(av3 == bv){
                                cout << "YES" << endl;
                                return 0;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "NO" << endl;



    return 0;
}
