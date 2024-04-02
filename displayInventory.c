#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//#include <sqlite3.h>
#define MAX_LIMIT 90

struct itemInfo {
  int sku;
  char name[MAX_LIMIT];
  int QOH;
  int QIR;
  int price;
};

int displayInventory(struct itemInfo inventory[], int itemCount){
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
return 0;
}
