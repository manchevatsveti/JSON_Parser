#include <iostream>
#include "Factory/CommandFactory.h"

int main() {
	
	while (true) {
		try {
			CommandFactory::getCommand()->execute();
		}
		catch (...) {
			break;
		}

	}

}