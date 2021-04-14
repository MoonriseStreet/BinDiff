//
// Created by irina on 4/14/21.
//

#ifndef BINDIFF_DIFFILE_H
#define BINDIFF_DIFFILE_H

#include <Diff.h>
#include <stdio.h>

class DifFile {
public:
  DifFile();

  ~DifFile();

  void add_diff(const Diff &diff);
private:
  void write_header();

  std::FILE *stream = NULL;
};

#endif // BINDIFF_DIFFILE_H
