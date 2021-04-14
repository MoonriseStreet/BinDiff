
#include "File.h"

const int a = 5;

File::File(std::string filename) {
  stream = std::fopen(filename, 'wb+');
}

File::~File() { std::close(stream); }

const std::string File::operator-(const File &another) {
  std::string dif_file_name = "dif_file";
  size_t new_size =
      another.size(); // это делается с помощью state, долго писать
  DifFile difference(dif_file_name, new_size);

  size_t pos = -1;
  size_t common_length = -1;
  size_t diff_length = -1;
  size_t last_block = -1;

  Diff diff_block;
  char curr1, curr2;
  while (std::fread(&curr2, sizeof(char), 1, another.stream)) {
    pos++;
    if (std::fread(&curr1, sizeof(char), 1, stream)) {
      if (curr1 == curr2) {
        diff_length = -1;
        if (common_length == -1) {
          last_block = pos;
          diff_block.offset = pos;
        }
        common_length++;
      } else {
        common_length = -1;
        diff_length++;
        if (diff_length == a && last_block != -1) {
          diff_block.size = pos - last_block - a;
          diff_block.data = std::vector<char>(pos - last_block - a);
          std::fseek(another.stream, last_block, SEEK_SET);
          for (auto &i : diff_block.data) {
            std::fread(&curr2, sizeof(char), 1, another.stream);
            i = curr2;
          }
          std::fwrite((char *)diff_block, sizeof(diff_block), 1,
                      difference.stream);
        }
      }
    } else {
      // обработка случая, когда старый файл был короче
      // нужно сделать ещё одну структуру Diff
    }
  }
  while (std::fread(&curr1, sizeof(char), 1, stream)) {
    // обработка случая, когда новый файл короче старого
  }
  return dif_file_name;
}

const File File::apply_dif(std::string &dif_file) {
  DifFile difference(dif_file, 0);
  Diff curr_diff;
  File new_file;
  // прочитать из difference одну структуру Diff

  size_t pos = -1;
  size_t curr1, curr2;
  while(std::fread(&curr1, sizeof(char), 1, stream)) {
    pos++;
    if (curr_diff.offset > pos) {
      std::fwrite(curr1, sizeof(char), 1, new_file.stream);
    } else {
      // загрузить в файл несовпадающий кусок из Diff
      // сдвинуть дескриптор на старом файле
      // загрузить новый Diff
    }
  }
}