#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
 char name[ 20 ] ;
 int age ;
 char sex ;
 float gpa ;
 struct studentNode *next ;
 struct studentNode *back ;
} ;

void ShowAll( struct studentNode *walk ) ;
struct studentNode *AddNode(struct studentNode **start, char *name, int age, char sex, float gpa);
void InsNode(struct studentNode *now, char *name, int age, char sex, float gpa);
void DelNode(struct studentNode **now);
void GoBack(struct studentNode **now);

int main() {
 struct studentNode *start, *now ;
 start = NULL ;
 now = AddNode( &start, "one", 6, 'M', 3.11 ) ; ShowAll( start ) ;
 now = AddNode( &start, "two", 8, 'F', 3.22 ) ; ShowAll( start ) ;
 InsNode( now, "three", 10, 'M', 3.33 ) ; ShowAll( start ) ;
 InsNode( now, "four", 12, 'F', 3.44 ) ; ShowAll( start ) ;
 GoBack( &now ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 DelNode( &now ) ; ShowAll( start ) ;
 return 0 ;
}//end function

void ShowAll( struct studentNode *walk ) {
 while( walk != NULL ) {
  printf( "%s ", walk->name ) ;
  walk = walk->next ;
 }//end while
 printf( "\n" ) ;
}//end function

struct studentNode *AddNode(struct studentNode **start, char *name, int age, char sex, float gpa) {
    struct studentNode *node = (struct studentNode *)malloc(sizeof(struct studentNode));

    if (node == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    strcpy(node->name, name);
    node->age = age;
    node->sex = sex;
    node->gpa = gpa;
    node->next = NULL;
    node->back = NULL;

    if (*start == NULL) {
        *start = node;
    } else {
        struct studentNode *temp = *start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = node;
        node->back = temp;
    }

    return node;
}

void InsNode(struct studentNode *now, char *name, int age, char sex, float gpa) {
    struct studentNode *node = (struct studentNode *)malloc(sizeof(struct studentNode));

    if (node == NULL) {
        printf("Memory allocation error.\n");
        exit(1);
    }

    strcpy(node->name, name);
    node->age = age;
    node->sex = sex;
    node->gpa = gpa;

    if (now != NULL) {
        node->next = now;
        node->back = now->back;
        if (now->back != NULL) {
            now->back->next = node;
        }
        now->back = node;
    }
}

void DelNode(struct studentNode **now) {
    if (*now == NULL) {
        printf("Cannot delete. Empty node.\n");
        return;
    }

    struct studentNode *temp = *now;

    if (temp->back != NULL) {
        temp->back->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->back = temp->back;
        *now = temp->next;
    } else {
        *now = temp->back;
    }

    free(temp);
}

void GoBack(struct studentNode **now) {
    if (*now != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}
