#include<stdio.h>
int main(){
    printf("Matrix 1\n");
    int c1;
    printf("enter row in matrix 1and 2\n");
    scanf("%d",&c1);
    int T1[c1][3];
    printf("Enter elements in tuple form\n");
    
    for(int i=0;i<c1+1;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&T1[i][j]);
        }
    }
    
    
    printf("\nMatrix 2\n");
    int T2[c1][3];
    printf("Enter elements in tuple form\n");
    for(int i=0;i<c1+1;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&T2[i][j]);
        } 
    }
   
    printf("\nMatrix 3\n");
    int T3[2*c1][3];
    
    T3[0][0]= T1[0][0];
    T3[0][1]= T1[0][1];
    T3[0][2]= T1[0][2] ;

    int i=1;
    int j=1;
    int k=1;

    while(i<(c1+1) && j<(c1+1)){
        
        if(T1[i][0]<T2[j][0]){
            T3[k][0]=T1[i][0];
            T3[k][1]=T1[i][1];
            T3[k][2]=T1[i][2];
        
            i++;
        }
        else if(T1[i][0]==T2[j][0] ){
            if(T1[i][1]<T2[j][1]){
                T3[k][0]=T1[i][0];
                T3[k][1]=T1[i][1];
                T3[k][2]=T1[i][2];
                i++;
                
            }
            else if(T1[i][1]==T2[j][1]){
                T3[k][0]=T1[i][0];
                T3[k][1]=T1[i][1];
                T3[k][2]=T2[j][2] + T1[i][2];
            
                j++;
                i++;
            } 
            else{
                T3[k][0]=T2[j][0];
                T3[k][1]=T2[j][1];
                T3[k][2]=T2[j][2];
                j++;
            } 
        }
        else {
            T3[k][0]=T2[j][0];
            T3[k][1]=T2[j][1];
            T3[k][2]=T2[j][2];
            j++;
        }
        k++;
    }
    while(i<(c1+1)) {
        T3[k][0] = T1[i][0];
        T3[k][1] = T1[i][1];
        T3[k][2] = T1[i][2];
        i++;
        k++;
    }
    while(j<(c1+1)){
        T3[k][0] = T2[j][0];
        T3[k][1] = T2[j][1];
        T3[k][2] = T2[j][2];
        j++;
        k++;
    }
    
    printf("After addition\n");
    for(int i=0;i<k;i++){
       
        for(int j=0;j<3;j++){
            printf("%d\t",T3[i][j]);
        }
        printf("\n");
    }

}