#include <iostream>
#include <fstream>
#include <set>

bool validatePassport(const std::set<std::string>& keys, const std::string& passport) {
  for (auto it = keys.begin(); it != keys.end(); ++it) {
    if (passport.find(*it) == std::string::npos) {
      return false;
    }
  }
  return true;
}

int main() {
  std::ifstream inputFile("input.txt");
  std::string line;

  std::set<std::string> keys = {"byr", "iyr", "eyr", "hgt", "hcl", "ecl", "pid"};
  std::string passport;
  int counter = 1;
  int validPassports = 0;

  if (inputFile.is_open()) {
    while(getline(inputFile, line)) {
      if (line.empty()) {
        if (validatePassport(keys, passport)) {
          validPassports++;
        }
        passport = "";
        counter++;
      } else {
        passport.append(line);
      }
    }
    if (validatePassport(keys, passport)) {
      validPassports++;
    }
    std::cout << "Passports: " << counter << " valid: " << validPassports << std::endl;
  }
}
