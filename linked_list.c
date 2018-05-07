#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct person {
	char name[50];
	int age;
	struct person* next;
} node;

typedef void (*callback)(node* data);

node* create(node* next, char name[50], int age) {
	node* new_node = (node*)malloc(sizeof(node));
	if(new_node == NULL) {
		printf("Error creating new node\n");
	}

	strcpy(new_node->name, name);
	new_node->age = age;
	new_node->next = next;
	return new_node;
}

node* prepend(node* head, char name[50], int age) {
	node* new_node = create(head, name, age);
	head = new_node;
	return head;
}

node* append(node* head, char name[50], int age) {
	node* cursor = head;
	while(cursor->next != NULL) {
		cursor = cursor->next;
	}
	
	node* new_node = create(NULL, name, age);
	cursor->next = new_node;

	return head;
}

void traverse(node* head, callback f) {
	node* cursor = head;
	while(cursor != NULL) {
		f(cursor);
		cursor = cursor->next;
	}
}

int count(node* head) {
	node* cursor = head;
	int c = 0;
	while(cursor != NULL) {
		c++;
		cursor = cursor->next;
	}
	return c;
}

node* pos(node* head, int i) {
	node* cursor = head;
	int c = 0;
	while(cursor != NULL) {
		if(c == i)
			break;
		c++;
		cursor = cursor->next;
	}
	return cursor;
}

node* remove_front(node* head) {
	if(head == NULL)
		return NULL;

	node* front = head;
	head = head->next;
	front->next = NULL;
	if(front == head)
		head = NULL;

	free(front);

	return head;
}

node* remove_back(node* head) {
	if(head == NULL)
		return NULL;
	
	node* cursor = head;
	node* back = NULL;

	while(cursor->next == NULL) {
		back = cursor;
		cursor = cursor->next;
	}

	if(back != NULL)
		back->next = NULL;

	if(cursor == head)
		head = NULL;

	free(cursor);

	return head;
}

node* remove_any(node* head, node* nd) {
	if(nd == head) {
		head = remove_front(head);
		return NULL;
	}

	if(nd->next == NULL) {
		head = remove_back(head);
		return head;
	}

	node* cursor = head;

	while(cursor != NULL) {
		if(cursor->next == nd) {
			break;
		}
		cursor = cursor->next;
	}

	if(cursor != NULL) {
		node* tmp = cursor->next;
		cursor->next = tmp->next;
		tmp->next = NULL;
		free(tmp);
	}
	return head;
}

node* insertion_sort(node* head) {
    node *x, *y, *e;
 
    x = head;
    head = NULL;
 
    while(x != NULL) {
        e = x;
        x = x->next;
        if (head != NULL) {
            if(e->age > head->age) {
                y = head;
                while ((y->next != NULL) && (e->age> y->next->age)) {
                    y = y->next;
                }
                e->next = y->next;
                y->next = e;
            }
            else {
                e->next = head;
                head = e ;
            }
        }
        else {
            e->next = NULL;
            head = e ;
        }
    }
    return head;
}


void display(node* n) {
	if(n != NULL) {
		printf("%s ",n->name);
		printf("%d\n",n->age);
	}
}

int size(char* str1) {
	int i = 0;
	while(1) {
		if(str1	[i] == '\0')
			break;
		i++;
	}
	return i;
}

int isEqual(char* str1, char* str2) {
	int i=0;
	int n1 = size(str1);
	if(size(str1) != size(str2))
		return 0;
	else
		for(i=0; i<n1; i++) {
			if(str1[i] != str2[i]) {
				return 0;
			}
		}
	return 1;
}

void menu() {
	printf("********************************************************************************************************************\n");
	printf("**                                Author: Tejeswar Tripathy - Emp ID: 396606                                      **\n");
	printf("********************************************************************************************************************\n");
	printf("********************************************************************************************************************\n");
	printf("**                                             INSTRUCTION                                                        **\n");
	printf("********************************************************************************************************************\n");
	printf("** insert name age - To insert name and age. age is integer; eg.  insert Tejeswar 22                              **\n");
	printf("** print position  - To print a particular node; position is an integer; position starts from one; eg. print 2   **\n");
	printf("** remove position - To remove a particular node; position is an integer; position starts from one; eg. remove 2 **\n");
	printf("** display         - To display the entire list                                                                   **\n");
	printf("**               KEEP IN MIND. THE LIST IS AUTO SORTED. DISPLAY BEFORE REMOVING ANY ITEM.                         **\n");
	printf("********************************************************************************************************************\n");
}
int main() {
	//char* name = (char*)malloc(sizeof(char[50]));
	char name[50];
	int age,i;
	char* command = (char*)malloc(sizeof(char[50]));
	int trigger = 0;
	node* head = NULL;
	node* temp = NULL;
	callback disp = display;
	menu();
	while(1) {
		scanf("%s", command)	;
		if(isEqual(command, "stop") == 1)
			break;
		else if(isEqual(command, "insert") == 1)
			trigger = 1;
		else if(isEqual(command, "print") == 1)
			trigger = 2;
		else if(isEqual(command, "remove") == 1)
			trigger = 3;
		else if(isEqual(command, "display") == 1)
			trigger = 4;
		else
			trigger = 5;
					
		switch(trigger) {
			case 1:
					scanf("%s", name);
					scanf("%d", &age);
					if(count(head) == 0)
						head = prepend(head, name, age);
					else
						head = append(head, name, age);
					head = insertion_sort(head);
					printf("\n");
					break;
					
			case 2:
					scanf("%d", &i);
					i--;
					temp = pos(head,i);
					printf("\n");
					display(temp);
					printf("\n");
					break;
			
			case 3:
					scanf("%d", &i);
					i--;	
					temp = pos(head, i);
					head = remove_any(head, temp);
					head = insertion_sort(head);
					printf("\n");
					break;
					
			case 4:
					printf("\n");
					traverse(head,disp);
					printf("\n");
					break;
					
			case 5:
					menu();
					break;
		}
	}
	
	
	return 0;
}	
