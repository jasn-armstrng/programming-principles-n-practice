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
int main()
{


  return 0;
}
