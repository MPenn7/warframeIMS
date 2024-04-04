#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <sqlite3.h>
#define MAX_LIMIT 90
//#include "itemInfo.h"
#include "addItem.c"

void edit();


//FILE *file;
/*
struct itemInfo {
  int sku;
  char name[MAX_LIMIT];
  int QOH;
  int QIR;
  int price;
};


static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
for(int i = 0; i<argc; i++){
	printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
}
	printf("\n");
	return 0;
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


void loadInventory(FILE *file){
       //Use either a basic read/write system or SQL api to save/load inventory info
       file = fopen("InventorText", "a+");
       if(file == NULL){
            printf("ERROR FILE IS NULL\n");
            exit(1);
       }



void SaveInventory(struct itemInfo inventory[]){
       Saves info to the same text file or SQL server
       struct itemInfo item = inventory[i];
       sqlite3 *db;
       int rc;

       rc = sqlite3_open("waframeIMSSQL", &db);
       if (rc){
       	printf(stderr, "CANNOT OPEN DATABASE: %s\n", sqlite3_errmsg(db));
       	return rc;
       }

       



void createDatabase(struct itemInfo inventory[]){
       struct itemInfo item = inventory[i];
       sqlite3 *db;
       int rc;

       rc = sqlite3_open("waframeIMSSQL", &db);
       if (rc){
       	printf(stderr, "CANNOT OPEN DATABASE: %s\n", sqlite3_errmsg(db));
       	return rc;
       }



*/
int main()
{
/*
    sqlite3 *db;
    char *errMSG;
    int rc;
   
    rc = sqlite3_open("warframeIMSSQL", &db);
    
    if(rc){
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    return(0);
    } else {
	fprintf(stderr, "opened database successfully\n");
    } 
*/	
    int itemCount = 0;//sets default item count to 0
	while(1){
        printf("\nPrime Market Inventory Management System\n");
        printf("1. Edit\n");
        printf("2. Display Inventory\n");
	printf("3. Load Inventory\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        int choice;
        scanf("%d", &choice);
	printf("\n\n");
        switch (choice) {
            case 1:
		edit();
                break;
            case 2:
		//display();
	        printf("Placeholder\n");
                break;
		case 3:
		//createDatabase();
		printf("Placeholder\n");
            case 4:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");

	}
    }
    return 0;
		
}


void edit(int itemCount, struct itemInfo){
	
	int choice;
	printf("\n\n");
	printf("1. Add Item\n");
	printf("2. Update Item\n");
	printf("3. Back to main menu\n");
	
	scanf("%d", &choice);
	switch(choice){
	case 1:
		addItem(itemCount);
		break;
	case 2:
		//updateItem();	
		printf("Placeholder\n");
		break;
	case 3: 
		main();
		break;
	default:
		printf("ERROR: Selection out of bounds\n");
	}
}





