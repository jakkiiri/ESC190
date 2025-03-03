#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct business {
    int phone_number[10];
    char *name;
} business;

void read_numbers(const char *filename, business **whitepages, int *size) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        return;
    }
    fscanf(fp, "%d", size);
    *whitepages = (business *) malloc(sizeof(business) * *size);
    char number_string[13];
    char *name;
    for (int i = 0; i < *size; i++) {
        name = (char *) malloc (sizeof(char));
        fscanf(fp, "%s\t%[^\n]", number_string, name);
        for (int k = 0, j = 0; k < 12; k++, j++) {
            if (k != 3 && k != 7) {
                (*whitepages)[i].phone_number[j] = (int) (number_string[k] - '0');
            } else {
                j--;
            }
        }
        int str_size = strlen(name) + 1;
        (*whitepages + i)->name = (char *) malloc (sizeof(char) * str_size);
        strcpy((*whitepages)[i].name, name);
    }
    fclose(fp);
}

void free_numbers(business *whitepages, int size) {
    for (int i = 0; i < size; i++) {
        free(whitepages[i].name);
    }
    free(whitepages);
}

int main() {
    business *whitepages;
    int size;
    read_numbers("businesses.txt", &whitepages, &size);

    for (int i = 0; i < size; i++) {
        printf("Business %d:\n", i + 1);
        printf("Phone Number: ");
        for (int j = 0; j < 10; j++) {
            printf("%d", whitepages[i].phone_number[j]);
            if (j == 2 || j == 5) {
                printf("-");
            }
        }
        printf("\nName: %s\n", whitepages[i].name);
    }




    return 0;
}