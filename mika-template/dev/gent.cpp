#include <cstdio>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

const string DEF_TYP = ".cpp";

string out, typ, cwd;

/**
 * path utils
 * */
string get_typ(string &t) {
	int len = t.length();
	for (int i = len-1; i >= 0; i--) {
		if (t[i] == '.') return t.substr(i, len-i);
	}
	t += DEF_TYP;
	return DEF_TYP;
}


/**
 * template generator
 * */
void gen_template() {
	ifstream tsrc(cwd + "/template/t" + typ);
	ofstream csrc(cwd + "/template/c" + typ);
	//
	string line;
	time_t t = time(0);
	while (getline(tsrc, line)) {
		// maybe we should add more macro in the future
		if (line == "{{date}}") {
			csrc << "created:\t" << ctime(&t);
		} else {
			csrc << line << "\n";
		}
	}
}


/**
 * drivers
 * */
int main(int argc, char const *argv[]) {
	if (argc < 2) {
		printf("too few arguments\n");
		return 0;	
	}
	//
	cwd = std::getenv("EXC"); cwd += "/mika-template";
	out = argv[1];
	typ = get_typ(out);
	//
	gen_template();
	string exec = "cp " + cwd + "/template/c" + typ + " \"" + out + "\"";
	system(exec.c_str());
	return 0;
}
