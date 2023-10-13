#include <stdio.h>
#include <string.h>

#define MAX_USERS 100

typedef struct {
    char username[50];
    char password[50];
} User;

User users[MAX_USERS];
int userCount = 0;

int main() {
    int choice;
    do {
        printf("--enter 1 to Register\n--enter 2 to Login\n--enter 3 to quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User database is full. Cannot register more users.\n");
        return;
    }

    User newUser;
    printf("Enter username: ");
    scanf("%s", newUser.username);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    users[userCount] = newUser;
    userCount++;

    printf("Registration successful!\n");
}

void loginUser() {
    char username[50];
    char password[50];
    int loggedIn = 0;

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            printf("Login successful!\n");
            loggedIn = 1;
            break;
        }
    }

    if (!loggedIn) {
        printf("Login failed. Please check your credentials.\n");
    }
}