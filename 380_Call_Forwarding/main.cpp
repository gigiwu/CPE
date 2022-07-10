#include <iostream>
#include <vector>
#include <set>
using namespace std;

void printdigit(int d){
    int s[4] = {0};
    for(int i=3; i>=0; i--){
        s[i] = d % 10;
        d= d/10;
    }
    for(int &i : s){
        cout << i;
    }

}

int main(){
    int n, source, time, duration, target, ext; 
    cin >> n;
    cout << "CALL FORWARDING OUTPUT" << endl;
    for(int i =0 ;i <n ; i++){
        cout << "SYSTEM " << i+1 << endl; 

        vector<pair<pair<long,long>, int>> fvec;
        while(cin >> source){
            if(source == 0) break;
            cin >> time >> duration >> target;
            int end = time + duration;
            long starttime = (long)source*10000+(long)time;
            long endtime = (long)source*10000+(long)end;
            fvec.push_back(make_pair(make_pair(starttime,endtime), target));
        }
        while(cin>>time){
            if(time == 9000) break;
            cin >> ext;
            cout << "AT ";
            printdigit(time);
            cout << " CALL TO ";
            printdigit(ext);
            cout << " RINGS ";
            int source = ext;
            bool forwarded=false;
            set<int> called; 
            while(1){
                called.insert(source);
                for(auto& v: fvec){
                    long sourcetime = (long)source*10000+time;
                    auto start = v.first.first;
                    auto end = v.first.second;
                    auto target = v.second;
                    if(sourcetime >= start && sourcetime <= end){
                        source = target;
                        forwarded = true;
                        break;
                    }
                    forwarded = false;
                }
                
                if(!forwarded) break;
                if(forwarded && called.count(source)!=0){
                    source = 9999;
                    break;
                }
            }
            printdigit(source);
            cout << endl;
        }
        
    }
    cout << "END OF OUTPUT" << endl;
}