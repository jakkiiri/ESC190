#include <stdio.h>
#include <stdlib.h>

// Q1

// write own string length function
int str_len(char *str) {
    int i = 0;
    while (*str != '\0') {
        i++;
        str++;
    }
    return i;
}

// write own reverse string function
char *reverse_string(char *str) {
    int size = str_len(str);
    char *reverse_string = (char *) malloc (size * sizeof(char) + 1);
    for (int i = size - 1; i >= 0; i--) {
        reverse_string[size - 1 - i] = str[i];
    }
    reverse_string[size] = '\0';
    return reverse_string;

}

double my_atof(char *str) {
    // reverse str
    char *reversed_str = reverse_string(str);
    double result = 0.0;
    int condition = 0;
    int power = 1;
    for (int i = 0; i < str_len(str); i++) {
        if (str[i] == '.') {
            condition = 1;
            i++;
        }
        if (condition) {
            double temp = (double) (str[i] - '0');
            for (int j = 0; j < power; j++) {
                temp *= 0.1;
            }
            result += temp;
            power++;
        }
    }
    // now add everything eyond the decimal
    condition = 0;
    power = 0;
    for (int i = 0; i < str_len(str); i++) {
        if (str[i] == '.') {
            condition = 1;
        }
        if (condition) {
            double temp = (double) (reversed_str[i] - '0');
            for (int j = 0; j < power; j++) {
                temp *= 10;
            }
            result += temp;
            power++;
        }
    }
    free(reversed_str);
    return result;
}

// Q2
int my_strncmp (char *str1, char *str2, int num) {
    if (num == 0 || *str1 == '\0' || *str2 == '\0') {
        return (int) (*str1 - *str2);
    } else if (*str1 != *str2) {
        return (int) (*str1 - *str2);
    } else {
        return my_strncmp(str1+ 1, str2+1 , num- 1);
    }
}

int main() {
    char *str = "512.23";
    printf("%lf\n", my_atof(str));
    printf("%d\n", my_strncmp("ESC180", "ESC190", 3));
    printf("%d\n", my_strncmp("ESC180", "ESC190", 5));
    return 0;
}