/**
 * @file patron.h
 * @author Jason Armstrong
 * @brief Patron class, its and its members' definitions and helper functions
 * @version 0.1
 * @date 2023-02-07
 */

#include <iostream>

int number { 0 }; // incremented when a patron is created

class Patron
{
  public:
    // Constructor
    Patron(std::string user_name);

    // Getters
    std::string user_name() const { return User_Name; }
    std::string id() const { return ID; }
    double fees() const { return Fees; }
    bool has_fees() const { return (Fees > 0 ? true : false); }

    // Setters
    void add_fee(const double fee) { this->Fees += fee; }

  private:
    std::string User_Name;
    std::string ID;
    double Fees { 0 };
};


// Member function definitions .................................................
Patron::Patron(std::string user_name):User_Name{user_name}
{
  ++number;
  ID = std::to_string(number);
}

// Helper functions ............................................................
bool operator==(const Patron& a, const Patron& b)
{
  return (a.id() == b.id());
}
