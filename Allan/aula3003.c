#include <stdio.h>

int x, i, n, j, k;

int main()
{    
x = 0;  //1
for(i=0;i<n;i++){ // n
  for(j=1;j<=n;j=j*2){ // n(log1n+1)
    x = x + i + j; // n(log2n+1)
    }
  }
printf("%d",x); // 1

  // t(n) = 2 + n + 2n log2n +2n
  // o(n logn)
}

int caso2()
{  
x=0; // 1
for(i=0;i<n;i=i+2){ // n div 2
  for(j=n;j>1;j=j/2){ // n/2*log2n
    x=x+i+j; // n/2*log2n
  }
}
printf("%d",x); // 1

  //??
  // o(n logn)
 
}

int caso3()
{  
x=0; // 1
for(i=0;i<n;i=i+3){ // n/3
  for(j=1;j<n;j=j*4){ // n/3*log4n
    for(k=0;k<n;k++){ // n*n/3*log4n
      x=x+i+j+k; // n*n/3*log4n
}
}
}
printf("%d",x); // 1

  // t(n) = 2n * n/3 * log4n + n/3 * log4n + n/3 +2
  // 0(n2 logn)
 }

int caso4()
{  
x=0; // 1
for(i=0;i<n;i=i+2){ // n/2
  for(j=i;j<n;j++){ // n/2(n+1) / 2
      x=x+i+j; // n
}
}
}
printf("%d",x); // 1

  // 
  // o(n^2)
 }