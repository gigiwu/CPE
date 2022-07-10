#include <iostream>
#include <set>
using namespace std;
int main(){
    int N;
    while(cin >> N && N != 0){
        bool found = false;
        for(int i=1234; i < 98765; i++){
            if(i*N > 98765){
                if(!found) cout << "There are no solutions for " << N << "." <<endl;
                break;
            } else if(i*N < 10000){
                continue;
            }else{
                int digit[10]={0};
                int num = i*N;
                int den = i;
                bool isdup = false;
                if(den <10000) digit[0]++;
                while(num>0){
                    int tmp = num%10;
                    num = num/10;
                    if(digit[tmp]!=0){
                        isdup=true;
                        break;
                    }else digit[tmp]++;
                }
                while(den>0 && !isdup){
                    int tmp = den%10;
                    den = den/10;
                    if(digit[tmp]!=0) {
                        isdup=true;
                        break;
                    }else digit[tmp]++;
                }
                if(!isdup){
                    found=true;
                    printf("%05d / %05d = %d\n", i*N, i, N);
                }
            }
        }
        cout << endl;
    }
    return 0;
}