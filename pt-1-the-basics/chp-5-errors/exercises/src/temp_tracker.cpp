// This program stores and presents the avg. temperature of all the days of a
// given week, computes and presents the avg. temperature for the given week.
#include <iostream>
#include <vector>

// ------------------------- function decs -------------------------------------
void ui();
inline void error(const std::string& s);
std::vector<std::vector<std::string> > update(const int week, const std::string day,
                       const int temp, std::vector<std::vector<std::string> > temps);
void index(const std::vector<std::vector<std::string> > temps);

int main()
try {
  ui();
  return 0;
}
catch (std::exception& e) {
  std::cerr << "Error: " << e.what() << '\n';
  return 1;
}
catch (...) {
  std::cerr << "Error: Unknown exception\n";
  return 2;
}

// ------------------------- function defs -------------------------------------
inline void error(const std::string& s) { throw std::runtime_error(s); }

void ui(){
  // create a 2D vector for temps
  std::vector<std::vector<std::string> > temperatures;
  // initialize with number of weeks(lvl-1) and days(lvl-2)
  int weeks = 3, days = 7;
  // 3 out 52 weeks used here for demo. Each day has the default value '-'
  temperatures.resize(weeks, std::vector<std::string>(days, "-"));

  // week_number corresponds to a lvl-1 index of the temp vector
  int week_number;
  // day mapped to a lvl-2 index of the 2D vector in the update function
  std::string day;
  // value at a lvl-2 index of the 2D vector in the update function
  int temp;

  // used to continue or break from record entry loop
  char more_records;
  bool data = true;

  while(data){
    // get data from user
    std::cout << "Enter the week#: ";
    std::cin >> week_number;
    std::cout << "Enter the day: ";
    std::cin >> day;
    std::cout << "Enter the avg. temperature: ";
    std::cin >> temp;

    // update temp record for week/day in 2D vector
    temperatures = update(week_number, day, temp, temperatures);

    // show all recorded temps
    index(temperatures);

    // record more temperatures or quit the program
    std::cout << "\nEnter another week/day/temp [y/n]: ";
    std::cin >> more_records;
    if (more_records == 'n' || more_records == 'N') {
      data = false;
    }
    std::cout << '\n';
  }
}

std::vector<std::vector<std::string> > update(const int week, const std::string day,
                       const int temp, std::vector<std::vector<std::string> > temps) {
    // update the temperature vector week/day elements with valid entries
    // pre-conditions: 1 <= week <= 52, day like Mon or monday, -90 >=temp <= 58
    //                 , temps is a 2D vector
    // post-condtions: returns updated week and day in 2D vector temps

    // convert temp to string to store
    std::string t = std::to_string(temp);

    // throw error if week, day inputs are invalid
    if (week < 1 || week > 52) { error("Invalid input for week#"); }
    if (temp < -90 || temp > 58) { error("Temperature input outside normals"); }

    // update temp values if valid day synonym entered, throw error if not
    if (day == "Mon" || day == "monday") {
      temps[week-1][0] = t;
    } else if (day == "Tues" || day == "tuesday") {
      temps[week-1][1] = t;
    } else if (day == "Wed" || day == "wednesday") {
      temps[week-1][2] = t;
    } else if (day == "Thur" || day == "thursday") {
      temps[week-1][3] = t;
    } else if (day == "Fri" || day == "friday") {
      temps[week-1][4] = t;
    } else if (day == "Sat" || day == "saturday") {
      temps[week-1][5] = t;
    } else if (day == "Sun" || day == "sunday") {
      temps[week-1][6] = t;
    } else {
      error("Invalid input for day");
    }
    return temps;
}

void index(const std::vector<std::vector<std::string> > temps) {
  // show table of all temps recorded for week/days
  // pre-condtion: temps vector should not be empty

  // output table header
  std::cout << "\nWeek\t" << "Mon\t" << "Tues\t" << "Wed\t" << "Thur\t" << "Fri\t"
            << "Sat\t" << "Sun\t\n";
  std::cout << "------------------------------------------------------------\n";

  // print each week and its 7 days of temps on a new line
  for (unsigned i = 0; i < temps.size(); ++i) {
    std::cout << i+1 << "\t";
    for (unsigned j = 0; j < temps[i].size(); ++j) {
      std::cout << temps[i][j] << "\t";
    }
    std::cout << '\n';
  }
}
