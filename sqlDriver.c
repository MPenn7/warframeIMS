#include <stdio.h>
#include <sqlite3.h>


struct sqlVars{
sqlite3 *db;
int rc;
char *sql;
};

int main();
//declares main that is found in PrimeMarketIMS, or the main file. Used when going back to main menu

int addItem();
//declares addItem that is found in addItem.c. Used to get values for insert

static int callback(void *NotUsed, int argc, char **argv, char **azColName){

	for(int i = 0; i<argc; i++){
		printf("%s = %s\n", azColName[i], argv[i] ? argv[i] :"Null");
	}
	printf("\n");
	return 0;

}

int createTable(){
	
	struct sqlVars vars;
	char *zErrMsg = 0;

	vars.rc = sqlite3_open("warframeIMS.db", &vars.db);

	if(vars.rc){
	fprintf(stderr, "Can't open database: %s \n", sqlite3_errmsg(vars.db));
	return 0;
	} else {
	fprintf(stdout, "Opened database successfully\n");
	}

	vars.sql = "CREATE TABLE IF NOT EXISTS WarframeSet(" \
	      "SKU INT PRIMARY KEY	," \
	      "NAME		TEXT	," \
	      "QOH 		INT	," \
	      "QIR		INT	," \
	      "PRICE		INT	);";
       vars.rc = sqlite3_exec(vars.db, vars.sql, callback, 0, &zErrMsg);

	
	vars.sql = "CREATE TABLE IF NOT EXISTS PrimaryWeapon(" \
	      "SKU INT PRIMARY KEY	," \
	      "NAME		TEXT	," \
	      "QOH 		INT	," \
	      "QIR		INT	," \
	      "PRICE		INT	);";
       vars.rc = sqlite3_exec(vars.db, vars.sql, callback, 0, &zErrMsg);
       
	vars.sql = "CREATE TABLE IF NOT EXISTS SecondaryWeapon(" \
	      "SKU INT PRIMARY KEY	," \
	      "NAME		TEXT	," \
	      "QOH 		INT	," \
	      "QIR		INT	," \
	      "PRICE		INT	);";
       vars.rc = sqlite3_exec(vars.db, vars.sql, callback, 0, &zErrMsg);

	vars.sql = "CREATE TABLE IF NOT EXISTS Melee(" \
	      "SKU INT PRIMARY KEY	," \
	      "NAME		TEXT	," \
	      "QOH 		INT	," \
	      "QIR		INT	," \
	      "PRICE		INT	);";
       vars.rc = sqlite3_exec(vars.db, vars.sql, callback, 0, &zErrMsg);


	vars.sql = "CREATE TABLE IF NOT EXISTS ETC(" \
	      "SKU INT PRIMARY KEY	," \
	      "NAME		TEXT	," \
	      "QOH 		INT	," \
	      "QIR		INT	," \
	      "PRICE		INT	);";
       vars.rc = sqlite3_exec(vars.db, vars.sql, callback, 0, &zErrMsg);


       if(vars.rc != SQLITE_OK){
	fprintf(stderr, "SQL error: %s\n", zErrMsg);
	sqlite3_free(zErrMsg);
	} else {
	fprintf(stdout, "Table created successfully\n");
	}
       sqlite3_close(vars.db);
       return 0;
}


int sqlDriver(){

	char *zErrMsg = 0;	
	struct sqlVars vars;

	vars.rc = sqlite3_open("warframeIMS.db", &vars.db);
	
	if(vars.rc){
	   fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(vars.db));
	   return 0;
	} else {
	   fprintf(stderr, "Opened database successfully\n");
	}
	sqlite3_close(vars.db);	

}
