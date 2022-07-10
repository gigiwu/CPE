#include <iostream>
#include <sstream>
using namespace std;

string removespace(string in){
    auto space = count(in.begin(), in.end(),' ');
    remove(in.begin(), in.end(), ' ');
    in.resize(in.length()-space);
    return in;
}
int main(){
    int N, n, c;
    string s;
    int casenum =0;
    while(cin >> N && N != 0){
        cout << "Run #" << ++casenum << ": ";
        cin.ignore();
        stringstream ssinput;
        n = N;
        while(N--){
            getline(cin, s);
            ssinput << s;
        }
        cin >> N;
        cin.ignore();
        c = N;
        stringstream sssolution;
        while(N--){
            getline(cin ,s);
            sssolution << s;
        }
        auto in = ssinput.str();
        auto sol = sssolution.str();
        if (in == sol){
            if(n==c){
                cout << "Accepted " << in.length() << endl;
                continue;
            }else{
                cout << "Presentation Error " << in.length() << endl;
                continue;
            }
        }else{
            auto innospace = removespace(in);
            auto solnospace = removespace(sol);
            if(innospace == solnospace){
                cout << "Presentation Error " << in.length() << endl;
                continue;
            }else{
                cout << "Wrong Answer " << in.length() << endl;
                continue;
            }
        }

    }
}