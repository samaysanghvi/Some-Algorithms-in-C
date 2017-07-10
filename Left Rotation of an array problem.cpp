#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {
long int n,temp;
    scanf("%ld",&n);
    long int d,i=0,j=0,m;
    scanf("%ld",&d);
    long int a[n];
    for(i=0;i<n;i++)
       {
        scanf("%ld",&m);
        a[(n-d+i)%n]=m;
    }
    
    
    
    for(i=0;i<n;i++)
       {
        printf("%ld ",a[i]);
    }
    return 0;
}

