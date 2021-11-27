#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DB_PATH "db/%s.csv"

FILE *db; // read mode

void open_db(char *db_path) {
  char db_folder[50] = "db/";
  strcat(db_folder, db_path);
  strcat(db_folder, ".csv");
  snprintf( "db", "/", db_path, ".csv" );

  db = fopen(db_folder, "r");
  if (db == NULL) {
    db = fopen(db_path, "w");
    if (db == NULL) {
      perror("Error while opening the db file.\n");
      exit(EXIT_FAILURE);
    }
  }
}

void save_db() {
  fclose(db);
}

void read_db() {
}

int main()
{
  open_db("products");
  open_db("clients");
  open_db("history");
}
