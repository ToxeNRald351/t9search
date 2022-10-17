#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define CONTACTS_SIZE 42
#define TEXT_LEN 101

char digits[10][4] = {
    {'+'},                      // 0
    {},                         // 1
    {'a', 'b', 'c'},            // 2
    {'d', 'e', 'f'},            // 3
    {'g', 'h', 'i'},            // 4
    {'j', 'k', 'l'},            // 5
    {'m', 'n', 'o'},            // 6
    {'p', 'q', 'r', 's'},       // 7
    {'t', 'u', 'v'},            // 8
    {'w', 'x', 'y', 'z'}        // 9
};

// get all contacts from stdin and place them in array
int getContacts(char (*contacts)[2][TEXT_LEN]);
// is char a part of a certain digit
bool digitHasChar(int d, char c);
// is substring a part of a string?
bool isSubstr(char *s, char *contact);
// is subnumber a part of a number?
bool isSubnum(char *s, char *number);

int main(int argc, char **argv) {
    char contacts[CONTACTS_SIZE][2][TEXT_LEN] = {}; /*= {
        {"name", "number"}
    };
    */
    // get input and args
    int n = getContacts(contacts);
    char s[TEXT_LEN] = {};
    if (argc > 1)
        memcpy(s, argv[1], TEXT_LEN - 1);

    // output
    printf("\nNumber of contacts: %d\n===== Contacts list =====\n", n);
    for (int i = 0; i < CONTACTS_SIZE; i++) {
        if (contacts[i][0][0] != '\0')
            printf("%s, %s\n", contacts[i][0], contacts[i][1]);
    }
    
    printf("\nLook for: %s\n\n", s);

    // do actual shit
    printf("===== Search results =====\n");
    for (int i = 0; i < n; i++) {                               // through each contact
        if (isSubstr(s, contacts[i][0])) {
            printf("%s, %s\n", contacts[i][0], contacts[i][1]);
        }
        else if (isSubnum(s, contacts[i][1])) {
            printf("%s, %s\n", contacts[i][0], contacts[i][1]);
        }
    }

    return 0;
}

int getContacts(char (*contacts)[2][TEXT_LEN]) {
    char name[TEXT_LEN] = {};
    char number[TEXT_LEN] = {};

    for (int i = 0; i < CONTACTS_SIZE && !feof(stdin); i++) {
        fgets(name, TEXT_LEN - 1, stdin);
        fgets(number, TEXT_LEN - 1, stdin);

        if (feof(stdin))
            return i;
        
        name[strlen(name) - 1] = '\0';
        number[strlen(number) - 1] = '\0';
        memcpy(contacts[i][0], name, TEXT_LEN - 1);
        memcpy(contacts[i][1], number, TEXT_LEN - 1);
    }

    return CONTACTS_SIZE;
}

bool digitHasChar(int d, char c) {
    for (int i = 0; i < (int)strlen(digits[d]); i++) {
        if (digits[d][i] == c)
            return true;
    }

    return false;
}

bool isSubstr(char *s, char *contact) {
    for (int j = 0; j < (int)strlen(contact); j++) {     // through each contact char
        int i, k;
        for (i = 0, k = j; i < (int)strlen(s) && k < (int)strlen(contact) && digitHasChar(s[i] - '0', contact[k]); i++, k++) {
        }
        if (i == (int)strlen(s))
            return true;
    }

    return false;
}

bool isSubnum(char *s, char *number) {
    for (int j = 0; j < (int)strlen(number); j++) {     // through each contact char
        int i, k;
        for (i = 0, k = j; i < (int)strlen(s) && k < (int)strlen(number) && s[i] == number[k]; i++, k++) {
        }
        if (i == (int)strlen(s))
            return true;
    }

    return false;
}