#include <stdio.h>

#define ROWS 10
#define COLS 10

void updateSector(int grid[ROWS][COLS]){
    int row, column, flag, value;
    printf("Enter row and column(separated by a comma): ");
    scanf("%d,%d", &row, &column);
    printf("Enter flag to update(0=Power, 1=Overload, 2=Maintenance): ");
    scanf("%d", &flag);
    printf("Set to(1 or 0): ");
    scanf("%d", &value);
    
    if(row<0 || row>=ROWS || column<0 || column>=COLS){
        printf("Invalid coordinates.\n");
        return;
    }
    
    if(value==1){
        grid[row][column]|=(1<<flag);
    } 
	else{
        grid[row][column]&= ~(1<<flag);
    }
    printf("Status updated.\n");
}

void querySector(int grid[ROWS][COLS]){
    int row, column;
    printf("Enter row and column(seperated by a comma): ");
    scanf("%d,%d", &row, &column);
    
    if (row<0 || row>=ROWS || column<0 || column>=COLS){
        printf("Invalid coordinates.\n");
        return;
    }
    
    int status=grid[row][column];
    printf("Sector (%d,%d) Status:\n", row, column);
    printf("Power: %s\n", (status&1)?"ON":"OFF");
    printf("Overload: %s\n", (status&2)?"YES":"NO");
    printf("Maintenance: %s\n", (status&4)?"YES":"NO");
}

void runDiagnostic(int grid[ROWS][COLS]){
    int overloadCount=0;
    int maintenanceCount=0;
    
    for (int i=0; i<ROWS; i++){
        for (int j=0; j<COLS; j++) {
            int status=grid[i][j];
            if(status&2){
            	overloadCount++;
            }
            if(status&4){
                maintenanceCount++;
            }
        }
    }
    
    printf("System Diagnostic Report:\n");
    printf("Overloaded sectors: %d\n", overloadCount);
    printf("Maintenance required sectors: %d\n", maintenanceCount);
}

int main(){
    int grid[ROWS][COLS]={0};
    int choice;
    printf("\tIESCO Grid Monitor\n");
    do{
        printf("Menu:\n");
        printf("1. Update Sector Status\n");
        printf("2. Query Sector Status\n");
        printf("3. Run System Diagnostic\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                updateSector(grid);
                printf("\n");               
			    break;
            case 2:
                querySector(grid);
                printf("\n");
                break;
            case 3:
                runDiagnostic(grid);
                printf("\n");
                break;
            case 4:
                printf("Thank you for using IESCO Grid Monitor System.\n");
                break;
            default:
                printf("Invalid choice. Select from 1-4\n\n");
        }
    } 
	while(choice!=4);
    
    return 0;
}
