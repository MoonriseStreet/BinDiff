
#include "DifFile.h"


DifFile::DifFile(std::string filename) {
  stream = std::fopen(filename, 'w');
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