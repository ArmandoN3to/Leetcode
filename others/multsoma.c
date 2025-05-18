#include <stdio.h>

int main(){
    int a,b,soma;
    scanf("%d",&a);
    scanf("%d",&b);
    soma=a;

    for(int i=1;i<b;i++){
        a+=soma;    
    }
    printf("%d\n",a);
    
}