#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sqlite3.h>
#define MAX_LIMIT 90

struct itemInfo{
int sku;
char name[MAX_LIMIT];
int QOH;
int QIR;
int price;
};

static int callb(void *NotUsed, int argc, char **argv, char **azColName){

	for(int i = 0; i<argc; i++){
	printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
	}
	printf("\n");
	return 0;
}

int main();
//declares main that is found in PrimeMarketIMS, or the main file. Used when going back to main menu

int addItem(int itemCount){
	struct itemInfo newItem;
	int type; //var used to take the input from the user


	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;	

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

	itemCount = 0;

    	switch(type){
        case 1:		  
	       	   newItem.sku = 1000 + itemCount + 1;
            	   break;
        case 2:
            	   newItem.sku = 2000 + itemCount + 1;
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

	
	rc = sqlite3_open("warframeIMS.db", &db);

	if(rc){
		fprintf(stderr, "Can't open database %s\n", sqlite3_errmsg(db));
		return 0;
	} else 
		fprintf(stderr, "Opened database successfully");
	
	sqlite3_stmt *stmt;
	const char *sql;
	const char *name = newItem.name;
	const int sku = newItem.sku;
	const int QOH = newItem.QOH;
	const int QIR = newItem.QIR;
       	const int price = newItem.price;	
	switch(type){
	case 1:	
		
		sql = "INSERT INTO WarframeSet (SKU, NAME, QOH, QIR, PRICE) VALUES (?1, ?2, ?3, ?4, ?5)";
		rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL );		
		rc = sqlite3_bind_int(stmt, 1, sku);
		rc = sqlite3_bind_text(stmt, 2, name, -1, SQLITE_TRANSIENT);
		rc = sqlite3_bind_int(stmt, 3, QOH);
		rc = sqlite3_bind_int(stmt, 4, QIR);
		rc = sqlite3_bind_int(stmt, 5, price);

		rc = sqlite3_step(stmt);
		rc = sqlite3_exec(db, sql, callb, 0, &zErrMsg);

		if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		} else {
		fprintf(stdout, "Records created successfully\n");
		}
		
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		break;
	case 2:
		
		sql = "INSERT INTO PrimaryWeapon (SKU, NAME, QOH, QIR, PRICE) VALUES (?1, ?2, ?3, ?4, ?5)";
		rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL );		
		rc = sqlite3_bind_int(stmt, 1, sku);
		rc = sqlite3_bind_text(stmt, 2, name, -1, SQLITE_TRANSIENT);
		rc = sqlite3_bind_int(stmt, 3, QOH);
		rc = sqlite3_bind_int(stmt, 4, QIR);
		rc = sqlite3_bind_int(stmt, 5, price);

		rc = sqlite3_step(stmt);
		rc = sqlite3_exec(db, sql, callb, 0, &zErrMsg);

		if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		} else {
		fprintf(stdout, "Records created successfully\n");
		}
		
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		break;
	case 3:
			
		sql = "INSERT INTO SecondaryWeapon (SKU, NAME, QOH, QIR, PRICE) VALUES (?1, ?2, ?3, ?4, ?5)";
		rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL );		
		rc = sqlite3_bind_int(stmt, 1, sku);
		rc = sqlite3_bind_text(stmt, 2, name, -1, SQLITE_TRANSIENT);
		rc = sqlite3_bind_int(stmt, 3, QOH);
		rc = sqlite3_bind_int(stmt, 4, QIR);
		rc = sqlite3_bind_int(stmt, 5, price);

		rc = sqlite3_step(stmt);
		rc = sqlite3_exec(db, sql, callb, 0, &zErrMsg);

		if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		} else {
		fprintf(stdout, "Records created successfully\n");
		}
		
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		break;
	case 4:
			
		sql = "INSERT INTO Melee (SKU, NAME, QOH, QIR, PRICE) VALUES (?1, ?2, ?3, ?4, ?5)";
		rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL );		
		rc = sqlite3_bind_int(stmt, 1, sku);
		rc = sqlite3_bind_text(stmt, 2, name, -1, SQLITE_TRANSIENT);
		rc = sqlite3_bind_int(stmt, 3, QOH);
		rc = sqlite3_bind_int(stmt, 4, QIR);
		rc = sqlite3_bind_int(stmt, 5, price);

		rc = sqlite3_step(stmt);
		rc = sqlite3_exec(db, sql, callb, 0, &zErrMsg);

		if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		} else {
		fprintf(stdout, "Records created successfully\n");
		}
		
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		break;
	case 5:
			
		sql = "INSERT INTO ETC (SKU, NAME, QOH, QIR, PRICE) VALUES (?1, ?2, ?3, ?4, ?5)";
		rc = sqlite3_prepare_v2(db, sql, -1, &stmt, NULL );		
		rc = sqlite3_bind_int(stmt, 1, sku);
		rc = sqlite3_bind_text(stmt, 2, name, -1, SQLITE_TRANSIENT);
		rc = sqlite3_bind_int(stmt, 3, QOH);
		rc = sqlite3_bind_int(stmt, 4, QIR);
		rc = sqlite3_bind_int(stmt, 5, price);

		rc = sqlite3_step(stmt);
		rc = sqlite3_exec(db, sql, callb, 0, &zErrMsg);

		if(rc != SQLITE_OK){
		fprintf(stderr, "SQL error: %s\n", zErrMsg);
		sqlite3_free(zErrMsg);
		} else {
		fprintf(stdout, "Records created successfully\n");
		}
		
		sqlite3_finalize(stmt);
		sqlite3_close(db);
		break;
	case 6:
		main();
		break;
	default:
		printf("ERROR: Selection outside of bounds");
		break;
	}
	sql = "";
return 0; 
    }

