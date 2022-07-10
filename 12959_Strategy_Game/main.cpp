#include <iostream>
using namespace std;
int main(){
    int J, R;
    while(1){
        int sum[505] = {0};
        cin >> J >> R;
        if(J == 0 && R == 0) break;
        for(int i = 0; i < J*R ; i++){
            int tmp;
            cin >> tmp;
            sum[i%J]+=tmp;
        }
        int max = sum[0];
        int player = 0;
        for(int i=0; i< J; i++){
            if(sum[i] >= max){
                max = sum[i];
                player=i;
            }
        }
        cout << player+1 << "\n";
    }
    return 0;
}