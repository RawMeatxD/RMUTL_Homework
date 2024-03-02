#include <stdio.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
	struct studentNode *next ;
	struct studentNode *back ;
};

class LinkedList {
protected:
    struct studentNode *start, **now;

public:
    LinkedList();
    ~LinkedList();
    void InsNode(char n[], int a, char s, float g);
    void DelNode();
    void GoNext();
    virtual void ShowNode();
};

class NewList : public LinkedList {
public:
    void GoFirst();
    virtual void ShowNode();
};

LinkedList::LinkedList() {
    start = NULL;
    now = &start;
}

LinkedList::~LinkedList() {
    while (start != NULL) {
        struct studentNode *temp = start;
        start = start->next;
        delete temp;
    }
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    struct studentNode *node = new studentNode;
    strcpy(node->name, n);
    node->age = a;
    node->sex = s;
    node->gpa = g;

    node->next = start;
    start = node;
    *now = start;
}

void LinkedList::DelNode() {
    if (start != NULL) {
        struct studentNode *temp = start;
        start = start->next;
        delete temp;
        *now = start;
    }
}

void LinkedList::GoNext() {
    if (*now != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::ShowNode() {
    if (*now != NULL) {
        printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", (*now)->name, (*now)->age, (*now)->sex, (*now)->gpa);
    }
}

void NewList::GoFirst() {
    now = &start;
}

void NewList::ShowNode() {
    struct studentNode *temp = start;
    while (temp != NULL) {
        printf("Name: %s, Age: %d, Sex: %c, GPA: %.2f\n", temp->name, temp->age, temp->sex, temp->gpa);
        temp = temp->next;
    }
}

int main() {
 LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}//end function

