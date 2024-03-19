#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

typedef struct studentNode StudentNode;

struct LinkedList {
    StudentNode *start, **now;
};

typedef struct LinkedList LinkedList;

void InsNode(LinkedList *ll, char n[], int a, char s, float g) {
    StudentNode *newNode = (StudentNode *)malloc(sizeof(StudentNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;

    *(ll->now) = newNode;
    ll->now = &(newNode->next);
}

void DelNode(LinkedList *ll, char n[]) {
    StudentNode *current = ll->start;
    StudentNode *previous = NULL;

    while (current != NULL && strcmp(current->name, n) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        printf("Student not found.\n");
        return;
    }

    if (previous == NULL) {
        ll->start = current->next;
    } else {
        previous->next = current->next;
    }

    free(current);
    printf("Student deleted successfully.\n");
}


void ShowAll(LinkedList *ll) {
    StudentNode *temp = ll->start;
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
}
void EditNode(LinkedList *ll, char n[], int a, char s, float g) {
    StudentNode *temp = ll->start;
    while (temp != NULL) {
        if (strcmp(temp->name, n) == 0) {
            temp->age = a;
            temp->sex = s;
            temp->gpa = g;
            printf("Data edited successfully.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student not found.\n");
}
void EditData(LinkedList *ll) {
    char name[20];
    int age;
    char sex;
    float gpa;

    printf("Enter the name of the student you want to edit: ");
    scanf("%s", name);
    printf("Enter new age: ");
    scanf("%d", &age);
    printf("Enter new sex (M/F): ");
    scanf(" %c", &sex);
    printf("Enter new GPA: ");
    scanf("%f", &gpa);

    EditNode(ll, name, age, sex, gpa);
}


int main() {
    LinkedList listA;
    listA.start = NULL;
    listA.now = &(listA.start);

    int menu;
    printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
    scanf("%d", &menu);
    while (menu != 0) {
        switch (menu) {
            case 1: {
                char name[20];
                int age;
                char sex;
                float gpa;

                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter age: ");
                scanf("%d", &age);
                printf("Enter sex (M/F): ");
                scanf(" %c", &sex);
                printf("Enter GPA: ");
                scanf("%f", &gpa);

                InsNode(&listA, name, age, sex, gpa);
                break;
            }
            case 2:
                EditData(&listA);
                break;
            case 3:
            	char name[20];
                DelNode(&listA, name);
                break;
            case 4:
                int FindNode(LinkedList *ll, char n[]) {
				    StudentNode *temp = ll->start;
				    int index = 0;
				    while (temp != NULL) {
				        if (strcmp(temp->name, n) == 0) {
				            return index;
				        }
			        temp = temp->next;
			        index++;
			   		}
			   		return -1;
				}
                break;
            case 5:
                ShowAll(&listA);
                break;
        }
        printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
        scanf("%d", &menu);
    }
    


    return 0;
}
