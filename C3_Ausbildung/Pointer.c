#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

#include "Header.h"
#include <stdio.h>
#include <conio.h>
#include<stdlib.h>

void P1() {
	
	int x = 5, y = 0; /* Initialisierung von "x" und "y" */
	int* zeiger = 0; /* Zeiger Definition und */
/* Initialisierung als Null-Zeiger */
	ausgabe(x, y);
	warten();
	zeiger = &x; /* Der Zeiger erhält die Adresse */
	/* der Variablen "x" */
	y = *zeiger; /* Die Variable "y" erhält den */
	/* Inhalt der Speicherstelle, auf */
	/* die der Zeiger zeigt. */
	ausgabe(x, y);

}
void ausgabe(int x, int y) /* Ausgabe von "x" und "y" */
{
	printf("\n x = %d y = %d \n", x, y);
}
void warten(void)
{
	printf("\n Drücken Sie bitte eine beliebige Taste...\n\n");
	while (!kbhit())
		;
}
void menu(int* button, int* entry, struct Person* personen);

struct Datum {
	int Tag;
    int Monat;
	int Jahr;

};

struct Person {
	char Name[1];
int alter;
	struct Datum datum;

};

//struct Person personen[10];

void P2() {
	int entry=0;
	//*** Dynamische Speicherverwaltung
	int size = 10;
	struct Person* personen;
	personen = (struct Person*)malloc(size * sizeof(struct Person));
	


	int button = 0;
	do {
		button = 0;
		menu(&button,&entry,&personen);
	} while (1);
	
	}


void menu(int* button,int *entry,struct Person* personen) {
		int validInput = 0;
	    

		do {
			//system("cls");

			switch (*button) {
			case 1:
				printf("(1) - Person hinzuf%cgen\n", 129);
				validInput = 1;

				add_person(personen,&entry);
				break;
			case 2:
				printf("(2) - Person anzeigen\n");
				validInput = 1;



				show_person(personen,&entry);
				break;
			case 3:
				printf("(3) - Exit");
				validInput = 1;

				
				exit(0);
				break;
			default:
				printf("Men%causwahl\n", 129);
				printf("Dr%ccken sie 1, 2, oder 3\n", 129);
				printf("(1) - Person hinzuf%cgen\n", 129);
				printf("(2) - Person anzeigen\n");
				printf("(3) - Exit\n");
			}

			if (validInput == 0) {
				*button = (int)getch() - 48;
			}
		//	printf("%d", entry);
		} while (validInput == 0);
}



int add_person(struct Person *personen,int** entry)
{
	for (int i = 0; i < (**entry); i++){
		personen++;
	}

	printf("Name eingeben:");
	fseek(stdin, 0, SEEK_END);
	fgets(personen->Name, 50, stdin);

	/*printf("Alter eingeben:");
	fseek(stdin, 0, SEEK_END);
	scanf_s("%d", &personen->alter);*/
	//fgets(personen->alter, 20, stdin);
	
	
	
	(**entry)++;
	
	return 0;
}

int show_person(struct Person* personen, int** entry) {
	
	
	for (int i = 0; i < (**entry); i++) {

		printf("%s \n", personen->Name);
		//printf("%d", personen->alter);
	
		personen++;
	}
	
	
	_getch();
	return 0;
}




