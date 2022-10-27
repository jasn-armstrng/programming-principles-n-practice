// This program list the instructions for a "player" to find the bathroom at a home.
// Layout of ground floor:
// +------------------------+
// |                        |
// |                        |
// |                        |
// |---------+              |
// |          \ (C)         |
// |         |     =========|
// |=o (D)   |              |
// +---------------   /------+
//                   / <- (B)
//                 Y <- (A)
// A - Start point of the "player" -> centre of doorway, 1.5 ft away.
// B - Front door of house
// C - Bathroom door
// D - Toilet

#include <iostream>
int main(){
  std::cout << "+-----------------------------------------------------------------------------+\n";
  std::cout << "|                            Find the bathroom                                |\n";
  std::cout << "+-----------------------------------------------------------------------------+\n";
  std::cout << "\n";
  std::cout << "Layout of ground floor:\n";
  std::cout << "+------------------------+\n";
  std::cout << "|                        |\n";
  std::cout << "|                        |\n";
  std::cout << "|                        |\n";
  std::cout << "|---------+              |\n";
  std::cout << "|          \\ (C)         |\n";
  std::cout << "|         |     =========|\n";
  std::cout << "|=o (D)   |              |\n";
  std::cout << "+---------------   /-----+\n";
  std::cout << "                  / <- (B)\n";
  std::cout << "                  . <- (A)\n";
  std::cout << "\n";
  std::cout << " A - Start point of the player -> centre of doorway, 1.5 ft away.\n";
  std::cout << " B - Front door of house\n";
  std::cout << " C - Bathroom door\n";
  std::cout << " D - Toilet\n";
  std::cout << "\n";
  std::cout << "Preconditions: 1. Player begins at facing the middle of the front door.\n";
  std::cout << "               2. Player is 1.5 feet from the front door.\n";
  std::cout << "\n";
  std::cout << " 1. Move 1 side-step left.\n";
  std::cout << " 2. Identify the door handle.\n";
  std::cout << " 3. Extend right hand 45 degrees downward to make contact with door handle.\n";
  std::cout << " 4. Grip door handle.\n";
  std::cout << " 5. Turn door handle clockwise.\n";
  std::cout << " 6. Turn up to a 45 degree angle.\n";
  std::cout << " 7. Apply a pull force of 0.025N to door handle.\n";
  std::cout << " 8. Apply force until door is 90 degrees from its start position.\n";
  std::cout << " 9. Remove hand from door handle.\n";
  std::cout << "10. Move 1 side-step right.\n"; // step() can be function taking args - forward, back, side
  std::cout << "11. Move forward 4 steps.\n";
  std::cout << "12. Turn 90 degrees to the left.\n";
  std::cout << "13. Move forward 2.5 steps.\n";
  std::cout << "14. Turn 90 degrees to the right.\n";
  std::cout << "15. Move forward 4 steps.\n";
  std::cout << "16. Turn 90 degrees to the left.\n";
  std::cout << "17. Repeat steps 2-10.\n"; // Steps 2-10 can be grouped as a open_door() function.
  std::cout << "18. Move forward 3 steps.\n";
  std::cout << "19. Turn 90 degrees to the left.\n";
  std::cout << "20. Move forward 4 steps.\n";
  std::cout << "21. Turn 90 degrees to the right.\n";
  std::cout << "22. End.\n";
  return 0;
}
