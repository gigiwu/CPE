//uva11489
#include <iostream>
#include <vector>
#include <string> 
using namespace std;

int main(){

    int n;
    int nowcase = 0;
    string s;

    cin >> n;
    for(int i=0 ; i < n ; i++){
        cin >> s;
        nowcase++;
        int sum = 0;
        int counter = 0;
        vector<int> num;
        for(int j=0 ; j < s.length() ; j++){
            num.push_back(s[j]-'0');
            sum += s[j]-'0';
        }
        
        for(int j=0 ; j < num.size(); j++){
            if(num[j]%3 == 0) counter++;
        }

        if(sum%3 == 0){
            if(counter%2 == 0)
				cout << "Case " << nowcase << ": T" << endl;
            else
				cout << "Case " << nowcase << ": S" << endl;
        }
        else{
            for(int j=0 ; j < num.size() ; j++){
                if((sum-num[j])%3 == 0){
                    if(counter%2 == 0)
						cout << "Case " << nowcase << ": S" << endl;
                    else 
						cout << "Case " << nowcase << ": T" << endl;
                    break;
                }
                else if(j == num.size()-1){
                    cout << "Case " << nowcase << ": T" << endl;
                    break;
                }
            }
        }
    }
}