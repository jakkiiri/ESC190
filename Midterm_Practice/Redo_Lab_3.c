#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Q1
// First one passes a copy, changes x in the local frame (does not reflect main frame)
// Second one changes the pointer, which will change the x in the main frame.

// Q2
typedef struct student1 {
    char name[200];
    char student_number[11];
    int year;
} student1;

void print_student1(student1 s1) {
    printf("Student Name: %s\n", s1.name);
    printf("Student Number: %s\n", s1.student_number);
    printf("Student Year: %d\n", s1.year);
    printf("\n");
}

// Q3
void set_default_name(student1 *p_s) {
    strcpy(p_s->name, "Default Student");
    p_s->year = 0;
}

// wrong, passes a copy of s into the local frame, won't be able to change anything in the main frame
void set_default_name_wrong(student1 s) {
    strcpy(s.name, "Default Student");
    s.year = 0;
}

// Q4
void create_block1(student1 **p_p_s, int n_students) {
    *p_p_s = (student1 *) malloc (sizeof(student1) * n_students);
}

// Q5
void set_name(student1 *p_s, char *name) {
    char new_name[200];
    int i;
    for (i = 0; name[i] != '\0'; i++) {
        new_name[i] = name[i];
    }
    new_name[i] = '\0';
    strcpy(p_s->name, name);
}

// Q6
void destroy_block1(student1 *p_s) {
    free(p_s);
}

// Q7
typedef struct student2 {
    char *name;
    char *student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int num_students) {
    *p_p_s = (student2 *) malloc (sizeof(student2)*num_students);
}

// Q8
void set_name2(student2 *p_s, char *name) {
    p_s->name = (char *) malloc(sizeof(name));
    strcpy(p_s->name, name);
    p_s->student_number = (char *) malloc (2);
    strcpy(p_s->student_number, "0");
}

void print_student2(student2 s2) {
    printf("Student Name: %s\n", s2.name);
    printf("Student Number: %s\n", s2.student_number);
    printf("Student Year: %d\n", s2.year);
    printf("\n");
}

// Q9 (pain)
void destroy_block2(student2 *p_s, int n_students) {
    for (int i = 0; i < n_students; i++) {
        free(p_s[i].name);
        free(p_s[i].student_number);
    }
    free(p_s);
}

// Q13
void print_file_content(char *filename) {
    char line[1000];
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}

int main() {
    student1 s1 = {"Jakkii Ri", "1011271678", 1};
    print_student1(s1);
    student1 *p_s = 0;
    create_block1(&p_s, 5);

    // allocate name to all the students
    set_name(p_s, "Lawrence");
    set_name(p_s+1, "Yang Yang");
    set_name(p_s+2, "Nelson");
    set_name(p_s+3, "Jason");
    set_name(p_s+4, "Junhee");
    print_student1(*p_s);
    print_student1(*(p_s + 1));
    print_student1(*(p_s + 2));
    print_student1(*(p_s + 3));
    print_student1(*(p_s + 4));
    destroy_block1(p_s);

    student2 *p_s2 = 0;
    create_block2(&p_s2, 3);
    set_name2(p_s2, "Aidan");
    set_name2(p_s2 + 1, "Alex");
    set_name2(p_s2 + 2, "Paul");
    print_student2(p_s2[0]);
    print_student2(p_s2[1]);
    print_student2(p_s2[2]);
    destroy_block2(p_s2, 3);

    print_file_content("lab_3_text.txt");

    return 0;
}