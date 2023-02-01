// Program description:
#include <iostream>
#include "../headers/name_pairs.h"

int main() {
  Name_pairs name_pairs;
  name_pairs.read_names();
  name_pairs.read_ages();
  name_pairs.print();

  return 0;
}
