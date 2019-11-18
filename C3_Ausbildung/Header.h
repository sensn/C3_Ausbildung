#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#pragma once

#include<stdio.h> /* benötigt für printf() */
#include<conio.h> /* benötigt für kbhit() */

void P1();
void ausgabe(int, int); /* Prototyp für ausgabe() */
void warten(void); /* Prototyp für warten() */

void P2();
int add_person(struct Person* personen, int** entry);
int show_person(struct Person *, int** entry);

