#include <iostream>
#include <map>

using namespace std;
int main (){
    int t;
    cin >> t;
    string notes;
    map<char, string> finger= {
        {'c',"1236789"},
        {'d',"123678"},
        {'e',"12367"},
        {'f',"1236"},
        {'g',"123"},
        {'a',"12"},
        {'b',"1"},
        {'C',"2"},
        {'D',"0123678"},
        {'E',"012367"},
        {'F',"01236"},
        {'G',"0123"},
        {'A',"012"},
        {'B',"01"},
    }; 
    while(t--){
        int press[10] = {0};
        int count[10] = {0};
        cin >> notes;
        //cout << notes <<endl;
        for(auto & c : notes){
            //cout << c << ": ";
            int keep[10] = {0};
            for(int i = 0; i< finger.at(c).size(); i++){
                
                int f = finger.at(c)[i] - '0'; 
                //cout << f << " press[f]" <<press[f];
                keep[f] = 1;
                if(press[f] == 0){
                    count[f]++;
                    press[f] = 1;
                    //cout << " press and count ++: " << f<<" keep:" << keep[f] << " count[f]:" <<count[f]<<" press[f]:" <<press[f]<<endl;
                }
                
            }
            for(int j = 0; j<10; j++){
                if(keep[j]==0) press[j] = 0;
            }
            //cout << endl; 
        }
        for(int i = 0; i <9; i++){
            printf("%d ", count[i]);
        }
        printf("%d", count[9]);
        cout << endl;
    }
}