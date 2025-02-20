#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Question 2 & 3
// Question 1 needs to be done on ecf

// Question 2
double my_atoi(const char *str) {
    int i = 0;
    int sign = 1;
    if (str[i] == '-') {
        sign = -1;
        i++;
    }
    double result = 0;
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    // decimals
    i++;
    double dec = 0;
    double factor = 0.1;
    while (str[i] >= '0' && str[i] <= '9') {
        dec += (str[i] - '0') * factor;
        factor *= 0.1;
        i++;
    }
    
    return (result + dec) * sign;
}

// Question 3
typedef struct student1 {
    char name[3];
    int age;
} student1;

void change_name1_wrong(student1 s) {
    s.name[0] = 'b';
}
// no equivilence to python.  structs are pass by value in C.  In python, a tuple is passed by reference
// In python, strings are immutable, so you can't change the value of a string

void change_name1_right_a(student1 *p_s) {
    p_s->name[0] = 'b';
}
// no equivilence to python.  When pointer is passed, it is passed by value, since the pointer value is copied.
// Using pointer logic you can then change the value of the string i.e: changing the first character
// Lastly you can't modify the value of a string in python, since strings are immutable

void change_name1_right_b(student1 *p_s) {
    strcpy(p_s->name, "b");
}
// this is different from python where you have to reassign the value of the string
// here, strcpy goes into the memory location of the string and copies all the values from "b" to name manually.
// The pointer can't be changed to reference another memory block.



int main() {
    // Question 2
    char file[200];
    FILE *fp = fopen("lab4text.txt", "r");
    // store stuff in string array
    char* arr[100];
    int index = 0;
    while(fgets(file, sizeof(file), fp) && index < 100) {
        arr[index] = malloc(strlen(file) + 1); 
        strcpy(arr[index], file);
        index++;
    }
    fclose(fp);
    double numbers[20];
    for (int i = 0; i < index; i++) {
        // remove all characters before the first number or - sign
        int j = 0;
        while (arr[i][j] != '-' && (arr[i][j] < '0' || arr[i][j] > '9')) {
            j++;
        }
        arr[i] = arr[i] + j;
    }
    
    for (int i = 0; i < index; i++) {
        numbers[i] = my_atoi(arr[i]);
    }
    printf("(%.17g", numbers[0]);
    for (int i = 1; i < index; i++) {
        printf("+%.17g", numbers[i]);
    }
    printf(")");
    double sum = 0;
    for (int i = 0; i < index; i++) {
        sum += numbers[i];
    }
    printf(" = %.17g\n", sum);

    // Question 3

    return 0;
}