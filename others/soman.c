#include <stdio.h>

int main(){
    int n=0, i=0 ,soma=0;
    scanf("%d",&n);

    for (i=0; i<=n ;i++){
        soma+=i;
    }
    printf("%d",soma);

    return 0;

}