#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Person {
    char name[50];
    struct Person* parent;
} Person;

int is_ancestor(Person* ancestor, Person* descendant);

int main() {
    /*
    * family members
    */
    Person alice = {"Alice", NULL};
    Person bob = {"Bob", &alice};
    Person charlie = {"Charlie", &bob};
    Person daisy = {"Daisy", &charlie};

    // TODO: Implement below

    return 0;
}

int is_ancestor(Person* ancestor, Person* descendant) {
    // TODO: Implement this function
}
