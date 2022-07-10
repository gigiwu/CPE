// 20220525 Total: 23 min
//https://cpe.cse.nsysu.edu.tw/cpe/file/attendance/problemPdf/12908.pdf
#include <iostream>
using namespace std;
typedef unsigned long long ull;
int main(){
    ull s;
    while(cin >> s && s != 0){
        ull page=0;
        ull sum=0;
        while(sum <= s){
            ++page;
            sum+= page;
        }
        ull m  = sum - s;
        cout << m <<  " " << page << endl;
    }
    return 0;
}