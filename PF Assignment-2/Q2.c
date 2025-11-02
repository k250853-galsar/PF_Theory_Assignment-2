#include<stdio.h>


void CustomerInformation(char name[50], char CNIC[15]){
    printf("Enter your name: ");
    getchar();
	fgets(name, 50, stdin);
    printf("Enter CNIC: ");
    fgets(CNIC, 15, stdin);
    printf("Customer information saved successfully!\n\n");
}

void DisplayInventory(int inventory[][4], char products[][20]){
    printf("\n\t\tSUPERMARKET INVENTORY\n");
    printf("Product Code\tProduct Name\t\tQuantity\tPrice\n");
    printf("------------------------------------------------------------------\n");
    
    for(int i=0; i<4; i++){
        printf("    %03d\t\t%-15s\t\t  %d\t\tRs.%d\n",inventory[i][0],products[i],inventory[i][2],inventory[i][3]);
    }
    printf("------------------------------------------------------------------\n\n");
}

void UpdateInventory(int inventory[][4], int productCode, int quantity){
    for(int i=0; i<4; i++){
        if(inventory[i][0]==productCode){
            inventory[i][2]-=quantity;
            break;
        }
    }
}

void AddItem(int inventory[][4], int cart[], char products[][20]){
    int productCode, quantity;
    
    printf("Enter product code to add to cart: ");
    scanf("%d", &productCode);
    
    if(productCode<1 || productCode>4){
        printf("Invalid product code! Please try again.\n\n");
        return;
    }
    
    printf("Enter quantity: ");
    scanf("%d", &quantity);
    
    if(quantity>inventory[productCode-1][2]){
        printf("Insufficient stock! Only %d items available.\n\n", inventory[productCode-1][2]);
        return;
    }
    
    cart[productCode-1]+=quantity;
    
    printf("%d units of %s added to cart successfully!\n\n",quantity,products[productCode-1]);
	UpdateInventory(inventory, productCode, quantity);
}

void DisplayTotalBill(int inventory[][4], int cart[], float *totalBill, char products[][20]){
    int cartEmpty=1;
    
    for(int i=0; i<4; i++){
        if(cart[i]>0){
            cartEmpty=0;
            break;
        }
    }
    
    if(cartEmpty){
        printf("Cart is empty! Please add items first.\n\n");
        return;
    }
    
    *totalBill=0;
    printf("\n\t\tITEMS IN CART\n");
    printf("Product\t\tQuantity\tPrice\tTotal\n");
    printf("------------------------------------------------\n");
    
    for(int i=0; i<4; i++){
        if(cart[i]>0){
            int productTotal=cart[i]*inventory[i][3];
            *totalBill+=productTotal;
            printf("%s\t\t%d\t\tRs.%d\tRs.%d\n",products[i],cart[i],inventory[i][3],productTotal);
        }
    }
    printf("------------------------------------------------\n");
    printf("Total Bill: Rs.%.2f\n", *totalBill);
    
    char promo[20];
    char Ispromo;
    printf("\nDo you have a promo code?(Y/N): ");
    getchar();
    scanf("%c", &Ispromo);
    float discount = 0, discountedTotal = *totalBill;
    if(Ispromo=='Y'||Ispromo=='y'){
    	printf("Enter promo code: ");
		scanf("%s", promo);
		int isEid2025=1;
    	char eid[]="Eid2025";
    	for(int i=0; i<7; i++){
       		if(promo[i]!=eid[i]){
           		isEid2025=0;
            	break;
        	}
    	}
    	if(isEid2025 && promo[7] == '\0') {
            discount = *totalBill * 0.25;
            discountedTotal = *totalBill - discount;
            printf("\nPromo code applied successfully!\n");
            printf("Discount (25%%): Rs.%.2f\n", discount);
            printf("Discounted Total: Rs.%.2f\n", discountedTotal);
        } 
		else {
            printf("\nInvalid promo code! No discount applied.\n");
            printf("Total remains: Rs.%.2f\n", *totalBill);
            discountedTotal = *totalBill;
        } 	
	}
	else{
        printf("\nNo promo code applied.\n");
        printf("Total: Rs.%.2f\n", *totalBill);
    }
	*totalBill = discountedTotal;    
    printf("\n");
}

void ShowInvoice(char name[50], char CNIC[15], int inventory[][4], int cart[], float totalBill, char products[][20]){
    int cartEmpty=1;
    
    for(int i=0; i<4; i++){
        if(cart[i]>0){
            cartEmpty=0;
            break;
        }
    }
    
    if(cartEmpty){
        printf("No purchase made! Please add items and generate bill first.\n\n");
        return;
    }
    
    printf("\n\t\tMEGA SUPERMARKET - INVOICE\n");
    printf("Customer Name: %s", name);
    printf("CNIC: %s\n", CNIC);
    printf("Product\t\tQuantity\tPrice\tTotal\n");
    printf("-------------------------------------------------\n");
    
    float subtotal=0;
    for(int i=0; i<4; i++){
        if(cart[i]>0){
            int productTotal=cart[i]*inventory[i][3];
            subtotal+=productTotal;
            printf("%s\t\t%d\t\tRs.%d\tRs.%d\n",products[i],cart[i],inventory[i][3],productTotal);
        }
    }
    
    printf("-------------------------------------------------\n");
    printf("Subtotal: Rs.%.2f\n", subtotal);
    
    if(totalBill<subtotal){
        float discount=subtotal-totalBill;
        printf("Discount (25%%): -Rs.%.2f\n", discount);
        printf("-------------------------------------------------\n");
    }
    
    printf("GRAND TOTAL: Rs.%.2f\n", totalBill);
    printf("=================================================\n");
    printf("Thank you for shopping with us!\n\n");
    
    for(int i=0; i<4; i++){
        if(cart[i]>0){
            UpdateInventory(inventory, inventory[i][0], cart[i]);
        }
    }
}

int main(){
    char name[50], CNIC[15];
    int choose;
    int inventory[4][4]={{1, 0, 50, 100},{2, 0, 10, 200},{3, 0, 20, 300},{4, 0, 8, 150}};
    char products[4][20]={"Bread","Milk","Eggs","Butter"};
    
    int cart[4]={0};
    float totalBill=0;
    int customerInfoTaken=0;
    
    printf("\tWelcome To The Mega Supermarket!\n");
    
    do{
        printf("Menu:\n");
        printf("1. Customer Information\n");
        printf("2. Display Inventory\n");
        printf("3. Add item to cart\n");
        printf("4. Display total bill\n");
        printf("5. Show Invoice\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choose);
        
        switch(choose){
            case 1:
                CustomerInformation(name, CNIC);
                customerInfoTaken = 1;
                break;
            case 2:
                DisplayInventory(inventory, products);
                break;
            case 3:
                AddItem(inventory, cart, products);
                break;    
            case 4:
                DisplayTotalBill(inventory, cart, &totalBill, products);
                break;
            case 5:
                if(!customerInfoTaken){
                    printf("Please enter customer information first!\n\n");
                }
				else{
                    ShowInvoice(name, CNIC, inventory, cart, totalBill, products);
 					for(int i=0; i<4; i++){
                        cart[i]=0;
                    }
                    totalBill=0;
                }
                break;
            case 6:
                printf("Thanks for using Mega Supermarket online platform.\n");
                break;
            default:
                printf("Invalid Input! Please type a valid input.\n\n");    
        }
    } 
	while(choose!=6);
    
    return 0;
}
