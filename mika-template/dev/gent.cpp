#include <cstdio>
#include <fstream>
#include <string>
#include <ctime>
using namespace std;

const string DEF_TYP = ".cpp";

string out, typ, cwd;


/**
 * string utils
 * */
bool replace(string& str, const string from, const string to) {
    size_t start_pos = str.find(from);
    if(start_pos == string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}


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
 * timedate utils
 * */
string mdtime(time_t& now) {
	static string MONTHS[12] = {
		"Jan", "Feb", "Mar", 
		"Apr", "May", "Jun", 
		"Jul", "Aug", "Sep", 
		"Oct", "Nov", "Dec", 
	};
	//
	tm *lct = localtime(&now);
	string year  = to_string(1900 + lct->tm_year),
	       month = MONTHS[lct->tm_mon],
	       day   = to_string(lct->tm_mday);
	return month + '-' + day + '-' + year;
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
	string cr_time = ctime(&t);
	cr_time = cr_time.substr(0, cr_time.length()-1);	// remove the \n
	//
	while (getline(tsrc, line)) {
		// maybe we should add more macro in the future
		replace(line, "{{date}}", cr_time);
		replace(line, "{{mdtime}}", mdtime(t));
		csrc << line << "\n";
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
