#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Q1
// does not work as it changes local x
void set_int1(int x) {
    x = 42;
}

// works because the address is passed in
// directly change the variable with the address
void set_int2(int *p_x) {
    *p_x = 42;
}

// Q2
typedef struct student1 {
    char name[200];
    char student_number[11];
    int year;
} student1;

void print_student_info(student1 s1) {
    printf("Name: %s\n", s1.name);
    printf("Student Number: %s\n", s1.student_number);
    printf("Year: %d\n", s1.year);
}



// Q3
// a)
void set_default_name(student1 *p_s) {
    strcpy(p_s->name, "Default Student");
    p_s->year = 2028;
}
// b)
// this function doesn't work because it changes the local copy of s
void set_default_name_wrong(student1 s) {
    strcpy(s.name, "Default Student");
    s.year = 2028;
}

// Q4
void create_block1(student1 **p_p_s, int n_students) {
    *p_p_s = (student1 *)malloc (sizeof(student1) * n_students);
}

// Q5
void set_name (student1 *p_s, char *name) {
    if (strlen(name) < 200) {
        strcpy(p_s->name, name);
    } else {
        name[199] = '\0';
        strcpy(p_s->name, name);
    }
}

// Q6
void destroy_block1(student1 **p_p_s) {
    if (*p_p_s != NULL) {
        free(*p_p_s);
    }
} 

// Q7
typedef struct student2 {
    char *name;
    char *student_number;
    int year;
} student2;

void create_block2(student2 **p_p_s, int num_students) {
    *p_p_s = (student2 *)malloc(sizeof(student2) * num_students);
    for (int i = 0; i < num_students; i++) {
        (*p_p_s)[i].name = "0";
        (*p_p_s)[i].student_number = "0";
        (*p_p_s)[i].year = 0;
    }
}

// Q8
void set_name2(student2 *p_s, char *name) {
    p_s->name = (char *)malloc(strlen(name) + 1);
    strcpy(p_s->name, name);
}

void print_student_info2(student2 s2) {
    printf("Name: %s\n", s2.name);
    printf("Student Number: %s\n", s2.student_number);
    printf("Year: %d\n", s2.year);
}

// Q9
void destroy_block2 (student2 **p_p_s) {
    if (*p_p_s != NULL) {
        free(*p_p_s);
    }
}

void set_default_name2(student2 s) {
    strcpy(s.name, "Default Name");
}

int main() {
    struct student1 s1;
    s1.year = 2029;
    strcpy(s1.name, "Jacky");
    strcpy(s1.student_number, "1011967830");
    print_student_info(s1);

    // Q4 using create_block1
    student1 *p_s = NULL;              
    student1 **p_p_s = &p_s;           
    create_block1(p_p_s, 5);
    **p_p_s = s1;

    // Q5 using set_name
    char *name = "Jacques";
    set_name(*p_p_s, name);
    printf("\n");
    print_student_info(**p_p_s);

    // Q6 using destroy_block1
    destroy_block1(p_p_s);
    printf("\n");

    // Q8 using set_name2
    student2 *p_s_2 = NULL;
    student2 **p_p_s_2 = &p_s_2;
    create_block2(p_p_s_2, 5);
    set_name2(p_p_s_2[0], "Rowan");
    print_student_info2(**p_p_s_2);
    destroy_block2(p_p_s_2);
    
    printf("\n");

    // Q10
    // s1 is proven as in quesiton 3
    // s2 can be proven as in following
    struct student2 s3;
    set_name2(&s3, "Joel");
    set_default_name2(s3);
    print_student_info2(s3);


    return 0;
}