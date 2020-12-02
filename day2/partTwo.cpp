#include <iostream>
#include <fstream>

int main() {
  std::ifstream inputFile("input.txt");
  std::string line;

  int amountValidPasswords;

  if (inputFile.is_open()) {
    while(getline(inputFile, line)) {
      std::string policy = line.substr(0, line.find(":"));
      char policyLetter = policy.substr(policy.size()-1)[0];
      std::string password = line.substr(policy.size()+2, line.size());
      std::string lowestAsString = policy.substr(0, policy.find("-"));
      int lowest = std::stoi(policy.substr(0, policy.find("-")));
      std::string highestAsString = policy.substr(lowestAsString.size()+1, policy.size());
      int highest = std::stoi(highestAsString);

      if ((password[lowest-1] == policyLetter) ^ (password[highest-1] == policyLetter)) {
        amountValidPasswords++;
      }
    }
  }
  std::cout << "Amount of valid passwords: " << amountValidPasswords << std::endl;
}