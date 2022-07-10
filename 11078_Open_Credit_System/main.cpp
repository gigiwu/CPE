#include <iostream>
using namespace std;
int main() {
    int T, N;
    
    cin >> T;
    while(T--){
        cin >> N;
        int score[100000];
        int maxdif[100000];
        for (int i = 0; i< N; i++){
            maxdif[i] = INT_MIN;
        }
        //cout << "N:" << N << "\n";
        for(int i = 0; i< N; i++){
            cin >> score[i];
            //cout << "score:" << score[i] << "\n";
            for(int j =0; j< i ; j++){
                int newdif=score[j]-score[i];
                //out << "i:" << i << " j:" << j << " newdif: " << newdif << " maxdif: "<< maxdif[j]<<"\n";
                if( newdif > maxdif[j]) maxdif[j]=newdif;
            }
        }
        int max=maxdif[0];
        for(int i=0; i< N; i++){
            //cout << maxdif[i] << "\n";
            if(maxdif[i] > max) max = maxdif[i];
        }
        cout << max << "\n";
    }
    
    return 0;
}