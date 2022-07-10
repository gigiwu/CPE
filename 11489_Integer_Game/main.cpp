#include <iostream>
using namespace std;
typedef unsigned long long ull;
int main(){
    int T;
    string N;
    cin >> T;
    for(int i =0;i<T;i++){
        cout << "Case " << i+1 << ": ";
        cin >> N;
        int counter[10] = {0};
        int sum = 0;
        for(auto & c :N){
            int n = c-'0';
            counter[n]++;
            sum += n;
        }
        int draw = 0;
        while(sum > 0){
            int rm = sum%3;
            bool found =false;
            for(int j=0; j<=3 && j*3+rm <10; j++){
                if(counter[rm+j*3]>0){
                    counter[rm+j*3]--;
                    draw++;
                    sum -= (rm+j*3);
                    found = true;
                    break;
                }
            }
            if(!found){
                break;
            }
        }
        int rem = 0;
        for(auto & c : counter){
            rem+=c;
        }
        if(rem==1) draw++;
        cout << (draw%2==1 ? "S":"T") << endl;
    }
}