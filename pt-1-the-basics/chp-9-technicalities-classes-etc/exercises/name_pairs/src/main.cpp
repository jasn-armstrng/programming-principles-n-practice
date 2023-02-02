/**
 * @file main.cpp
 * @author Jason Armstrong
 * @brief Solution for Chp 9 Ex 2-3
 * @version 0.1
 * @date 2023-02-01
 * @todo Handle bad <Name Age> inputs
 *
 */
#include <iostream>
#include "../headers/name_pairs.h"

int main()
{
  Name_pairs name_pairs;
  name_pairs.read_name_age();
  std::cout << name_pairs;

  return 0;
}
