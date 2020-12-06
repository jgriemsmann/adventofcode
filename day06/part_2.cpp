#include <iostream>
#include <vector>
#include <set>

unsigned calcSumOfCommonGroupAnswers(const std::set<char>& uniqueGroupAnswers, const std::vector<std::string>& personAnswers) {
  unsigned sumOfCommonGroupAnswers = 0;
  for (auto it_group = uniqueGroupAnswers.begin(); it_group != uniqueGroupAnswers.end(); ++it_group) {
    unsigned commonAnswers = 0;
    for (auto it_person = personAnswers.begin(); it_person != personAnswers.end(); ++it_person) {
      if ((*it_person).find(*it_group) != std::string::npos) {
        commonAnswers++;
      }
    }
    if (commonAnswers == personAnswers.size()) {
      sumOfCommonGroupAnswers++;
    }
  }
  return sumOfCommonGroupAnswers;
}

int main() {
  std::string line;
  std::set<char> uniqueGroupAnswers;
  unsigned sumOfCommonGroupAnswers = 0;
  std::vector<std::string> personAnswers;

  while(getline(std::cin, line)) {
    if (line.empty()) {
      sumOfCommonGroupAnswers += calcSumOfCommonGroupAnswers(uniqueGroupAnswers, personAnswers);
      uniqueGroupAnswers.clear();
      personAnswers.clear();
    } else {
      personAnswers.push_back(line);
      for (auto it = line.begin(); it != line.end(); ++it) {
        uniqueGroupAnswers.insert(*it);
      }
    }
  }
  sumOfCommonGroupAnswers += calcSumOfCommonGroupAnswers(uniqueGroupAnswers, personAnswers);
  std::cout << "Sum of group answers: " << sumOfCommonGroupAnswers << std::endl;
  return 0;
}