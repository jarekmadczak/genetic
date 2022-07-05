#include "Individual.h"
#include "individual_funcions.h"
#include <iostream>

int main(){
	std::cout << "write word to find: ";
	std::cin >> target;
	std::string chromosom = target;
	Individual alghorithm(chromosom);
	alghorithm.start();

}