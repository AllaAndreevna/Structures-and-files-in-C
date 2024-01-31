#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct izdatel {
    int god;
    char naz[100];
    char gor[100];
};

struct Book {
    char title[100];
    int price;
    int numPages;
    char author[100];
    struct izdatel publisherInfo;
};

void check_number(const char name[], int *s) {
    int ret_code;
    do {
        printf("Input %s:\n", name);
        ret_code = scanf("%d", s);
        while (getchar() != '\n');  // чистим буфер (потому что без fgets)
    } while (ret_code != 1 || *s <= 0);
}

void check_year(const char name[], int *s) {
    int ret_code;
    do {
        printf("Input %s (between 1458 and 2024):\n", name);
        ret_code = scanf("%d", s);
        while (getchar() != '\n');  
    } while (ret_code != 1 || *s < 1458 || *s > 2024);
}

void check_string(const char name[], char s[]) {
    int invalid_input;
    do {
        invalid_input = 0;
        printf("Input %s:\n", name);
        scanf("%s", s);
        while (getchar() != '\n'); 
        
        for (int i = 0; i < strlen(s); i++) {
            if (!isalpha(s[i]) && !isspace(s[i])) {
                invalid_input = 1;
                printf("Invalid input. Please enter a string without numbers or special characters.\n");
                break;
            }
        }

    } while (invalid_input || strlen(s) == 0);
}

void input(struct Book *books, const int numStructs) {
    for (int i = 0; i < numStructs; i++) {
        printf("Book #%d\n", i + 1);
        check_string("Title", books[i].title);
        check_number("Price", &books[i].price);
        check_number("Number of pages", &books[i].numPages);
        check_string("Author", books[i].author);
        
        printf("Publishing company:\n");
        check_year("Year of publication", &books[i].publisherInfo.god);
        check_string("Publisher name", books[i].publisherInfo.naz);
        check_string("Publishing city", books[i].publisherInfo.gor);
    }
}

void output(struct Book *books, const int numStructs) {
    printf("\nReceived books:\n");
    for (int i = 0; i < numStructs; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Price: %d\n", books[i].price);
        printf("Number of pages: %d\n", books[i].numPages);
        printf("Author: %s\n", books[i].author);
        printf("Publisher Info:\n");
        printf("Year of publication: %d\n", books[i].publisherInfo.god);
        printf("Publisher name: %s\n", books[i].publisherInfo.naz);
        printf("Publishing city: %s\n", books[i].publisherInfo.gor);
    }
}

char** solution(struct Book *books, const int numStructs, int *numResults){
    float minPrice = books[0].price;
    for (int i = 0; i < numStructs; i++) {
        if (books[i].price < minPrice) {
            minPrice = books[i].price;
        }
    }

    char **result = (char **)malloc(numStructs * sizeof(char *));
    if (result == NULL) {
        printf("Memory failed.\n");
        *numResults = 0;
        return NULL;
    }

    *numResults = 0;

    for (int i = 0; i < numStructs; i++) {
        if (books[i].price == minPrice) {
            int found = 0;
            for (int j = 0; j < *numResults; j++) {
                if (strcmp(books[i].publisherInfo.gor, result[j]) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                result[*numResults] = strdup(books[i].publisherInfo.gor);
                (*numResults)++;
            }
        }
    }
    return result;
}

int main() {
    int numStructs;
    printf("Enter the number of books: ");
    scanf("%d", &numStructs);
    while (getchar() != '\n');  

    struct Book books[numStructs];
    input(books, numStructs);
    output(books, numStructs);

    int numResults;
    char **result = solution(books, numStructs, &numResults);
    if (result != NULL) {
        printf("\nCities where the cheapest books are published:\n");
        for (int i = 0; i < numResults; i++) {
            printf("%s\n", result[i]);
            free(result[i]);  
        }
        free(result);  
    }
    

    return 0;
}


