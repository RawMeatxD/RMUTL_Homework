#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode* next;
    struct studentNode* prev; // ??????????????????
};

struct studentNode* AddNode(struct studentNode** start, char* name, int age, char sex, float gpa);
void ShowAll(struct studentNode* walk);
void swap(struct studentNode** start, int A, int B);

int main() {
    struct studentNode* start, * now, ** walk;
    start = NULL;
    AddNode(&start, "one", 6, 'M', 3.11);
    AddNode(&start, "two", 8, 'F', 3.22);
    AddNode(&start, "three", 10, 'M', 3.33);
    AddNode(&start, "four", 12, 'F', 3.44);
    AddNode(&start, "five", 20, 'F', 3.69);

    printf("Before swap : \n");
    ShowAll(start);

    swap(&start, 1, 5);

    printf("After swap : \n");
    ShowAll(start);

    return 0;
}

struct studentNode* AddNode(struct studentNode** start, char* name, int age, char sex, float gpa) {

    while ((*start) != NULL) {
        start = &((*start)->next);
    }

    *start = new struct studentNode;
    strcpy((*start)->name, name);
    (*start)->age = age;
    (*start)->sex = sex;
    (*start)->gpa = gpa;
    (*start)->next = NULL;
    (*start)->prev = NULL; // ??????????????????????????????????? NULL

    return *start;
}

void swap(struct studentNode** start, int A, int B) {
    if (*start == NULL || (*start)->next == NULL) {
        printf("Empty node or less than one node.\n");
        return;
    }
    else if (A == B) {
        printf("Can't swap same position.\n");
        return;
    }

    struct studentNode* currentA = *start;
    for (int i = 1; currentA != NULL && i < A; ++i) {
        currentA = currentA->next;
    }

    struct studentNode* currentB = *start;
    for (int i = 1; currentB != NULL && i < B; ++i) {
        currentB = currentB->next;
    }

    if (currentA == NULL || currentB == NULL) {
        printf("Error.\n");
        return;
    }
    else {

        if (currentA->prev != NULL) {
            currentA->prev->next = currentB;
        }
        else {
            *start = currentB;
        }

        if (currentB->prev != NULL) {
            currentB->prev->next = currentA;
        }
        else {
            *start = currentA;
        }

        struct studentNode* tempNext = currentA->next;
        struct studentNode* tempPrev = currentA->prev;
        currentA->next = currentB->next;
        currentA->prev = currentB->prev;
        currentB->next = tempNext;
        currentB->prev = tempPrev;
    }
}

void ShowAll(struct studentNode* walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

