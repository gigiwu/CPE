#include <iostream>
typedef unsigned long long ull;
using namespace std;
int main(){
    ull l,h;
    while(1){
        cin >> l >> h;
        if (l==0 && h == 0) break;
        cout << h/5 - l/5 +1 << endl;

    }
    return 0;
}