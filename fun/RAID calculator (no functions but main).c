#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int menu();
int roll_a_dice();
int selected_rule_number();
int display_dice_values(int);
int compute_point(int,int,int);
void display_points();
void display_final_points();
int remaining_dice(int,int);

int main(){
	int starting_dice1,starting_dice2,first_turn,second_turn,round,roll_counter,rule_number,dice_left=6,previous_points=0,points;
	srand(time(NULL));
	do{
		int acc_point1=0,acc_point2=0;
		printf("FARKLE STARTS\nDice are rolled by each player to select who will start first:\n");
		starting_dice1=roll_a_dice();
		starting_dice2=roll_a_dice();
		printf("Dice 1 (rolled by player 1): %d    Dice 2 (rolled by player 2): %d\n",starting_dice1,starting_dice2);
		if(starting_dice1>starting_dice2){
			printf("Player 1 is starting!\n\n");
			first_turn=1;
			second_turn=2;
		}else{
			printf("Player 2 is starting!\n\n");
			first_turn=2;
			second_turn=1;
		}
		for(round=1;round<6;round++){
			printf("ROUND %d\n-------------------------\n",round);
			printf("PLAYER %d'S TURN\n\n",first_turn);
			for(roll_counter=0;roll_counter<3;roll_counter++){
				rule_number=select_rule_number();
				points=compute_point(dice_left,rule_number,previous_points);
				previous_points=previous_points+points;
				dice_left=dice_left-remaining_dice(rule_number,points);
			}
			printf("PLAYER %d'S TURN IS OVER!\n",first_turn);
			printf("ROUND %d POINTS: %d\n",round,previous_points);
			acc_point1=acc_point1+previous_points;
			printf("ACCUMULATED POINTS: %d\n\n",acc_point1);
			dice_left=6;
			previous_points=0;
				printf("PLAYER %d'S TURN\n\n",second_turn);
			for(roll_counter=0;roll_counter<3;roll_counter++){
				rule_number=select_rule_number();
				points=compute_point(dice_left,rule_number,previous_points);
				previous_points=previous_points+points;
				dice_left=dice_left-remaining_dice(rule_number,points);
			}
			printf("PLAYER %d'S TURN IS OVER!\n",second_turn);
			printf("ROUND %d POINTS: %d\n",round,previous_points);
			acc_point2=acc_point2+previous_points;
			printf("ACCUMULATED POINTS: %d\n\n",acc_point2);
			dice_left=6;
			previous_points=0;
		}
		printf("\nFINAL RESULT:\n-------------------------\n");
		printf("PLAYER %d: %d POINTS\n",first_turn,acc_point1);
		printf("PLAYER %d: %d POINTS\n",second_turn,acc_point2);
		if(acc_point1>acc_point2)
			printf("\nPLAYER %d IS WINNER! CONGRATULATIONS...\n",first_turn);
		else if(acc_point1<acc_point2)
			printf("\nPLAYER %d IS WINNER! CONGRATULATIONS...\n",second_turn);
		else
			printf("\nNO WINNER! (DRAW) CONGRATULATIONS...\n\n");
		
	}while(menu()-2);
	printf("Goodbye!\n\n\n");
	system("PAUSE");
	return 0;
}

