#include<stdio.h>

int main(){
	int matrix1[3][2]={2,4,5,2,8,5};
	int matrix2[2][3]={4,7,5,6,4,2};
	int sonuc[3][3];
	int i, j, k, elem;
	
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			for(k=0,elem=0;k<2;k++){
				elem=elem+matrix1[i][k]*matrix2[k][j];
			}
			sonuc[i][j]=elem;
			printf("%d ",sonuc[i][j]);
		}
		printf("\n");
	}
	return 0;
}
