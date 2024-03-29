// A complete working C program to demonstrate all insertion methods 
#include <stdio.h> 
#include <stdlib.h> 

// A linked list node 
struct Node {
	int data;
	struct Node* next;
	struct Node* prev;
};

/* Given a reference (pointer to pointer) to the head of a list
   and an int, inserts a new node on the front of the list. */
void dll_push(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. Make next of new node as head and previous as NULL */
	new_node->next = (*head_ref);
	new_node->prev = NULL;

	/* 4. change prev of head node to new node */
	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	/* 5. move the head to point to the new node */
	(*head_ref) = new_node;
}

/* Given a node as prev_node, insert a new node after the given node */
void insertAfter(struct Node* prev_node, int new_data)
{
	/*1. check if the given prev_node is NULL */
	if (prev_node == NULL) {
		printf("the given previous node cannot be NULL");
		return;
	}

	/* 2. allocate new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* 3. put in the data  */
	new_node->data = new_data;

	/* 4. Make next of new node as next of prev_node */
	new_node->next = prev_node->next;

	/* 5. Make the next of prev_node as new_node */
	prev_node->next = new_node;

	/* 6. Make prev_node as previous of new_node */
	new_node->prev = prev_node;

	/* 7. Change previous of new_node's next node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

/* Given a reference (pointer to pointer) to the head
   of a DLL and an int, appends a new node at the end  */
void append(struct Node** head_ref, int new_data)
{
	/* 1. allocate node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	struct Node* last = *head_ref; /* used in step 5*/

	/* 2. put in the data  */
	new_node->data = new_data;

	/* 3. This new node is going to be the last node, so
		  make next of it as NULL*/
	new_node->next = NULL;

	/* 4. If the Linked List is empty, then make the new
		  node as head */
	if (*head_ref == NULL) {
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}

	/* 5. Else traverse till the last node */
	while (last->next != NULL)
		last = last->next;

	/* 6. Change the next of last node */
	last->next = new_node;

	/* 7. Make last node as previous of new node */
	new_node->prev = last;

	return;
}

void insertBefore(struct Node** head, struct Node* next_node, int new_data)
{
	if (next_node == NULL)
	{
		puts("Next node cannot be NULL");
		return;
	}

	struct Node* new_node = malloc(sizeof(struct Node));
	new_node->data = new_data;

	new_node->prev = next_node->prev;
	new_node->next = next_node;
	next_node->prev = new_node;

	if (new_node->prev != NULL) new_node->prev->next = new_node;
	else (*head) = new_node; // given node is head, so modify head with the newly created node
}



// This function prints contents of linked list starting from the given node 
void printList(struct Node* node)
{
	struct Node* last = NULL;
	printf("\nTraversal in forward direction \n");
	while (node != NULL) {
		printf(" %d ", node->data);
		last = node;
		node = node->next;
	}

	printf("\nTraversal in reverse direction \n");
	while (last != NULL) {
		printf(" %d ", last->data);
		last = last->prev;
	}
}
int insert_by_index(struct Node** head, int n,int new_data) {

	
	

	/* 2. allocate new node */
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));

	/* 3. put in the data  */
	new_node->data = new_data;


 struct Node* current = *head;
 struct Node* temp_node = NULL;

	if (n == 0) {
		dll_push(head, new_data);
		//printf("PREPEND");
		return 1;
	}

	for (int i = 0; i < n - 1; i++) {
		if (current->next == NULL) {
			return -1;
		}
		current = current->next;
	}


	/* 4. Make next of new node as next of prev_node */
	new_node->next = current->next;

	/* 5. Make the next of prev_node as new_node */
	current->next = new_node;

	/* 6. Make prev_node as previous of new_node */
	new_node->prev = current;

	/* 7. Change previous of new_node's next node */
	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}



/* Driver program to test above functions*/
int DLL_main()
{
	/* Start with the empty list */
	struct Node* head = NULL;

	// Insert 6.  So linked list becomes 6->NULL 
	append(&head, 6);

	// Insert 7 at the beginning. So linked list becomes 7->6->NULL 
	dll_push(&head, 7);

	// Insert 1 at the beginning. So linked list becomes 1->7->6->NULL 
	dll_push(&head, 1);

	// Insert 4 at the end. So linked list becomes 1->7->6->4->NULL 
	append(&head, 4);

	// Insert 8, after 7. So linked list becomes 1->7->8->6->4->NULL 
	insertAfter(head->next, 8);
	insertBefore(&head,head->next->next, 17);

	insert_by_index(&head, 6, 27);
	insert_by_index(&head, 0, 27);
	
	printf("Created DLL is: ");
	printList(head);
	puts("");
	getch();
	return 0;
}