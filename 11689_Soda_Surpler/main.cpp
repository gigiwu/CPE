#include <iostream>
using namespace std;
int main(){
    int N, e,f,c;
    cin >> N;
    while(N--){
        cin >> e >> f >> c;
        int ans = 0;
        int empty = e+f;
        while(empty >= c){
            int buy = empty / c;
            int rem = empty % c;
            ans +=buy;
            empty = buy + rem;
        }
        cout << ans << endl;
    }
}