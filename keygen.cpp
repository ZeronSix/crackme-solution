#include <iostream>

constexpr unsigned XOR_CONSTANT = 0x1234 ^ 0x5678;

bool CheckIfUsernameIsValid(const std::string& str) {
  for (char c : str) {
    if (c < 'A') {
      return false;
    }
  }

  return true;
}

void MakeUppercase(std::string& str) {
  for (char& c : str) {
    if (c >= 'Z') { // it is implemented this way in the program
      c -= 0x20;
    }
  }
}

unsigned GenerateKey(const std::string& str) {
  unsigned sum = 0;

  for (char c : str) {
    sum += static_cast<unsigned>(c);
  }

  return sum ^ XOR_CONSTANT;
}

int main() {
  std::string user_name;
  std::cout << "Enter user name:" << std::endl;
  std::getline(std::cin, user_name);

  if (!CheckIfUsernameIsValid(user_name)) {
    std::cerr << "The user name is invalid!" << std::endl;
  } else {
    MakeUppercase(user_name);
    std::cout << "Key: " << GenerateKey(user_name) << std::endl;
  }

  return 0;
}
