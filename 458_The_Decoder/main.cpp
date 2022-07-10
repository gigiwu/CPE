#include <iostream>
using namespace std;
// diff is -7
int main(){

    string in;
    while(cin >> in){
        for(int i=0; i<in.size();i++){
            cout << (char)(in[i] -7);;
        }
        cout << endl;
    }

}