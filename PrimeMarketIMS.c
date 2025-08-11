#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sqlite3.h>
#include <unistd.h>
#include "addItem.c"
#include "sqlDriver.c"
#define MAX_LIMIT 90
#define FALSE 0
#define TRUE 1

void edit();

//int createTable();

//int sqlDriver();



int main()
{
	sqlDriver();
	createTable();

	while(TRUE){
        printf("\nPrime Market Inventory Management System\n");
        printf("1. Edit\n");
        printf("2. Display Inventory\n");
	printf("3. Edit Database\n");
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
       choice = 0;	
    }
    return 0;
		
}


void edit(struct itemInfo){

	while(TRUE){
	int choice = 0;
	printf("\n\n");
	printf("1. Add Item\n");
	printf("2. Update Item\n");
	printf("3. Back to main menu\n");
	
	scanf("%d", &choice);
	switch(choice){
	    case 1:
		addItem();
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
		exit(0);
	}
    }
}
