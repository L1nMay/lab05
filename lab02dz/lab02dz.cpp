#include <iostream>

int main() {
  // Объявляем переменную для хранения имени пользователя.
  std::string name;
  // Запрашиваем имя пользователя.
  std::cout << "Enter your name: ";
  std::cin >> name;
  // Выводим приветствие.
  std::cout << "Hello world from " << name << std::endl;
  return 0;
}
