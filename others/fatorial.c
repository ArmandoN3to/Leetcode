#include <stdio.h>

int main(){
    int n,fatorial;
    scanf("%d",&n);
    printf("antes loop: %d\n",n);

    fatorial=n;
    
    for(int i=1; i<=fatorial; i++){
        n=n*i;  
        printf("%d\n",n);
    }
    printf("Final: %d\n",n);
    
}