#include "database.c"
#include "services/products.c"

int main() {
  init_db();
  add_product("1,Souris,100,10\n");
}
