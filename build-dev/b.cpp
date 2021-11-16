
#include <iostream>
#include <string>
using namespace std;

// set default type here
const string DEF_TYP = ".cpp";

/*
to build and run a cpp file:
    b <filename>
to build and run with stdin from file:
    b <filename> <testfile>
*/

string src, f, typ, inp, compiler;

string get_compiler(string &typ) {
    if (typ == ".cpp") return "g++";
    if (typ == ".c") return "gcc";
    return "NULL";
}

/*
path utils
*/
string get_typ(string &t) {
	int len = t.length();
	for (int i = len-1; i >= 0; i--) {
		if (t[i] == '.') return t.substr(i, len-i);
	}
	t += DEF_TYP;
	return DEF_TYP;
}

/*
cmd gen
*/
string and_rm() {
    return " && rm \"./" + f + ".exe\"";
}

void compile(string &f, string &src, string &compiler) {
    string cmd = compiler + " -o \"" + f + ".exe\" \"" + src + "\"";
    cout << "$ " << cmd << "\n";
    system(cmd.c_str());
}

void run() {
    string cmd = "\"./" + f + ".exe\"" + and_rm();
    system(cmd.c_str());
}

void run(string &inp) {
    string cmd = "\"./" + f + ".exe\" < \"" + inp + "\"" + and_rm();
    system(cmd.c_str());
}

/*
drivers
*/
int main(int argc, char const *argv[]) {
    if (argc < 2) {
        cout << "two few args\n";
    } else {
        // name
        src = argv[1]; 
        typ = get_typ(src); // src can be modified here
        f = src.substr(0, src.length() - typ.length());
        // compile
        string compiler = get_compiler(typ);
        if (compiler == "NULL") {
            cout << "unsupported file type: " << typ << "\n";
            return 0;
        }
        compile(f, src, compiler);
        // execution
        if (argc == 2) {
            // stdin from terminal
            cout << "compiled successfully, you can start typing input\n-------------------------------------------------\n";
            run();
        } else {
            // stdin from file
            inp = argv[2];
            run(inp);
        }
    }
    return 0;
}
