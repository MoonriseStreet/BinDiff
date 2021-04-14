
#include "File.h"

File::File(std::string filename) {
  stream = std::fopen(filename, 'wb');
}

File::~File() {
  std::close(stream);
}

const std::string File::operator-(const File &another) {
  std::string dif_file_name = "dif_file";
  DifFile difference(dif_file_name);

  return dif_file_name;
}

const File File::apply_dif(std::string &dif_file) {
  DifFile difference(dif_file, 0);

}