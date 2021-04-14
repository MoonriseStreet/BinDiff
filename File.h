
#ifndef BINDIFF_FILE_H
#define BINDIFF_FILE_H

#include <DifFile.h>
#include <Diff.h>
#include <string.h>
#include <stdio.h>

class File {
public:
  File(std::string filename);

  ~File();

  const std::string operator-(const File &another);

  const std::string apply_dif(const DifFile &difference);

private:
  std::FILE *stream = NULL;
};


#endif // BINDIFF_FILE_H
