#include<stdio.h>
void countpage(int num){
    int sum=0;
    int i=0;
    while(sum<num+1){
        sum+=(++i); 
    }
    int page = sum - num;
    printf("%d %d\n", page, i);
}

int main(){
    int num = 0;
    while(1) {
        scanf("%d", &num);
        if(num == 0) break;
        countpage(num);
    }
    return 0;
}

