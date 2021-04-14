

#ifndef BINDIFF_DIFF_H
#define BINDIFF_DIFF_H

struct Diff {

  long int offset = 0;
  long int size = 0;
  char data[];

};


#endif // BINDIFF_DIFF_H
