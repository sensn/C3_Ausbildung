#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma once

#include<stdio.h> /* ben�tigt f�r printf() */
#include<conio.h> /* ben�tigt f�r kbhit() */

void P1();
void ausgabe(int, int); /* Prototyp f�r ausgabe() */
void warten(void); /* Prototyp f�r warten() */

void P2();
int add_person(struct Person* personen, int** entry);
int show_person(struct Person *, int** entry);

