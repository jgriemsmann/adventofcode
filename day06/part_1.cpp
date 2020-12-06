#include <iostream>
#include <set>

int main() {
  std::string line;
  std::set<char> uniqueGroupAnswers;
  int sumOfGroupAnswers = 0;

  while(getline(std::cin, line)) {
    if (line.empty()) {
      sumOfGroupAnswers += uniqueGroupAnswers.size();
      uniqueGroupAnswers.clear();
    } else {
      for (auto it = line.begin(); it != line.end(); ++it) {
        uniqueGroupAnswers.insert(*it);
      }
    }
  }
  sumOfGroupAnswers += uniqueGroupAnswers.size();
  std::cout << "Sum of group answers: " << sumOfGroupAnswers << std::endl;
  return 0;
}