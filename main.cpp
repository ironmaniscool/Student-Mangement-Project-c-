#include <iostream>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <string>

#include "StudentMangement.h"


int main(int argc, char* argv[]) {
	
	StudentMangement app;

	try {
		app.run();
	}
	catch(std::runtime_error& e) {
		std::printf("Execption thrown: %s ", e.what());
	}

	return 0;
}