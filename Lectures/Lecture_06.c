#include <stdio.h>

// example of typedef
typedef int sz_arr_t;

void print_array(int *arr, sz_arr_t sz) {
    int i;
    for (i = 0; i < sz; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// compound data types
// struct is a way to group variables together --> OOP
typedef struct student {
    char name[200];
    char number[11]; // 11 to include the null character
    double GPA;
} student;

// sending integers, string, and lists
void dont_change_int(int a) {
    a = 42;
}

void change_int(int *p_a) {
    *p_a = 43;
}

void change_arr(int* arr) {
    arr[0] = 5;
}

void dont_change_arr(int* arr) {
    arr = 0; // this will not change the array
    // local variable arr is set to 0
    // does not change the array in the main function
}

void change_s(const char *s) {
    // s[0] = 'x'; // error: assignment of read-only location '*s'
    // s = "xbc"; // allowed: changing the address of s
}

void dont_change_arr1(const char* arr) {
    arr = 0; // this will not change the array
    // local variable arr is set to 0
}

void change_str(char* s) {
    s[0] = 'x';
    // s = "xbc"; // error: assignment of read-only location '*s'
}

int main() {

    // printf review
    const char *s1 = "abc";
    const char *s2 = "def";
    const char *s3 = "ghi";

    printf("%d %c\n", 87, 87); // 87 is the ASCII value of 'W'
    printf("%p\n", 87); 
    printf("%s\n", s1+1); // bc substring
    printf("%c\n", s1); // null (final character)
    printf("%c\n", *s1); // a
    printf("%c\n", s1[0]); // a same thing as last line
    int x = 123;
    printf("%ld\n", &x);
    printf("s1: %ld\ns2: %ld\ns3: %ld\n", s1, s2, s3); // addresses are stored 4 bytes apart
    printf("s2: %s\n", s1 + 4); // to show adding 4 bytes to the address of s1 is the same as s2

    // custom data types & pointers
    // typedef is a way to give new names to types in c
    // e.g: typedef int arr_sz_t
    // arr_sz_t x = 5; // x is an integer and represents the size of an array
    // useful to switch the datatype of a variable in a program

    int arr[] = {5,6,7};
    typedef int sz_arr_t;
    sz_arr_t sz = 3;
    print_array(arr, sz);

    // example of struct and typedef
    student student1 = {"John Doe", "1234567890", 3.5};
    printf("Name: %s\nNumber: %s\nGPA: %lf\n", student1.name, student1.number, student1.GPA);
    student *p_student = &student1;
    printf("Name: %s\nNumber: %s\nGPA: %lf\n", (*p_student).name, (*p_student).number, (*p_student).GPA);
    // -> is a shorthand for dereferencing a pointer to a struct
    printf("Name: %s\nNumber: %s\nGPA: %lf\n", p_student->name, p_student->number, p_student->GPA); 

    // change str
    char *s1 = "abc";
    change_str(s1); // may crash due to modifying a string literal (undefined behavior)

    char s2[] = "abc";
    change_str(s2); // allowed, arrays are mutable

    return 0;
}