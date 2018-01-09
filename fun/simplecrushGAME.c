#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

int checkclock(clock_t start){
	clock_t end = clock();
	if (trunc((double)(end - start)) / CLOCKS_PER_SEC >= 180.00)
		return 0;
	else return 1;
}
int randomCandy();
int initializeBoard(int **);
int getCandiesCoordinates(int **,int *);
int checkCandies(int,int,int,int,int **,int *);
int crushCandies(int,int,int,int,int **);
int calculatePoints(int);
void display_board(int **);

int main(){
	srand(time(NULL));
	char again_or_not;
	int **table, i=0,totalPoints=0;
	int *total_points;
	total_points=&totalPoints;
	table=(int**) malloc (sizeof(int*)*7);	//7 represents number of rows
	for(i=0;i<7;i++)
		table[i]=(int*) malloc(sizeof(int)*7); //7 represents number of columns
	
	printf("Welcome to SimpleCrush!\n");
	do{
		*total_points=0;
		printf("\nLet's get started:\n");
		initializeBoard(table);
		clock_t start = clock();
		while (checkclock(start)){
			getCandiesCoordinates(table,total_points);
			display_board(table);
		}
		printf("You run out of time!\n");
		printf("Would you like to play again (Y/N)? ");
		fflush(stdin);
		scanf("%c",&again_or_not);
	}while(again_or_not=='Y'||again_or_not=='y');
	printf("\nSEE YOU AGAIN!\n\n");
	system("pause");
	free(table);
	return 0;
}

