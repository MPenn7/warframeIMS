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

void initialize_file(){
static int initialized = 0;

	if(initialized == 0){
	     int itemCount = 0;
	     FILE* fptr;

	     fptr = fopen("itemCount.txt", "a");
	     if (fptr == NULL){
		printf("\nThe file has not opened");
	     } else{
    		printf("\nThe file has been created");
	     }
		
	    fscanf(fptr,"%d",&itemCount);
	    if(itemCount>0){
		   printf("%d", itemCount);
	    }else{
		   fprintf(fptr, "%d", itemCount);
	    }
	    fclose(fptr);
	   initialized = 1; 
	}else {
		printf("Initalization Complete");
	}
}

int main()
{
	sqlDriver();
	createTable();
	initialize_file();

	while(TRUE){
        printf("\nPrime Market Inventory Management System\n");
        printf("1. Edit\n");
        printf("2. Display Inventory\n");
	printf("3. Edit Database\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

	fscanf(fptr,"%d", itemCount);

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


void edit(int itemCount, struct itemInfo){
	
	int choice = 0;
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
		exit(0);
	}
}
