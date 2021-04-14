
#include "File.h"

File::File(std::string filename) {
  stream = std::fopen(filename, 'r');
}

File::~File() {
  std::close(stream);
}

const std::string DifFile File::operator-(const File &another) {
  return "Имя созданного файла";
}

const std::string File::apply_dif(const DifFile &difference) {
  return "Имя созданного файла";
}