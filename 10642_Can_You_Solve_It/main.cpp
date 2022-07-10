#include <iostream>
using namespace std;

long countStep(int x, int y){
    long level = x+y;
    long ystep = level*(level+1)/2; 
    return ystep+x;
}
int main(){
    int N, x1, y1, x2, y2;
    cin >> N;
    for(int i = 0; i<N; i++){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << "Case " << i+1 << ": " << countStep(x2,y2) - countStep(x1,y1) << "\n";
    }
    return 0;
}