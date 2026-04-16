#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main() {
  const std::string file_name("albums.txt");
  std::ifstream file(file_name);

  if (!file) {
    std::cerr << "[ERROR] - Could not open file.\n";
    return -1;
  }

  std::vector<std::string> albums;
  std::string album_name;
  
  while(std::getline(file, album_name)) {
    albums.push_back(std::move(album_name));
  }

  if (file.bad()) {
    std::cerr << "[ERROR] - Failed while reading file.\n";
  }

  std::srand(std::time(nullptr));
  const std::string& drawn = albums[std::rand() % albums.size()];
  std::cout << "Your album is: " << drawn << "\n";

  return 0;
}