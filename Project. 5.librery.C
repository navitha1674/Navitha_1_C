#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

typedef struct {
    int id;
    char title[100];
    char author[100];
} Book;

Book books[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount >= MAX_BOOKS) {
        printf("Book limit reached.\n");
        return;
    }
    printf("Enter ID: ");
    scanf("%d", &books[bookCount].id);
    printf("Enter Title: ");
    getchar(); // Clear newline
    fgets(books[bookCount].title, 100, stdin);
    books[bookCount].title[strcspn(books[bookCount].title, "\n")] = '\0';
    printf("Enter Author: ");
    fgets(books[bookCount].author, 100, stdin);
    books[bookCount].author[strcspn(books[bookCount].author, "\n")] = '\0';
    bookCount++;
    printf("Book added!\n");
}

void searchBook() {
    int id, found = 0;
    printf("Enter ID to search: ");
    scanf("%d", &id);
    for (int i = 0; i < bookCount; i++) {
        if (books[i].id == id) {
            printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
            found = 1;
            break;
        }
    }
    if (!found) printf("Book not found.\n");
}

void listBooks() {
    if (bookCount == 0) {
        printf("No books available.\n");
        return;
    }
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d, Title: %s, Author: %s\n", books[i].id, books[i].title, books[i].author);
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Add Book\n2. Search Book\n3. List Books\n4. Exit\nChoice: ");
        scanf("%d", &choice);
        if (choice == 1) addBook();
        else if (choice == 2) searchBook();
        else if (choice == 3) listBooks();
        else if (choice == 4) break;
        else printf("Invalid choice.\n");
    }
    return 0;
}
