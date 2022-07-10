#include <iostream>
using namespace std;
int main(){
    int T,n;
    cin >> T;
    while(T-->0){
        cin >> n;
        int A[1001] = {0};
        int sum = 0;
        int B[1000]={0};

        for (int i=0; i<n; i++){
            cin >> A[i];
            B[i] = 0;
            for (int j=0; j<i; j++){
                if(A[j] <= A[i]) B[i-1]++;
            }
        }
        for (int i=0; i<n-1 ; i++){
            sum += B[i];
        }
        cout << sum << "\n";
    }
    return 0;
}