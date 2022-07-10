#include <iostream>
#include <math.h>
using namespace std;
int main(){
    string in;
    int b, cb;
    string s="ABCDEF";
    while(cin >> in){
        cin >> b >> cb;
        //cout << in << " " << b <<" "<< cb<< endl;
        int num = 0;
        for(int i =0;i<in.size();i++){
            char c = in[in.size()-i-1];
            int d;
            if(isdigit(c)){
                d = c - '0';
            }else{
                d = c - 'A' + 10;
            }
            //cout << d << " " << b << " " << i << " " << pow(b,i) << " ";
            num += d * pow(b,i);
        }
       
        //cout << num << endl;

        char out[7] = {0};
        int count = 0;
        while(num>0){
            int n = num % cb;
            char nc;
            if(n >= 10){
                nc = n - 10 + 'A';
            }else{
                nc=n + '0';
            }
            
            //cout << nc << " ";
            out[6-count] = nc;

            //cout << endl;
            //out += (num % cb) * pow(10,count);
            count++;
            num = num / cb;
        }

        for(int i = 0; i < 7-count; i++){
            cout << '0';
        }
        for(int i = 0; i< 7 ; i++){
            cout << out[i];
        }
         cout << endl;
    }
    cout << endl;
}