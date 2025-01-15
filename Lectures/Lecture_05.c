#include <stdio.h>

int main () {
    char s1[] = "abc"; // array of type char, with short hand s1[] = {'a', 'b', 'c', '\0'}
    char* s2 = "abc"; // pointer to a string literal, s2 points to the first character of the string literal

    // const char*  
    // values at addresses of type const char* are not mutable
    // but you can convert const char* to char* and then change the values

    char* s3 = "abc";
    s3[0] = 'x'; // implicit conversion to char* is not allowed
    // not allowed to modify the contents of const char* s3
    // go to address s and modify the contents there
    // this might crash

    // in C, undefined behavior: behavior of C that can be anything (crash, run, etc.)

    const char* s4 = "abc"; // s4 is address of the 'a'
    // not allowed to modify contents at s4
    // program won't compile
    // s4[0] = 'x'; // error: assignment of read only location '*(s4)'

    s4 = "xbc"; // allowed: not changing the contents of s4, just changing the address it points to
    // s4 is now pointing to the first character of the string literal "xbc"

    char c = 'x';
    char* p_c = &c;
    // c[0] = 'y'; // error: subscripted value is neither array nor pointer nor vector
    p_c[0] = 'y'; // same as c = 'y'

    // const are not mutable and will result out in error

    char* const str = "hello"; // str is a constant pointer to a char
    // str = "world"; // error: assignment of read-only variable 'str'
    str[0] = 'j'; // allowed: changing the contents of the string literal

    const char* const str2 = "hello"; // str2 is a constant pointer to a constant char
    // str2 = "world"; // error: assignment of read-only variable 'str2'
    // str2[0] = 'j'; // error: assignment of read-only location '*(str2 + 0)'

    char s[] = "hello"; // s is an array of type char
    s[0] = 'j'; // allowed: changing the contents of the array
    // s = "world"; // error: changing the pointer to the array

    char *s5 = "xbc"; 
    printf("%ld\n%ld\n", s4, s5);

    // printf 
    // %d: decimal
    // %c: character
    // %s: string
    // %ld: long decimal
    // %p: pointer

    return 0;
}