

#ifndef BINDIFF_DIFF_H
#define BINDIFF_DIFF_H

struct Diff {

  long int offset = 0;
  long int size = 0;
  std::vector<char> data{};

};


#endif // BINDIFF_DIFF_H