int menu(){
	int option;
	printf("FARKLE GAME!\nChoose one from followings:\n");
	printf("1. Start the game by selecting who will start first\n");
	printf("2. Exit\nOption: ");
	scanf("%d",&option);
	return option;
}
int roll_a_dice(){
	return (rand()%6)+1;
}
int select_rule_number(){
	int rule_number;
	printf("Select rule number: ");
	scanf("%d",&rule_number);
	return rule_number;
}
int display_dice_values(int dice_number){
	int value=roll_a_dice();
	printf("Dice %d: %d    ",dice_number,value);
	return value;
}
int compute_point(int dice_left,int rule_number,int previous_points){
	int points=0,dice_counter,rule_counter,number_of1=0,number_of2=0,number_of3=0,number_of4=0,number_of5=0,number_of6=0,temp_dice_left=dice_left;
	switch(rule_number){
		case 1:
			printf("Dice are rolled:\n");
			dice_counter=1;
			for(;temp_dice_left>0;temp_dice_left--){
				if(display_dice_values(dice_counter)==5)
					points=points+50;
				dice_counter++;
			}
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 2:
			printf("Dice are rolled:\n");
			dice_counter=1;
			for(;temp_dice_left>0;temp_dice_left--){
				if(display_dice_values(dice_counter)==1)
					points=points+100;
				dice_counter++;
			}
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 3:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				if(display_dice_values(dice_counter)==1)
					rule_counter++;
				dice_counter++;
			}
			points=rule_counter/3*300;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 4:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				if(display_dice_values(dice_counter)==2)
					rule_counter++;
				dice_counter++;
			}
			points=rule_counter/3*200;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 5:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				if(display_dice_values(dice_counter)==3)
					rule_counter++;
				dice_counter++;
			}
			points=rule_counter/3*300;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 6:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				if(display_dice_values(dice_counter)==4)
					rule_counter++;
				dice_counter++;
			}
			points=rule_counter/3*400;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 7:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				if(display_dice_values(dice_counter)==5)
					rule_counter++;
				dice_counter++;
			}
			points=rule_counter/3*500;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 8:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				if(display_dice_values(dice_counter)==6)
					rule_counter++;
				dice_counter++;
			}
			points=rule_counter/3*600;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 9:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				switch(display_dice_values(dice_counter)){
					case 1:
						number_of1++;
					break;
					case 2:
						number_of2++;
					break;
					case 3:
						number_of3++;
					break;
					case 4:
						number_of4++;
					break;
					case 5:
						number_of5++;
					break;
					case 6:
						number_of6++;
					break;
				}
				dice_counter++;
			}
			if(number_of1>=4||number_of2>=4||number_of3>=4||number_of4>=4||number_of5>=4||number_of6>=4)
				points=1000;
			else
				points=0;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 10:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				switch(display_dice_values(dice_counter)){
					case 1:
						number_of1++;
					break;
					case 2:
						number_of2++;
					break;
					case 3:
						number_of3++;
					break;
					case 4:
						number_of4++;
					break;
					case 5:
						number_of5++;
					break;
					case 6:
						number_of6++;
					break;
				}
				dice_counter++;
			}
			if(number_of1>=5||number_of2>=5||number_of3>=5||number_of4>=5||number_of5>=5||number_of6>=5)
				points=2000;
			else
				points=0;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 11:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				switch(display_dice_values(dice_counter)){
					case 1:
						number_of1++;
					break;
					case 2:
						number_of2++;
					break;
					case 3:
						number_of3++;
					break;
					case 4:
						number_of4++;
					break;
					case 5:
						number_of5++;
					break;
					case 6:
						number_of6++;
					break;
				}
				dice_counter++;
			}
			if(number_of1>=6||number_of2>=6||number_of3>=6||number_of4>=6||number_of5>=6||number_of6>=6)
				points=3000;
			else
				points=0;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 12:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				switch(display_dice_values(dice_counter)){
					case 1:
						number_of1++;
					break;
					case 2:
						number_of2++;
					break;
					case 3:
						number_of3++;
					break;
					case 4:
						number_of4++;
					break;
					case 5:
						number_of5++;
					break;
					case 6:
						number_of6++;
					break;
				}
				dice_counter++;
			}
			if(number_of1&&number_of2&&number_of3&&number_of4&&number_of5&&number_of6)
				points=1500;
			else
				points=0;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 13:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				switch(display_dice_values(dice_counter)){
					case 1:
						number_of1++;
					break;
					case 2:
						number_of2++;
					break;
					case 3:
						number_of3++;
					break;
					case 4:
						number_of4++;
					break;
					case 5:
						number_of5++;
					break;
					case 6:
						number_of6++;
					break;
				}
				dice_counter++;
			}
			if((number_of1==2||number_of1==0)&&(number_of2==2||number_of2==0)&&(number_of3==2||number_of3==0)&&(number_of4==2||number_of4==0)&&(number_of5==2||number_of5==0)&&(number_of6==2||number_of6==0))
				points=1500;
			else
				points=0;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 14:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				switch(display_dice_values(dice_counter)){
					case 1:
						number_of1++;
					break;
					case 2:
						number_of2++;
					break;
					case 3:
						number_of3++;
					break;
					case 4:
						number_of4++;
					break;
					case 5:
						number_of5++;
					break;
					case 6:
						number_of6++;
					break;
				}
				dice_counter++;
			}
			if((number_of1==4||number_of2==4||number_of3==4||number_of4==4||number_of5==4||number_of6==0)&&(number_of1==0||number_of2==0||number_of3==0||number_of4==0||number_of5==0||number_of6==0))
				points=1500;
			else
				points=0;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		case 15:
			printf("Dice are rolled:\n");
			dice_counter=1;
			rule_counter=0;
			for(;temp_dice_left>0;temp_dice_left--){
				switch(display_dice_values(dice_counter)){
					case 1:
						number_of1++;
					break;
					case 2:
						number_of2++;
					break;
					case 3:
						number_of3++;
					break;
					case 4:
						number_of4++;
					break;
					case 5:
						number_of5++;
					break;
					case 6:
						number_of6++;
					break;
				}
				dice_counter++;
			}
			if((number_of1==3||number_of1==0)&&(number_of2==3||number_of2==0)&&(number_of3==3||number_of3==0)&&(number_of4==3||number_of4==0)&&(number_of5==3||number_of5==0)&&(number_of6==3||number_of6==0))
				points=2500;
			else
				points=0;
			printf("\nPoints: %d\nTotal Points: %d\n",points,points+previous_points);
			printf("%d dice left...\n\n",dice_left-remaining_dice(rule_number,points));
			return points;
		break;
		
		
	}
}
int remaining_dice(int rule_number,int points){
	if(rule_number==1)
		return points/50;
	if(rule_number==2)
		return points/100;
	if(rule_number==3||rule_number==5)
		return points/300;
	if(rule_number==4)
		return points/200;
	if(rule_number==6)
		return points/400;
	if(rule_number==7)
		return points/500;
	if(rule_number==8)
		return points/600;
	if(rule_number==9)
		return points/1000;
	if(rule_number==10)
		return points/2000;
	if(rule_number==11)
		return points/3000;
	if(rule_number==12||rule_number==13||rule_number==14)
		return points/1500;
	if(rule_number==15)
		return points/2500;
	
}









