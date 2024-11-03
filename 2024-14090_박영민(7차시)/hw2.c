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

    char name1[50],name2[50];
    scanf("%s %s",name1,name2);

    Person *p1=NULL, *p2=NULL;
    
    if(strcmp(name1, alice.name)==0) p1=&alice;
    else if(strcmp(name1, bob.name)==0) p1=&bob;
    else if(strcmp(name1, charlie.name)==0) p1=&charlie;
    else if(strcmp(name1, daisy.name)==0) p1=&daisy;

    if(strcmp(name2, alice.name)==0) p2=&alice;
    else if(strcmp(name2, bob.name)==0) p2=&bob;
    else if(strcmp(name2, charlie.name)==0) p2=&charlie;
    else if(strcmp(name2, daisy.name)==0) p2=&daisy;

    if(is_ancestor(p1,p2)) printf("%s is an ancestor of %s",name1, name2);
    else printf("%s is not an ancestor of %s",name1, name2);



    return 0;
}

int is_ancestor(Person* ancestor, Person* descendant) {
    // TODO: Implement this function
    if(descendant == NULL) return 0;
    if(descendant == ancestor) return 1;
    return is_ancestor(ancestor, descendant->parent);

}