int randomCandy(){
	return rand()%5;
}
int initializeBoard(int **table){
	int i,j;
	for(i=0;i<7;i++)
		for(j=0;j<7;j++)
			table[i][j]=randomCandy();
			
	printf("     \t    1  2  3  4  5  6  7\n"); //column numbers of the table
	for(i=0;i<7;i++){
		printf("   \t%d   ",i+1); //row numbers of the table
		for(j=0;j<7;j++){
			if(table[i][j]==0) printf("o  ");
			else if(table[i][j]==1) printf("l  ");
			else if(table[i][j]==2) printf("y  ");
			else if(table[i][j]==3) printf("x  ");
			else if(table[i][j]==4) printf("w  ");
		}
		printf("\n");
	}
	return 0;
}
int getCandiesCoordinates(int **table,int *total_points){
	int r1,c1,r2,c2;
	do{
		printf("Enter the coordinates of candies to crash: ");
		fflush(stdin);
		scanf("(%d,%d) (%d,%d)",&r1,&c1,&r2,&c2);
		
	}while(checkCandies(r1-1,c1-1,r2-1,c2-1,table,total_points));
	
	
	return 0;
}
int checkCandies(int r1,int c1,int r2,int c2,int **table,int *total_points){
	int i,j,points;
	if(r1==r2){
		if(c1>c2){
			for(j=c2;j<=c1;j++){
				if(table[r1][j]!=table[r1][c1]||(c1-c2)==1){
					printf("Sorry cannot crush these candies!\n");
					return 1;
				}
			}
		}else if(c1<c2){
			for(j=c1;j<=c2;j++){
				if(table[r1][j]!=table[r1][c2]||(c2-c1)==1){
					printf("Sorry cannot crush these candies!\n");
					return 1;
				}
			}
		}else{
			printf("Sorry cannot crush these candies!\n");
			return 1;
		}			
	}else if(c1==c2){
		if(r1>r2){
			for(i=r2;i<=r1;i++){
				if(table[i][c1]!=table[r1][c1]||(r1-r2)==1){
					printf("Sorry cannot crush these candies!\n");
					return 1;
				}
			}
		}else if(r1<r2){
			for(i=r1;i<=r2;i++){
				if(table[i][c1]!=table[r2][c1]||(r2-r1)==1){
					printf("Sorry cannot crush these candies!\n");
					return 1;
				}
			}
		}else{
			printf("Sorry cannot crush these candies!\n");
			return 1;
		}
	}else{
		if(r1-r2!=c1-c2&&r1-r2!=c2-c1){
			printf("Sorry cannot crush these candies!\n");
			return 1;
		}else{
			if(r1>r2){
				if(c1>c2){
					for(i=r1,j=c1;i>r2;i--,j--){
						if(table[r2][c2]!=table[i][j]){
							printf("Sorry cannot crush these candies!\n");
							return 1;	
						}
					}
				}else{
					for(i=r1,j=c1;i>r2;i--,j++){
						if(table[r2][c2]!=table[i][j]){
							printf("*Sorry cannot crush these candies!\n");
							return 1;	
						}	
					}
				}
			}else{
				if(c1>c2){
					for(i=r1,j=c1;i<r2;i++,j--){
						if(table[r2][c2]!=table[i][j]){
							printf("Sorry cannot crush these candies!\n");
							return 1;	
						}
					}
				}else{
					for(i=r1,j=c1;i<r2;i++,j++)
						if(table[r2][c2]!=table[i][j]){
							printf("Sorry cannot crush these candies!\n");
							return 1;	
						}
				}
			}
		}
		
	}
	
	points=calculatePoints(crushCandies(r1,c1,r2,c2,table));
	printf("You got %d points!\n",points);
	(*total_points)=points+(*total_points);
	printf("Your total points is %d!\n",*total_points);
	return 0;
}
int crushCandies(int r1,int c1,int r2,int c2,int **table){
	int crushed_candies=0,r,c;
	if(r1==r2){
		if(c1>c2){
			crushed_candies=(c1-c2)+1;
			for(r=r1;r>=1;r--){
				for(c=c2;c<=c1;c++)
					table[r][c]=table[r-1][c];
			}
			for(c=c2;c<=c1;c++)
				table[0][c]=randomCandy();
		}else{
			crushed_candies=(c2-c1)+1;
			for(r=r1;r>=1;r--){
				for(c=c1;c<=c2;c++)
					table[r][c]=table[r-1][c];
			}
			for(c=c1;c<=c2;c++)
				table[0][c]=randomCandy();
		}
	}else if(c1==c2){
		if(r1>r2){
			crushed_candies=(r1-r2)+1;
			for(r=r1;r>=crushed_candies;r--)
				table[r][c1]=table[r-crushed_candies][c1];
			for(r=crushed_candies-1;r>=0;r--)
				table[r][c1]=randomCandy();
		}else{
			crushed_candies=(r2-r1)+1;
			for(r=r2;r>=crushed_candies;r--)
				table[r][c1]=table[r-crushed_candies][c];
			for(r=crushed_candies-1;r>=0;r--)
				table[r][c1]=randomCandy();
		}
	}else{
		if(r1>r2){
			if(c1>c2){
				crushed_candies=(r1-r2)+1;
				for(c=c1;c>=c2;c--){
					for(r=(r1-(c1-c));r>=1;r--)
						table[r][c]=table[r-1][c];
				}
				for(c=c2;c<=c1;c++)
					table[0][c]=randomCandy();
			}else{
				crushed_candies=(r1-r2)+1;
				for(c=c2;c>=c1;c--){
					for(r=(r2+(c2-c));r>=1;r--)
						table[r][c]=table[r-1][c];
				}
				for(c=c1;c<=c2;c++)
					table[0][c]=randomCandy();
			}
		}else{
			if(c1>c2){
				crushed_candies=(r2-r1)+1;
				for(c=c1;c>=c2;c--){
					for(r=(r1+(c1-c));r>=1;r--)
						table[r][c]=table[r-1][c];
				}
				for(c=c2;c<=c1;c++)
					table[0][c]=randomCandy();
			}else{
				crushed_candies=(r2-r1)+1;
				for(c=c2;c>=c1;c--){
					for(r=(r2-(c2-c));r>=1;r--)
						table[r][c]=table[r-1][c];
				}
				for(c=c1;c<=c2;c++)
					table[0][c]=randomCandy();
			}
		}
	}
	return crushed_candies;
}
int calculatePoints(int crashed_candies){
	return crashed_candies*100;
}
void display_board(int **table){
	int i, j;
	printf("     \t    1  2  3  4  5  6  7\n"); //column numbers of the table
	for(i=0;i<7;i++){
		printf("   \t%d   ",i+1); //row numbers of the table
		for(j=0;j<7;j++){
			if(table[i][j]==0) printf("o  ");
			else if(table[i][j]==1) printf("l  ");
			else if(table[i][j]==2) printf("y  ");
			else if(table[i][j]==3) printf("x  ");
			else if(table[i][j]==4) printf("w  ");
		}
		printf("\n");
	}
}
