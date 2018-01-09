#include<stdio.h>
#include<stdlib.h>

int main()
{
	int size,i,row,col=0;
	scanf("%d",&size);
	for(i=1;i<=size*(size+1);i++){
		row=(i/(size+1)+1);
		col+=1;
		if(i%(size+1)==0){
			printf("\n");
			col=0;
		}
		else if(row+col>size)
			printf("*");
		else
			printf(" ");
	}
	system("PAUSE");
	return 0;
}
