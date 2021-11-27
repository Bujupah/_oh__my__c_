#include <stdio.h>
#include <stdlib.h>

#define DB FILE*
#define HISTORIES_DB_PATH "db/histories.csv"
#define PRODUCTS_DB_PATH "db/products.csv"
#define CLIENTS_DB_PATH "db/clients.csv"

DB DB_CLIENT;
DB DB_PRODUCT;
DB DB_HISTORY;

DB open_db(char *db_path) {
  DB db = fopen(db_path, "r");
  if (db == NULL) {
    db = fopen(db_path, "w");
    if (db == NULL) {
      perror("Error while opening the db file.\n");
      exit(EXIT_FAILURE);
    }
  }
  return db;
}

void add_record_db(DB db, char* content) {
  fprintf(db, content);
  // save_db(db);
}

void save_db(DB db) {
  fclose(db);
}

void init_db() {
  DB_CLIENT = open_db(CLIENTS_DB_PATH);
  DB_PRODUCT = open_db(PRODUCTS_DB_PATH);
  DB_HISTORY = open_db(HISTORIES_DB_PATH);
}

char* read_db(DB db) {
  char ch;
  int i = 0;
  char* content = malloc(sizeof(char));
  while((ch = fgetc(db)) != EOF) {
      content[i] = ch;
      i++;
  }
  fclose(db);
  return content;
}