#include <stdio.h> #include <string.h>

#define MAX 100 // maximum number of books

int main() { int bookID[MAX], status[MAX]; char name[MAX][50]; int choice, i, count = 0, id, found;

while(1) {
    printf("\n===== LIBRARY BOOK ISSUE SYSTEM =====");
    printf("\n1. Add Book");
    printf("\n2. Issue Book");
    printf("\n3. Return Book");
    printf("\n4. View Book List");
    printf("\n5. Exit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch(choice) {

        // Add Book
        case 1:
            if(count < MAX){
                printf("Enter Book ID: ");
                scanf("%d", &bookID[count]);
                printf("Enter Book Name: ");
                scanf(" %[^\n]", name[count]);  // read string with spaces
                status[count] = 0;               // available
                count++;
                printf("Book Added Successfully!\n");
            } 
            else {
                printf("Book Storage Full!\n");
            }
            break;

        // Issue Book
        case 2:
            printf("Enter Book ID to Issue: ");
            scanf("%d", &id);
            found = 0;
            for(i = 0; i < count; i++){
                if(bookID[i] == id){
                    found = 1;
                    if(status[i] == 0){
                        status[i] = 1;
                        printf("Book Issued Successfully!\n");
                    } else {
                        printf("Book Already Issued!\n");
                    }
                    break;
                }
            }
            if(!found) printf("Book Not Found!\n");
            break;

        // Return Book
        case 3:
            printf("Enter Book ID to Return: ");
            scanf("%d", &id);
            found = 0;
            for(i = 0; i < count; i++){
                if(bookID[i] == id){
                    found = 1;
                    if(status[i] == 1){
                        status[i] = 0;
                        printf("Book Returned Successfully!\n");
                    } else {
                        printf("This Book Was Not Issued!\n");
                    }
                    break;
                }
            }
            if(!found) printf("Book Not Found!\n");
            break;

        // View Books
        case 4:
            printf("\n%-10s %-30s %-10s\n", "Book ID", "Book Name", "Status");
            for(i = 0; i < count; i++){
                printf("%-10d %-30s %-10s\n", bookID[i], name[i], (status[i] == 0 ? "Available" : "Issued"));
            }
            break;

        // Exit
        case 5:
            return 0;

        default:
            printf("Invalid Choice!\n");
    }
}
}