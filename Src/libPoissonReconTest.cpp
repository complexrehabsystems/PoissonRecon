#include <iostream>
#include <string>
#include <vector>

#include "libPoissonRecon.h"

using namespace std;

vector<string> split(const string& str, const string& delim)
{
  vector<string> tokens;
  size_t prev = 0, pos = 0;
  do
  {
    pos = str.find(delim, prev);
    if (pos == string::npos) pos = str.length();
    string token = str.substr(prev, pos - prev);
    if (!token.empty()) tokens.push_back(token);
    prev = pos + delim.length();
  } while (pos < str.length() && prev < str.length());
  return tokens;
}

int main(int argc, char* argv[]) {
  cout << "argc: " << argc << endl;
  cout << "argv: " << argv << endl;

  string folderPath = "C:\\Users\\pack3\\Downloads\\";

  std::string args = "PoissonRecon.exe --in " + folderPath + "master.ply --out " + folderPath + "bananas.ply";
  args += " --degree 2";
  args += " --depth 9";
  args += " --iters 10";
  args += " --scale 2";
  args += " --colors";
  args += " --normals";
  args += " --density";
  args += " --inCore";
  args += " --noComments";

  // std::string s = "scott>=tiger>=mushroom";
  // std::string delimiter = " ";
  //
  // size_t pos = 0;
  // std::string token;
  // while ((pos = args.find(delimiter)) != std::string::npos) {
  //   token = args.substr(0, pos);
  //   std::cout << token << std::endl;
  //   args.erase(0, pos + delimiter.length());
  // }

  auto tokens = split(args, " ");

  char* cargs[18];

  auto i = 0;
  for (auto& t : tokens)
  {
    char* writable = new char[t.size() + 1];
    std::copy(t.begin(), t.end(), writable);
    writable[t.size()] = '\0'; // don't forget the terminating 0

    cout << "argv[" << i << "]: " << writable << endl;
    cargs[i] = writable;
    // don't forget to free the string after finished using it
    i++;

    // NOTE: need to delete writables somewhere...
  }

  runPoissonRecon(18, cargs);
}


