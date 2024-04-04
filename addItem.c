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

int addItem(int itemCount){
    	char newItemQueue[5]; 
    	struct itemInfo newItem;    
    	int type;

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

    	//newItemQueue[1] = newItem.sku;
    	//newItemQueue[2] = name;
    	//newItemQueue[3] = newItem.QOH;
    	//newItemQueue[4] = newItem.QIR;
    	//newItemQueue[5] = newItem.price;
	//(itemCount)++;


   // sql = INSERT INTO COMPANY (SKU,NAME,QOH,QIR,PRICE)" \ "VALUES (
return 0; 
    }





