#include <iostream>
using namespace std;
int main(){
    int N, M, D;
    cin >> N;
    int days[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    string dayname[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    for(int i=1; i < 12; i++){
        days[i] += days[i-1];
    }
    int monday = (4+days[2]) % 7; // Given 4/4 is monday
    while(N--){
        cin >> M >>D;
        int d = (M==1)? D: days[M-2]+D;
        int s = d%7 - monday;
        if (s<0) s+=7;
        cout << dayname[s] << endl;
    }
    return 0;
}