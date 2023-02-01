// Program description:
#include <iostream>
#include "../headers/name_pairs.h"

int main() {
  Name_pairs name_pairs;
  name_pairs.read_name_age();
  std::cout << name_pairs;

  return 0;
}
