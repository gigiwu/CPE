#include <iostream>
#include <vector>
#include <set>
using namespace std;

class rule {
    public:
        int time, target, end;
        rule(): time(0), target(0), end(0){}
        rule(int time, int duration, int target){
            this->time=time;
            this->target=target;
            this->end=time+duration;
        }
};
int main(){
    int n, source, time, duration, target, ext; 
    cin >> n;
    cout << "CALL FORWARDING OUTPUT" << endl;
    for(int i =0 ;i <n ; i++){
        cout << "SYSTEM " << i+1 << endl; 
        vector<rule> rules[10000];
        while(cin >> source && source != 0){
            cin >> time >> duration >> target;
            rules[source].push_back(rule(time,duration,target));
        }
        while(cin>>time && time != 9000){
            cin >> ext;
            source = ext;
            set<int> called; 

            while(1){
                called.insert(source);
                bool forwarded = false;
                for(auto &v: rules[source]){
                    if(time >= v.time && time <= v.end){
                        source = v.target;
                        forwarded = true;
                        break;
                    }
                }
                if(!forwarded) break;
                if(called.count(source)!=0){
                    source = 9999;
                    break;
                }
            }
            printf("AT %04d CALL TO %04d RINGS %04d\n", time, ext, source);
        }      
    }
    cout << "END OF OUTPUT" << endl;
}