#include <iostream>
using namespace std;
#include <map>
#include <set>
int X, Y;
set<pair<int, int>> losts;

int main(){
    cin >> X >> Y;
    int x, y;
    char ori;
    string ins;
    
    map<char, int> dir = {
        {'N', 0},
        {'E', 1},
        {'S', 2},
        {'W', 3}
        };
    char numToDir[4] = {'N','E','S','W'};
    while(cin >> x){
        cin >> y >> ori;
        cin >> ins;
        //cout << x << " " << y << " " << ori << " " << ins << "\n";
        int turn = 0;
        bool islost = false;
        for(int i =0; i<ins.length(); i++){
            if(ins[i] == 'L'){
                turn--;
            }else if(ins[i]== 'R'){
                turn++;
            }else{
                int finalturn = ((dir[ori] + turn) % 4 + 4) % 4;
                //cout << "finalturn " << numToDir[finalturn] << "\n";
                ori = numToDir[finalturn];
                turn = 0;
                
                if(ori == 'N') {
                    if(y+1>Y){
                        if(losts.count(make_pair(x,y))>0) continue;
                        cout << x << " " << y << " " << ori <<  " LOST\n";
                        losts.insert(make_pair(x,y)); 
                        islost=true;
                        break;
                    }
                    y++;
                }
                else if(ori == 'E'){
                    if(x+1>X){
                        if(losts.count(make_pair(x,y))>0) continue;
                        cout << x << " " << y << " " << ori <<  " LOST\n";
                        losts.insert(make_pair(x,y)); 
                        islost=true;
                        break;
                    }
                    x++;
                } 
                else if(ori == 'S'){
                    if(y-1<0){
                        if(losts.count(make_pair(x,y))>0) continue;
                        cout << x << " " << y << " " << ori << " LOST\n";
                        losts.insert(make_pair(x,y)); 
                        islost=true;
                        break;
                    }
                    y--;
                } 
                else if(ori == 'W'){
                    if(x-1<0){
                        if(losts.count(make_pair(x,y))>0) continue;
                        cout << x << " " << y << " " << ori <<  " LOST\n";
                        losts.insert(make_pair(x,y)); 
                        islost=true;
                        break;
                    }
                    x--;
                } 
            }
        }
        int finalturn = ((dir[ori] + turn) % 4 + 4) % 4;
        ori = numToDir[finalturn];
        if (!islost) cout << x << " " << y << " " << ori <<"\n";
    }
    return 0;
}