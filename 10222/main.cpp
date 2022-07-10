#include <iostream>
using namespace std;
string KEYS = "qwertyuiop[]¥asdfghjkl;'zxcvbnm,./";
int main(){
    int N;
    cin >> N;
    string tmp;
    getline(cin, tmp);
    while(N--){
        getline(cin, tmp);
        for_each(tmp.begin(), tmp.end(), [](char & c){
            c = tolower(c);
        });
        for(int i=0; i <tmp.length(); i++){
            if(tmp[i] != ' ') tmp[i] = KEYS[KEYS.find(tmp[i])-2];
        }
        
        cout << tmp << "\n";
    }
    return 0;
}