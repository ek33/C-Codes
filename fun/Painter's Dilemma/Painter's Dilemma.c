#include<stdio.h>

int main(){
	
	int test,wall,b1,b2,i,j,temp,sum;
	char str[1500];
	scanf("%d",&test);
	for(;test>0;test--){
		sum=0;
		scanf("%d",&wall);
		int arr[wall];
		for(j=0;j<wall;j++){
			fscanf(stdin,"%s",str);
			arr[j]=atoi(str);
		}
		b1=arr[0];
		j=1;
		sum++;
		while(1){
			if(arr[j]!=b1){
				b2=arr[j];
				j++;
				//printf("b1=%d b2=%d ",b1,b2);
				sum++;
				break;
			}
			j++;
		}
		for(;j<wall;j++){
			if(arr[j]!=b1&&arr[j]!=b2){
				temp=j+1;
				while(1){
					if(arr[temp]==b1){
						b2=arr[j];
						//printf("b1=%d b2=%d ",b1,b2);
						sum++;
						break;
					}else if(arr[temp]==b2){
						b1=arr[j];
						//printf("b1=%d b2=%d ",b1,b2);
						sum++;
						break;
					}
					temp++;
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
