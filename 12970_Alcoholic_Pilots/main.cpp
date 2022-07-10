#include <iostream>
#include <numeric>
using namespace std;
typedef unsigned long long ull;
int main(){
    int n = 1;
    ull v1, d1, v2 ,d2;
    while(1){
        cin >> v1 >> d1 >> v2 >> d2;
        if(v1==0 && d1 ==0 && v2==0 && d2 ==0) break;
        string winner;
        double t1 = (double) d1 / v1;
        double t2 = (double) d2 / v2;
        if(t1 < t2) winner = "You owe me a beer!";
        else winner = "No beer for the captain.";
        cout << "Case #" << n++ << ": " << winner << endl;
        cout << "Avg. arrival time: ";
        double avg = (t1+t2)/2;
        int int_avg = (int) avg;
        if(avg > (double)int_avg){
            ull n = d1 * v2 + d2 * v1;
            ull m = v1 * v2 * 2;
            ull g = gcd(n,m);
            cout << n/g << "/" << m/g << endl;    
        }else{
            cout << avg << endl;
        }
    }
    return 0;
}