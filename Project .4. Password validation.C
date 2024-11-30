#include <stdio.h>
#include <string.h>
#include <ctype.h>

int is_valid_password(const char *password) {
    int length = strlen(password);
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;

    if (length < 8) {
        printf("Password must be at least 8 characters long.\n");
        return 0;
    }

    for (int i = 0; i < length; i++) {
        if (isupper(password[i])) 
            has_upper = 1;
        else if (islower(password[i])) 
            has_lower = 1;
        else if (isdigit(password[i])) 
            has_digit = 1;
        else if (strchr("!@#$%^&*()-_+=<>?", password[i])) 
            has_special = 1;
    }

    if (!has_upper)
        printf("Password must contain at least one uppercase letter.\n");
    if (!has_lower)
        printf("Password must contain at least one lowercase letter.\n");
    if (!has_digit)
        printf("Password must contain at least one digit.\n");
    if (!has_special)
        printf("Password must contain at least one special character (!@#$%^&*()-_+=<>?).\n");

    return has_upper && has_lower && has_digit && has_special;
}

int main() {
    char password[100];

    printf("Enter a password to check: ");
    scanf("%s", password);

    if (is_valid_password(password)) {
        printf("Password is valid.\n");
    } else {
        printf("Password is invalid.\n");
    }

    return 0;
}
