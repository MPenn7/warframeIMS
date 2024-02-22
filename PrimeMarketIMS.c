#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sqlite3.h>
#define MAX_LIMIT 90

FILE *file;

struct itemInfo {
  int sku;
  char name[MAX_LIMIT];
  int QOH;
  int QIR;
  int price;
};

void addItem(struct itemInfo inventory[], int *itemCount){
    struct itemInfo newItem;
    
    int type;
    printf("Please enter the type of item: \n");
    printf("---------------\n");
    printf("1. Warframe Set\n");
    printf("2. Primary Weapon\n");
    printf("3. Secondary Weapon\n");
    printf("4. Melee\n");
    printf("5. Mods or etc\n");
    
    scanf("%d", &type);
    
    printf("\n\n");
    
    if( type<1 || type>=6)
        printf("ERROR: Selection outside of bounds");
      
    switch(type){
        case 1:
            newItem.sku = 1000 + *itemCount + 1;
            break;
        case 2:
            newItem.sku = 2000 + *itemCount + 1;
            break;
        case 3:
            newItem.sku = 3000 + *itemCount + 1;
            break;
        case 4:
            newItem.sku = 4000 + *itemCount + 1;
            break;
        case 5:
            newItem.sku = 5000 + *itemCount + 1;
            break;
    
    }
    printf("Enter the name of the item: ");
    scanf(" %90[^\n]", newItem.name);
    printf("\n");

    printf("Enter the QOH of the item: ");
    scanf("%d", &newItem.QOH);
    printf("\n");

    printf("Enter the number of relics this item is in: ");
    scanf("%d", &newItem.QIR); 
    printf("\n");

    printf("Enter the price of this item: ");
    scanf("%d", &newItem.price);
    printf("\n");

    inventory[*itemCount] = newItem;
    (*itemCount)++;

    }

void displayInventory(struct itemInfo inventory[], int itemCount){
    if(itemCount == 0)
        printf("Inventory is empty. \n");
        
    printf("Inventory Items:\n");
    printf("ID\tName\t\t        QOH     QIR\tPrice\n");
    printf("\n");
    for (int i = 0; i < itemCount; i++){
        struct itemInfo item = inventory[i];
        //printf("%-8d%-20s%d%-12d%-10d", item.sku, item.name, item.QOH, item.QIR, item.price);
	printf("%d\t",item.sku);
	printf("%-20s\t",item.name);
	printf("%d\t",item.QOH);
	printf("%d\t",item.QIR);
	printf("%d\t",item.price);
	printf("\n");	
    }
}

void loadInventory(FILE *file){
	//Use either a basic read/write system or SQL api to save/load inventory info
	file = fopen("InventorText", "a+");
	if(file == NULL){
	     printf("ERROR FILE IS NULL\n");
	     exit(1);
	}

}

void SaveInventory(struct itemInfo inventory[]){
	/*Saves info to the same text file or SQL server
	struct itemInfo item = inventory[i];
	sqlite3 *db;
	int rc;

	rc = sqlite3_open("waframeIMSSQL", &db);
	if (rc){
		printf(stderr, "CANNOT OPEN DATABASE: %s\n", sqlite3_errmsg(db));
		return rc;
	}
*/
	
}
/*
void createDatabase(struct itemInfo inventory[]){
	struct itemInfo item = inventory[i];
	sqlite3 *db;
	int rc;

	rc = sqlite3_open("waframeIMSSQL", &db);
	if (rc){
		printf(stderr, "CANNOT OPEN DATABASE: %s\n", sqlite3_errmsg(db));
		return rc;
	}


}
*/
int main()
{
    sqlite3 *db;
    char *errMSG;
    int rc;
   
    rc = sqlite3_open("test.db". &db);
    
    if(rc){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return(0);
    } else {
	fprintf(stderr, "opened database successfully\n");
    } 
	
    struct itemInfo inventory[1000]; // Assuming a maximum of 1000 items
    int itemCount = 0;
	while(1){
        printf("\nPrime Market Inventory Management System\n");
        printf("1. Add Item\n");
        printf("2. Display Inventory\n");
	printf("3. Load Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
	printf("\n\n");
        switch (choice) {
            case 1:
                addItem(inventory, &itemCount);
                break;
            case 2:
                displayInventory(inventory, itemCount);
                break;
		case 3:
	    	printf("Needs to be implemented");
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");

	}
    }
    return 0;
		
}
