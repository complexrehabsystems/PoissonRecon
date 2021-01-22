#include <iostream>
#include <string>
#include <vector>

#include "libPoissonRecon.h"

using namespace std;

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

  runPoissonRecon(args);

  cout << "DONE" << endl;
}


