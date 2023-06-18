#include <iostream>
#include "Factory/CommandFactory.h"


int main() {
	
	while (true) {
		try {
			CommandFactory::getCommand()->execute();
		}
		catch (std::invalid_argument& ex) {
			std::cout << ex.what()<<std::endl;
		}
		catch(std::out_of_range& ex) {
			std::cout << ex.what() << std::endl;
		}
		catch (exit_exc& ex) {
			std::cout << ex.what();
			break;
		}
	}

}