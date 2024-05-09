#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <sqlite3.h>
#define MAX_LIMIT 90


struct itemInfo{
int sku;
char name[MAX_LIMIT];
int QOH;
int QIR;
int price;
};

int main();
//declares main that is found in PrimeMarketIMS, or the main file. Used when going back to main menu


int addItem(int itemCount){
    	char newItemQueue[5]; //this is the buffer that allows the user input to be put into the correct SQL query 
    	struct itemInfo newItem; //This takes the vars from the struct and allows use in the function
    	int type; //var used to take the input from the user

    	printf("\n\n");

    	printf("Please enter the type of item: \n");
    	printf("---------------\n");
    	printf("1. Warframe Set\n");
    	printf("2. Primary Weapon\n");
    	printf("3. Secondary Weapon\n");
    	printf("4. Melee\n");
    	printf("5. Mods or etc\n");
    	printf("6. Return to main menu\n");
    
    	scanf("%d", &type);
 
    	printf("\n\n");
	//menu and scanner

    	switch(type){
        	case 1:
            	   newItem.sku = 1000 + itemCount + 1;
            	break;
        case 2:
            	   newItem.sku = 2000 + itemCount + 1;
           	break;
        case 3:
            	   newItem.sku = 3000 + itemCount + 1;
            	break;
        case 4:
          	   newItem.sku = 4000 + itemCount + 1;
          	break;
        case 5:
        	   newItem.sku = 5000 + itemCount + 1;
        	break;
	case 6:
	    	   main();
	    	break;
	default:
	    	   printf("ERROR: Selection outside of bounds");
	    	break;
    } // gives a prefex to differentate the different types of items as well as sets default incase the wrong input is entered. Also sets itemCount up.

	

    	printf("Enter the name of the item: ");
    	scanf(" %90[^\n]", newItem.name);
    	printf("\n");
	//gets the name from the user and sets a character limit to the input
	
    	printf("Enter the QOH of the item: ");
    	scanf("%d", &newItem.QOH);
    	printf("\n");
	//gets the quantity on hand from the user

    	printf("Enter the number of relics this item is in: ");
    	scanf("%d", &newItem.QIR); 
    	printf("\n");
	//gets the number of relics this item is in. Acts like a bool and needs to be changed but like idc rn

    	printf("Enter the price of this item: ");
    	scanf("%d", &newItem.price);
    	printf("\n");
	//gets the price from the user

	/*
    	newItemQueue[1] = newItem.sku;
    	newItemQueue[2] = newItem.name;
    	newItemQueue[3] = newItem.QOH;
    	newItemQueue[4] = newItem.QIR;
    	newItemQueue[5] = newItem.price;
	*/
	//Sets the buffer queue to the values the user put in. 


return 0; 
    }

