#include <iostream>
using namespace std;

/*
to build and run a cpp file:
    b <filename>    (without extension)
to build and run with stdin from file:
    b <filename> <testfile>
*/

int main(int argc, char const *argv[]) {
    if (argc < 2) {
        cout << "two few args\n";
    } else {
        string f = argv[1],
               compile = "g++ -o \"" + f + ".exe\" \"" + f + ".cpp\"",
               run = "\"./" + f + ".exe\"";
        if (argc == 3) {
            string test = argv[2];
            run = run + " < " + test;
        }
        run = run + " && rm \"./" + f + ".exe\"";
        //
        // cout << compile << "\n" << run << "\n";
        system(compile.c_str());
        if (argc == 2)
            cout << "compiled successfully, you can start typing input\n-------------------------------------------------\n";
        system(run.c_str());
    }
    return 0;
}
