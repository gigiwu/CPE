#include <iostream>
using namespace std;
int main(){
    string s;
    string t[8]={"ABC","DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
    while(cin >> s){
        int hyphen = 0;
        int letter = 0;
        for(auto& c : s){
            if (isdigit(c)){
                cout << c;
            }
            else if(c=='-'){
                hyphen++;
                cout << c;
            }else{
                letter++;
                for(int i = 0; i<8;i++){
                    for(auto &l:t[i]){
                        if(l==c){
                            cout << i+2;
                        }
                    }
                }
            }
        }
        cout << " " << letter << " " << hyphen << endl;
    }
}