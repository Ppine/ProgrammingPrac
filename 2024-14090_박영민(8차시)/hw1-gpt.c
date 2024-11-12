#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Student {
    char name[MAX_NAME_LEN];
    int score;
    struct Student *next;
} Student;

Student* create_student(const char *name, int score) {
    Student *new_student = (Student*)malloc(sizeof(Student));
    if (new_student) {
        strncpy(new_student->name, name, MAX_NAME_LEN - 1);
        new_student->name[MAX_NAME_LEN - 1] = '\0'; // Null-terminate
        new_student->score = score;
        new_student->next = NULL;
    }
    return new_student;
}

void add_student(Student **head, const char *name, int score) {
    Student *new_student = create_student(name, score);
    if (!new_student) return;

    if (*head == NULL) {
        *head = new_student;
    } else {
        Student *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_student;
    }
}

void display_students(Student *head) {
    if (head == NULL) {
        printf("Empty\n");
    } else {
        Student *temp = head;
        while (temp != NULL) {
            printf("%s %d\n", temp->name, temp->score);
            temp = temp->next;
        }
    }
}

int find_student_score(Student *head, const char *name) {
    Student *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            return temp->score;
        }
        temp = temp->next;
    }
    return -1;
}

void free_list(Student *head) {
    Student *temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Student *head = NULL;
    int choice, score;
    char name[MAX_NAME_LEN];

    while (1) {
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                free_list(head);
                return 0;
            case 1:
                scanf("%s %d", name, &score);
                if (score >= 0 && score <= 100) {
                    add_student(&head, name, score);
                }
                break;
            case 2:
                display_students(head);
                break;
            case 3:
                scanf("%s", name);
                int result = find_student_score(head, name);
                printf("%d\n", result);
                break;
            default:
                printf("Invalid Input\n");
                break;
        }
    }
}
