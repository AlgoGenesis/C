#include<stdio.h>
struct data{
	int min;
	int max;
};
struct data DAC_Min_Max(int a[],int i,int j){
	int mid;
	struct data mm,mm1,mm2;
	if(i==j){
		mm.max=a[i];
		mm.min=a[i];
		return mm;
	}
	else if(i==j-1){
		if(a[i]<a[j]){
		mm.max=a[j];
		mm.min=a[i];
		}
		else{
		mm.max=a[i];
		mm.min=a[j];
		}
	return mm;
	}
	mid=(i+j)/2;
	mm1=DAC_Min_Max(a,i,mid);
	mm2=DAC_Min_Max(a,mid+1,j);
	if(mm1.max<mm2.max)
		mm.max=mm2.max;
	else
		mm.max=mm1.max;
	if(mm1.min<mm2.min)
		mm.min=mm1.min;
	else
		mm.min=mm2.min;
	return mm;
}
int main(){
    int n, a[50], i;
    struct data MinMax;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);
    MinMax = DAC_Min_Max(a, 0, n-1);
    printf("The maximum value is: %d\n", MinMax.max);
    printf("The minimum value is: %d", MinMax.min);
    return 0;
}	
