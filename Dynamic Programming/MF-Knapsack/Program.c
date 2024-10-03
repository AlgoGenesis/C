#include <stdio.h>
#include <stdlib.h>

int max(int i, int j){
 return (i>j) ? i : j;
}

int t[100][100], v[100], w[100], n, m, i, j;

int knap(int i, int j){
 if (t[i][j]==-1){
  if (j<w[i])
   t[i][j] = knap(i-1,j);
 else
   t[i][j] = max(knap(i-1,j),v[i]+knap(i-1,j-w[i]));
}
   return t[i][j];
}


void main(){
printf("No. of Items>> ");
scanf("%d",&n);
printf("Sack Capacity>> ");
scanf("%d",&m);
printf("Weight\tValue\n");
for(i=1;i<n+1;i++){scanf("%d\t%d",&w[i],&v[i]);
}


for(i=0;i<n+1;i++){
  for(j=0;j<m+1;j++){
    if (i==0||j==0)
      t[i][j]=0;
    else
      t[i][j]=-1;
  }
}

printf("Maximum Value: %d\n",knap(n,m));
for(int i=0;i<n+1;i++){
  for(int j=0;j<m+1;j++)
    printf("%d ",t[i][j]);
    printf("\n");
}
//  to print which are the sacks added 
printf("Composition:\n");
for(i=n;i>0;i--){
 if (t[i][m] != t[i-1][m]){
  printf("%d ",i);
   m = m-w[i];
  }
}
 printf("\n");
}
