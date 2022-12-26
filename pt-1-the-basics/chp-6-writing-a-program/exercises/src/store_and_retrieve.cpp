/*
  Reworking of store_and_retrieve.cpp - Chp 6. exercise 4
  --------------------------------------------------------
  Program allows user to store a list of "player score" pairs and provides the
  following features:
    1. Notifification when a duplicate name is to be processed. The name is
      not stored and the user is allowed to continue.
    2. View all entries
    3. Search entries for a given name
      -- notification if name does not exist
    4. Search entries for a given score.
      -- notification user if score does not exist
    5.Exit program.
*/

#include "../headers/store_and_retrieve.h"

int main()
{
  ui();
  return 0;
}
