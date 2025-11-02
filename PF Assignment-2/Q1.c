#include<stdio.h>

void AddNewBook(int isbns[100], int quantities[100], char titles[100][50], float prices[100], int *count){
    int isbn;
    printf("Enter Book's ISBN: ");
    scanf("%d", &isbn);
    
    for(int i=0; i<*count; i++){
        if(isbns[i]==isbn){
            printf("Error: Book with ISBN %d already exists!\n", isbn);
            return;
        }
    }
    
    isbns[*count]=isbn;
    printf("Enter Book's Title: ");
    scanf(" %[^\n]", titles[*count]);
    printf("Enter Book's Price: ");
    scanf("%f", &prices[*count]);
    printf("Enter Book's Quantity: ");
    scanf("%d", &quantities[*count]);
    
    (*count)++;
    printf("You successfully added the book's details\n");
}

void ProcessSale(int isbns[100], int quantities[100], char titles[100][50], float prices[100], int count){
    int isbn, copies;
    printf("Enter ISBN of the book to sell: ");
    scanf("%d", &isbn);
    
    int found=-1;
    for(int i=0; i<count; i++){
        if(isbns[i]==isbn){
            found=i;
            break;
        }
    }
    
    if(found==-1){
        printf("Error: Book with ISBN %d not found!\n", isbn);
        return;
    }
    
    printf("Enter number of copies to sell: ");
    scanf("%d", &copies);
    
    if(copies<=0){
        printf("Error: Invalid number of copies!\n");
        return;
    }
    
    if(quantities[found]<copies){
        printf("Error: Only %d copies available. Cannot sell %d copies.\n", quantities[found], copies);
        return;
    }
    
    quantities[found]-=copies;
    float total=prices[found]*copies;
    printf("Sale processed successfully!\n");
    printf("Book: %s\n", titles[found]);
    printf("Copies sold: %d\n", copies);
    printf("Total amount: $%.2f\n", total);
    printf("Remaining quantity: %d\n", quantities[found]);
}

void GenerateReport(int isbns[100], int quantities[100], char titles[100][50], float prices[100], int count){
    printf("\n\tLOW STOCK REPORT (Quantity<5)\n");
    int found=0;
    
    for(int i=0; i<count; i++){
        if(quantities[i]<5){
            printf("ISBN: %d\n", isbns[i]);
            printf("Title: %s\n", titles[i]);
            printf("Price: $%.2f\n", prices[i]);
            printf("Quantity: %d\n", quantities[i]);
            found=1;
        }
    }
    
    if(!found){
        printf("No books with low stock (all books have 5 or more copies).\n");
    }
}

int main(){
    int isbns[100], quantities[100];
    char titles[100][50];
    float prices[100];
    int choice, count = 0;
    
    printf("\t\tLiberty Books\n");
    
    do{
        printf("\nMenu:\n");
        printf("1. Add New Book\n");
        printf("2. Process a Sale\n");
        printf("3. Generate Low-Stock Report\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                if(count>=100){
                    printf("Error: Maximum capacity reached (100 books)!\n");
                } 
				else{
                    AddNewBook(isbns, quantities, titles, prices, &count);
                }
                break;
            case 2:
                if(count==0){
                    printf("Error: No books in inventory!\n");
                }
				else{
                    ProcessSale(isbns, quantities, titles, prices, count);
                }
                break;
            case 3:
                if(count==0){
                    printf("Error: No books in inventory!\n");
                } 
				else{
                    GenerateReport(isbns, quantities, titles, prices, count);
                }
                break;
            case 4:
                printf("Thank you for using Liberty Books System!\n");
                return 1;
            default:
                printf("Invalid Input! Please enter 1-4.\n");
                break;               
        }
    } 
	while(choice!=4);
    
    return 0;
}
