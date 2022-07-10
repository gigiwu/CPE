#include <iostream>
using namespace std;
int main(){
    int T, N ,P;
    cin >> T;
    while(T--){
        cin >> N >> P;
        int h[N];
        for(int i =0;i<N;i++){
            h[i] =0;
        }
        while(P--){
            int par;
            cin >> par;

            for(int i =0; i< N; i++){
                if((i+1)%7==6 || (i+1)%7==0) {
                    continue;
                    }
                if((i+1)%par==0){
                    h[i]=1;
                }
            }
        }
        int sum=0;
        for (auto c:h){
            sum +=c;
        }
        cout << sum << endl;
    }
}