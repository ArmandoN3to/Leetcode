#include <stdio.h>

int main(){
    int count=0;
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        if(i%2==0){
            count++;
        }
    }
    printf("%d",count);
}