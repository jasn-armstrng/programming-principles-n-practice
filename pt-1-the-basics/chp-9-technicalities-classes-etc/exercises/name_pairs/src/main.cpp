/*******************************************************************************
Description: Reads and stores <Name Age> pairs from user input. Prints pairs to
             console.
Created:     Feb 1, 2023
To do:       Handle bad <Name Age> inputs
*******************************************************************************/
#include <iostream>
#include "../headers/name_pairs.h"

int main()
{
  Name_pairs name_pairs;
  name_pairs.read_name_age();
  std::cout << name_pairs;

  return 0;
}
