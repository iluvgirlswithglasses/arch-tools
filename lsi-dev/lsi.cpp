
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Nov  1 21:44:56 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <cstdio>
#include <memory>
#include <stdexcept>
#include <string>
#include <array>
using namespace std;

int main(int argc, char const *argv[]) {
	// list every item in directory
	string cmd = "ls ";
	if (argc >= 2) cmd += argv[1];
	array<char, 512> buffer;
	int cnt = 0;
	//
    unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
    	printf("%d\t%s", ++cnt, buffer.data());
    }
	return 0;
}

