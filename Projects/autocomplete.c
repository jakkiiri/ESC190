#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "autocomplete.h"

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
        fscanf(fp, "%ld\t%s", &(*terms)[i].weight, (*terms)[i].term);
    }
}

int lowest_match(struct term *terms, int nterms, char *substr) {

}

int highest_match(struct term *terms, int nterms, char *substr) {

}

void autocomplete(struct term **answer, int *n_answer, struct term *terms, int nterms, char *substr) {

}
