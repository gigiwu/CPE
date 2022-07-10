#include <iostream>
using namespace std;

int main(){
    int T, N, M, a, b, tmp;
    long row;
    cin >> T;
    for(int i = 0; i< T ; i++){
        cin >> N;
        int mt[N][N];
        for(int j=0; j< N; j++){           
            cin >> row;
            for(int n=N-1; n>=0; n--){
                mt[j][n] = row % 10;
                row /=10;
            }
        }
        cin >> M;
        string op[M];
        int oparg[M][2];
        string cmd;
        for(int k = 0; k< M ; k++){
            cin >> cmd;
            if(cmd == "row"){
                cin >> a >> b;
                --a;
                --b;
                for (int j = 0; j<N;j++){
                    tmp = mt[a][j];
                    mt[a][j] = mt[b][j];
                    mt[b][j] = tmp;
                }
            } else if (cmd == "col"){
                cin >> a >> b;
                --a; --b;
                for (int j = 0; j<N;j++){
                    tmp = mt[j][a];
                    mt[j][a] = mt[j][b];
                    mt[j][b] = tmp;
                }

            } else if (cmd == "inc"){
                for(int j = 0; j < N; j ++){
                    for (int n =0; n<N ; n ++){
                        mt[j][n] += 1;
                        mt[j][n] %= 10;
                    }
                }
            } else if (cmd == "dec"){
                for(int j = 0; j < N; j ++){
                    for (int n =0; n<N ; n ++){
                        mt[j][n] -= 1;
                        if(mt[j][n] < 0) mt[j][n] +=10;
                    }
                }
            } else{
                for(int j = 0; j < N; j ++){
                    for (int n =0; n<N && n < j; n ++){
                        tmp = mt[j][n];
                        mt[j][n] = mt[n][j];
                        mt[n][j] = tmp;
                    }
                }
            }
        }
        cout << "Case #" << i+1 << "\n";
        for(int j = 0; j < N; j ++){
            for (int n =0; n<N ; n ++){
                cout << mt[j][n];
            }
            cout << "\n";
        }
    }
    return 0;
}