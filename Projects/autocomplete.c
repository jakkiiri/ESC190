#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "autocomplete.h"

// compare function for qsort
int compare (const void *a, const void *b) {
    return strcmp(((struct term *)a)->term, ((struct term *)b)->term);
}

void read_in_terms(struct term **terms, int *pnterms, char *filename) {
    // opens file, and checks if file is NULL
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("ERROR: file not found\n");
        exit(1);
    }
    // looks at first line to get the number of terms
    fscanf(fp, "%d", pnterms);
    // allocates memory for the block of terms
    *terms = (struct term *) malloc(sizeof(struct term) * *pnterms);
    // gets the term and weight from each term
    for (int i = 0; i < *pnterms; i++) {
        fscanf(fp, "%lf\t%[^\n]", &(*terms)[i].weight, (*terms)[i].term);
    }
    qsort(*terms, *pnterms, sizeof(struct term), compare);
    fclose(fp);
}

int lowest_match(struct term *terms, int nterms, char *substr) {
    int result = -1;
    int low = 0;
    int high = nterms - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(terms[mid].term, substr, strlen(substr)) < 0) {
            low = mid + 1;
        } else if (strcmp(terms[mid].term, substr, strlen(substr)) > 0){
            high = mid - 1;
        } else {
            result = mid;
            high = mid - 1;
        }    
    }
    return result;
}

int highest_match(struct term *terms, int nterms, char *substr) {
    int result = -1;
    int low = 0;
    int high = nterms - 1;
    int mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (strcmp(terms[mid].term, substr, strlen(substr)) > 0) {
            high = mid - 1;
        } else if (strcmp(terms[mid].term, strlen(substr)) < 0) {
            low = mid + 1;
        } else{
            result = mid;
            low = mid + 1;
        }
    }
    return result;
}

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr) {

}
