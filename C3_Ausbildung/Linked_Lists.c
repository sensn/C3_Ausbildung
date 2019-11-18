#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

//#include <cstddef>
#include<stdio.h> /* benötigt für printf() */
#include<conio.h> /* benötigt für kbhit() */
#include<stdlib.h>


typedef struct node {
	int val;
	struct node* next;
} node_t;


void print_list(node_t* head);
void push_at_end(node_t* head, int val);
void push(node_t** head, int val);
int pop(node_t** head);
int remove_last(node_t* head);
int remove_by_index(node_t** head, int n);
int remove_by_value(node_t** head, int rval);
int LL1();






int LL1() {

	//First Item

	node_t* head = NULL;
	head = malloc(sizeof(node_t));
	if (head == NULL) {
		return 1;
	}

	head->val = 1;
	head->next = NULL;

	// ADD ITEM

	head->next = malloc(sizeof(node_t));
	head->next->val = 2;
	head->next->next = NULL;

	push_at_end(head, 8);
	push_at_end(head, 9);
	push_at_end(head, 10);
	push_at_end(head, 11);
	print_list(head);
	puts("");
	remove_by_value(&head, 11);

	print_list(head);
}

void print_list(node_t* head) {
	node_t* current = head;

	while (current != NULL) {
		printf("%d\n", current->val);
		current = current->next;
	}
}

// Adding an item to the end of the list

void push_at_end(node_t* head, int val) {
	node_t* current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	/* now we can add a new variable */
	current->next = malloc(sizeof(node_t));
	//current->next = NULL;
	current->next->val = val;
	current->next->next = NULL;
}

//Adding an item to the beginning of the list (pushing to the list)

/* 1 Create a new itemand set its value
   2 Link the new item to point to the head of the list
   3 Set the head of the list to be our new item*/

void push(node_t** head, int val) {
	node_t* new_node;
	new_node = malloc(sizeof(node_t));

	new_node->val = val;
	new_node->next = *head;
	*head = new_node;
}

// Removing the first item(popping from the list)

//To pop a variable, we will need to reverse this action:

//  1 Take the next item that the head points toand save it
//  2 Free the head item
//  3 Set the head to be the next item that we've stored on the side

int pop(node_t** head) {
	
	int retval = -1;
	node_t* next_node = NULL;

	if (*head == NULL) {
		return -1;
	}

	next_node = (*head)->next;
	retval = (*head)->val;
	free(*head);
	*head = next_node;

	return retval;
}

// 
int remove_last(node_t* head) {
	int retval = 0;
	/* if there is only one item in the list, remove it */
	if (head->next == NULL) {
		retval = head->val;
		free(head);
		return retval;
	}

	/* get to the second to last node in the list */
	node_t* current = head;
	while (current->next->next != NULL) {
		current = current->next;
	}

	/* now current points to the second to last item of the list, so let's remove current->next */
	retval = current->next->val;
	free(current->next);
	current->next = NULL;
	return retval;
}

int remove_by_index(node_t** head, int n) {
	int i = 0;
	int retval = -1;
	node_t* current = *head;
	node_t* temp_node = NULL;

	if (n == 0) {
		return pop(head);
	}

	for (i = 0; i < n - 1; i++) {
		if (current->next == NULL) {
			return -1;
		}
		current = current->next;
	}

	temp_node = current->next;
	retval = temp_node->val;
	current->next = temp_node->next;
	free(temp_node);

	return retval;

}


//int remove_by_value(node_t** head, int rval) {
//	node_t* current = *head;
//	node_t* temp_node = NULL;
//	int retval = -1;
//
//	while (current->val != rval) {
//	//	temp_node = current;
//		current = current->next;
//	}
//
//	temp_node = current->next;
//	//retval = temp_node->val;
//	current->next = temp_node->next;
//	free(temp_node);
//}

int remove_by_value(node_t** head, int rval) {
	node_t* current = *head;


	
	if ((*head)->val == rval) {
		*head = current->next;
		free(current);
	}else{
		node_t* pAct = *head;
		while (pAct->next != NULL){

			if (pAct->next->val == rval) {

				if (pAct->next->next != NULL) {
					node_t* temp = pAct->next;
					pAct->next = pAct->next->next;
					free(temp);
				}
				else {
					free(pAct->next);
					pAct->next = NULL;
				}
				break;
			}

			pAct = pAct->next;
		}

	}
	
}