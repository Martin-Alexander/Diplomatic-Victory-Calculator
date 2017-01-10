#include <stdio.h>

#include <stdlib.h>

#include <math.h>
#include <stdbool.h>
#include <conio.h>
#include <ctype.h>
#include <windows.h>
#include <wincon.h>

void Gotoxy(int x, int y) {

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}


int main(){

	bool status = true;
	char userInput[256];
	int PlayersAlive, PlayersDead, CityStatesAlive, CityStatesDead;
	int reqDel;
	int host, FP, religion, ideology, allies, diplo, prev, del, text, exit;	
	
	printf("\n Based on input about your Civ 5 game this app will\n"
		" calculate how many delegates are needed for a diplomatic\n"
		" victory as well as how many delegates you possess.\n");



	while(status == true){

		printf("\n Would you like to continue with added explainations of how\n"
			" diplomatic victory conditions and delegates are calculated? [Y/N] ");
		fgets(userInput, 256, stdin);

		if((userInput[0] == 'y' || userInput[0] == 'Y') && userInput[1] == '\n'){
			text = 1;
			break;
			}
		else if((userInput[0] == 'n' || userInput[0] == 'N') && userInput[1] == '\n'){
			text = 0;
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}
	}

	system("cls");
	Gotoxy(0, 0);

	while(status == true){

	if(text ==1)
	printf("\n Two win a diplomatic victory you must be voted World\n"
		" Leader by players in the United Nations. The United\n"
		" Nations is founded once a player enters the Information\n"
		" Era or once half the players enter the Atomic Era.\n"
		" Then, every 20 turns a vote is held wherein each player\n"
		" is given a number of delegates with which to vote for\n"
		" any player (including themselves) as World Leader. For a\n"
		" player to be elected World Leader (and thus win the\n"
		" game) they must accumulate a certain minimum number of\n"
		" votes.\n\n"
		" There are many factors that influence 1) how many\n"
		" delegates you are assigned, and 2) how many votes are\n"
		" required to be elected World Leader. This app will ask\n"
		" you for the required information and then calculate both\n"
		" these numbers.\n");
	
	if(text ==1)
	printf("\n Press any key to continue.");

	if(text ==1){
	_getch();
	system("cls");
	Gotoxy(0, 0);
	}

	if(text ==1)
	printf("\n First, we will determine the minimum amount of delegates\n"
		" required to be elected world leader. This is based on\n" 
		" four variables: The amount of players alive, the amount\n"
		" of players dead, the amount of city-states alive, and\n"
		" the amount of city-states dead.\n");

	if(text ==1)
	printf("\n Press any key to continue.");


	if(text ==1){
	_getch();
	system("cls");
	Gotoxy(0, 0);
	}

	while(status == true){
		printf("\n How many players are alive?: ");
		fgets(userInput, 256, stdin);
	
		if(isdigit(userInput[0])){
			PlayersAlive = atoi(userInput);
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}	
	}

	while(status == true){
		printf("\n How many players are dead?: ");
		fgets(userInput, 256, stdin);
	
		if(isdigit(userInput[0])){
			PlayersDead = atoi(userInput);
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}	
	}

	while(status == true){
		printf("\n How many city-states are alive?: ");
		fgets(userInput, 256, stdin);
	
		if(isdigit(userInput[0])){
			CityStatesAlive = atoi(userInput);
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}	
	}

	while(status == true){
		printf("\n How many city-states are dead?: ");
		fgets(userInput, 256, stdin);
	
		if(isdigit(userInput[0])){
			CityStatesDead = atoi(userInput);
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}	
	}

	reqDel = floor(1.443 * log(PlayersAlive + 0.5 * PlayersDead) + 7 + 16.023 * log(CityStatesAlive + 0.5 * CityStatesDead) - 13.758);

	printf("\n Players Alive: %d", PlayersAlive);
	printf("\n Players Dead: %d", PlayersDead);
	printf("\n City States Alive: %d", CityStatesAlive);
	printf("\n City States Dead: %d", CityStatesDead);



	printf("\n\n Number of delegates required to be elected World Leader: %d\n", reqDel);

	printf("\n Press any key to continue.");


	if(text ==1){
	_getch();
	system("cls");
	Gotoxy(0, 0);
	}

	if(text ==1)
	printf("\n Now we will determine the amount of delegates you have.\n\n"
		" Again, this is based on several factors:\n" 
		" You recieve four delegates just for being a member\n"
		" of the United Nations\n"
		" Two if you're the host of the United Nations\n"
		" Two if you own The Forbidden Palace\n"
		" Two if your religion is World Religion\n"
		" Two if your ideology is World Ideology\n"
		" Two for every city-state ally that you have\n"
		" One for every diplomat you have in another player's\n"
		" capital once Globalization has been researched\n"
		" And two for each time a World Leader vote was called\n" 
		" and you recieved the most or second most delegates\n");

	if(text ==1)
	printf("\n Press any key to continue.");

	_getch();
	system("cls");
	Gotoxy(0, 0);

	while(status == true){

		printf("\n Are you the host of the United Nations? [Y/N]: ");
		fgets(userInput, 256, stdin);

		if((userInput[0] == 'y' || userInput[0] == 'Y') && userInput[1] == '\n'){
			host = 2;
			break;
			}
		else if((userInput[0] == 'n' || userInput[0] == 'N') && userInput[1] == '\n'){
			host = 0;
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}
	}

	while(status == true){

		printf("\n Do you own The Forbidden Palace? [Y/N]: ");
		fgets(userInput, 256, stdin);

		if((userInput[0] == 'y' || userInput[0] == 'Y') && userInput[1] == '\n'){
			FP = 2;
			break;
			}
		else if((userInput[0] == 'n' || userInput[0] == 'N') && userInput[1] == '\n'){
			FP = 0;
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}
	}

	while(status == true){

		printf("\n Is your religion World Religion? [Y/N]: ");
		fgets(userInput, 256, stdin);

		if((userInput[0] == 'y' || userInput[0] == 'Y') && userInput[1] == '\n'){
			religion = 2;
			break;
			}
		else if((userInput[0] == 'n' || userInput[0] == 'N') && userInput[1] == '\n'){
			religion = 0;
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}
	}

	while(status == true){

		printf("\n Is your ideology World Ideology? [Y/N]: ");
		fgets(userInput, 256, stdin);

		if((userInput[0] == 'y' || userInput[0] == 'Y') && userInput[1] == '\n'){
			ideology = 2;
			break;
			}
		else if((userInput[0] == 'n' || userInput[0] == 'N') && userInput[1] == '\n'){
			ideology = 0;
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}
	}
	
	while(status == true){
		printf("\n How many city-state allies do you have?: ");
		fgets(userInput, 256, stdin);
	
		if(isdigit(userInput[0])){
			allies = atoi(userInput);
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}	
	}			
		
	while(status == true){

		printf("\n Have you researched Globalization? [Y/N]: ");
		fgets(userInput, 256, stdin);

		if((userInput[0] == 'y' || userInput[0] == 'Y') && userInput[1] == '\n'){
			
			while(status == true){		
				printf("\n How many diplomats do you have in other player's capitals?: ");
				fgets(userInput, 256, stdin);
	
				if(isdigit(userInput[0])){
					diplo = atoi(userInput);
					break;
					}
				else{
					printf(" ERROR: Invalid input");
					}	
				}	
			break;
			}
		else if((userInput[0] == 'n' || userInput[0] == 'N') && userInput[1] == '\n'){
			diplo = 0;
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}
	}

	while(status == true){
		printf("\n In how many previous World Leader votes have you been\n"
			" among the top two in terms of delegates?: ");
		fgets(userInput, 256, stdin);
	
		if(isdigit(userInput[0])){
			prev = atoi(userInput);
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}	
	}

	system("cls");
	Gotoxy(0, 0);

	del = 4 + host + FP + religion + ideology + (allies * 2) + diplo + (prev * 2);
	
	printf("\n You have %d delegates\n", del);

	printf("\n This is in comparison to the %d delegates needed to be\n" 
	" elected World Leader\n", reqDel);

	
	while(status == true){

		printf("\n Would you like to preform another calculation? [Y/N]? ");
		fgets(userInput, 256, stdin);

		if((userInput[0] == 'y' || userInput[0] == 'Y') && userInput[1] == '\n'){
			exit = 0;
			break;
			}
		else if((userInput[0] == 'n' || userInput[0] == 'N') && userInput[1] == '\n'){
			exit = 1;
			break;
			}
		else{
			printf(" ERROR: Invalid input");
			}
	}
	
	if(exit == 1)
		break;
	
	system("cls");
	Gotoxy(0, 0);

	}

	return 0;

}
