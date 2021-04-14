
#include "DifFile.h"


DifFile::DifFile(std::string filename, bool new = True) {
  std::string flag = new ? 'wb' : 'rb';
  stream = std::fopen(filename, flag);
  write_header();
}

DifFile::~DifFile() {
  std::close(stream);
}

void DifFile::write_header() {
  return;
}

void DifFile::add_diff(const Diff &diff) {
  std::fwrite(&diff, sizeof(Diff), 1, stream);
  return;
}