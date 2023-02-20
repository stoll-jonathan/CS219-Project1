/*
	Format Results, 
	include overflow support, convert from string to uint32_t in processInstruction function,
	make readme, make runnable remotely
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>

std::string removeSpaces(std::string str) {
	std::string str2 = "";
	
	for (auto x : str) {
		if (x != ' ')
			str2.push_back(x);
	}
	
	return str2;
}

uint32_t performOperation(std::string op, uint32_t a, uint32_t b) {
	if (op == "ADD")
		return (a + b);
}

// split the instruction into its components and call performOperation
uint32_t processInstruction(std::string str) {
	// parse the instruction for the operation and arguments
    std::string operation = str.substr(0, 3);
    std::string arg1      = str.substr(4, 11);
    std::string arg2      = str.substr(17);
	
	//remove leading whitespace
    operation = removeSpaces(operation);
    arg1 = removeSpaces(arg1);
    arg2 = removeSpaces(arg2);
    
    // convert arguments to uint32_t
    uint32_t a = 0x72DF9901;
    uint32_t b = 0x2E0B484A;
    
    return performOperation(operation, a, b);
}

void printResult(std::string instr, uint32_t result) {
	std::cout << instr << " : 0x" << std::hex << result << std::endl;
}
int main() {
  	std::ifstream inputFile("Programming-Project-1.txt");
  	
  	if (!inputFile.is_open()) {
  		std::cout << "Could not open file";
  		return 1;
	}
	
  	std::string line;
	while (getline(inputFile, line)) {
		uint32_t result = processInstruction(line);
		printResult(line, result);
	}
  	
  	inputFile.close();
  	
  	return 0;
}
