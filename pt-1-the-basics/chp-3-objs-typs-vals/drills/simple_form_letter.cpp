/*
  This program produces a simple form letter based on
  user input.

  How it works:
   1. Prompt user for their first name and greet them. Store as author.
   2. Prompt user for the first name of the recipient. Store in recipient.
   3. Start building letter string with "Dear <recipient>,""
   4. Then add "<tab>How are you? I am fine. I miss you." to letter body.
   5. Add some more conversation to the letter.
   6. Prompt user for another friend's name. Store as friend_name.
   7. Add line "Have you seen <friend_name> lately?"
   8. Prompt the user for the sex (m/f) of friend from 5.. Store in friend_sex.
   9. Use if-statement to add the following pronouned line,
      "If you see <friend_name> tell him/her to call me."
  10. Prompt the user for the age of the recipient. Store in age.
  11. Add "I hear you just had a birthday and you are <age> years old."
  12. For 10. if the age <= 0 or >= 110 call simple_error("you're kidding!").
  13. Add the following condition based sentences to letter,
      If <friend_name>.<age> < 12: "Next year you will be <age+1>?"
      If <friend_name>.<age> > 17: "Next year you will be able to vote."
      If <friend_name>.<age> > 70: "I hope you are enjoying retirement."
  14. Add "Yours sincerely" followed by 2 blank lines for a signature, followed
      by <author>.
*/

#include <iostream>
#include <ostream> // for cerr: standard error stream

inline void simple_error(std::string s)
  // write error s and exit program
{
  std::cerr << "error: " << s << '\n';
  exit(1);
}

int main()
{
  // 1. Prompt user for their first name.
  std::cout << "Please enter your first name: ";
  std::string author;
  std::cin >> author;
  // Greet user.
  std::cout << "\nHello, " << author << ". Welcome to a simple form letter builder.\n";

  // Letter that will be built over course of program.
  std::string letter {"Dear "};

  // 2. Prompt user for the name of the recipient.
  std::cout << "\nStep 1. Enter the first name of the recipient: ";
  std::string recipient;
  std::cin >> recipient;

  // 3. Add salutation to letter.
  letter += (recipient + ",\n");
  // std::cout << letter; // view letter check to verify letter is built correctly.

  // 4-5. Add opening lines.
  letter += " How are you? I am fine. I miss you. I am sorry it took so\nlong for me to contact you.\n";
  // std::cout << letter;

  // 6. Prompt author for the name of the friend they're writing to inquire about.
  std::cout << "\nStep 2. Enter the first name of the recipient's friend: ";
  std::string friend_name;
  std::cin >> friend_name;

  // 7. Add friend inquiry to letter.
  letter += ("\nHave you seen "+ friend_name + " lately? ");
  // std::cout << letter;

  // 8. Prompt for the sex of the friend.
  std::cout << "\nStep 3. Enter the sex (m/f) of the recipient's friend: ";
  char friend_sex;
  std::cin >> friend_sex;

  // 9. Use conditionals to format next sentence in letter.
  if (friend_sex == 'f')
    letter += ("If you see " + friend_name + " tell her to call me.\n");
  else
    letter += ("If you see " + friend_name + " tell him to call me.\n");

  // 10. Prompt for the age of recipient
  std::cout << "\nStep 4. Enter the age of the recipient: ";
  int age;
  std::cin >> age;
  if (age <= 0 || age >= 110)
    simple_error("You're kidding!");

  // 11. Add birthday acknowledgement
  letter += ("\nI hear you just had a birthday and you are "+ std::to_string(age) + " years old.");

  std::cout << letter;

  return 0;
}
