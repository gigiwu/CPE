#include <iostream>
#include <set>
#include <map>
using namespace std;
int main(){
    int n, m, y, c;
    string s;
    cin >> n;
    set<char> mset{'M', 'R', 'V', 'B'};
    set<char> yset{'Y', 'R', 'B', 'G'};
    set<char> cset{'C', 'V' , 'G' , 'B'};
    while(n-->0 ){
        cin >> m >> y >> c >> s;
        for(int i=0; i<s.length() && m >=0 && y >=0 && c >= 0; i++){
            if(mset.count(s[i]) == 1) m--;
            if(yset.count(s[i]) == 1) y--;
            if(cset.count(s[i]) == 1) c--;
        }
        if(m >=0 && y >=0 && c >= 0) cout <<  "YES " << m << " " << y << " " << c << "\n" ;
        else cout << "NO\n";
    }
    return 0;
}