struct Product {
  int id;
  char* name;
  char* description;
  double price;
  int stock;
};

void get_products() {
  int i = 0;
  char* content = read_db(DB_PRODUCT);
  puts(content);
  // char* products = malloc(sizeof(char));
  while(content[i] != '\0') {
    if (content[i] == '\n') {
      printf("one line");
    }
    i++;
  }
  // char* content = read_db(DB_PRODUCT);
  // puts(content);
}

void add_product(char* value) {
  add_record_db(DB_PRODUCT, value);
}