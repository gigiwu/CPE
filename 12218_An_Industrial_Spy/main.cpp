#include <iostream>
#include <vector>
#include <set>
using namespace std;

int mem[10000000] = {0};

bool isprime(int a){
    if (a<2) return false;
    if (mem[a] == 1) return true;
    else if (mem[a] == -1) return false;
    bool ret = true;
    for(int i=2;i<=a/2;i++){
        //cout << "a: " << a << " i: " << i << " a/2: " << a/2 << endl;

        if(a%i==0){
            //cout << "a%i==0 ret: " << ret << endl;

            ret = false;
        }
    }
    mem[a] = ret ? 1:0;
    return ret;
}
int countprime(vector<int> v, int n){
    int count =0;
    int idx = 0;
    for(auto it = v.begin(); it != v.end(); it++){
        int d = *it;
        if(isprime(d + n)){
            count++;
        }
        if(v.size()>1){
            vector<int> newv = v;
            newv.erase(newv.begin()+idx);
            count += countprime(newv, 10*(d + n));
        }
        idx++;
    }
    //cout << "n: " << n << " count: " << count << endl;

    return count;
}
int main(){
    int c;
    string s;
    cin >> c;
    //cout<< isprime(4) << endl;
    //cout<< isprime(5) << endl;
    
    while(c--){
        cin >> s;
        //cout << s << endl;
        vector<int> digits;
        int count = 0;
        sort(s.begin(), s.end());
        for(auto & d : s){
            int n = d-'0';
            digits.push_back(n);    
        }
        //cout << countprime(digits, 0) << endl;
        auto cand = next_permutation(digits.begin(),digits.end());

    }

    return 0;
}