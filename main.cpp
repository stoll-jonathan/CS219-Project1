/*
	TODO: 
	add comments, make readme, make runnable remotely
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

uint32_t performOperation(std::string, uint32_t, uint32_t);
bool detectOverflow(std::string, uint32_t, uint32_t, uint32_t);
std::string removeSpaces(std::string);
uint32_t convertToInt(std::string);
void printOutput(std::string, uint32_t, bool);

int main() {
	// open the input file
  	std::ifstream inputFile("Programming-Project-1.txt");
  	
  	// ensure the file is successfully opened
  	if (!inputFile.is_open()) {
  		std::cout << "Could not open file";
  		return 1;
	}
	
	// iterate through each instruction
  	std::string instr;
	while (getline(inputFile, instr)) {
		// parse the instruction for the operation and arguments
	    std::string op = removeSpaces(instr.substr(0, 3));
	    uint32_t arg1  = convertToInt(removeSpaces(instr.substr(4, 11)));
	    uint32_t arg2  = convertToInt(removeSpaces(instr.substr(17)));
	    
	    // find the result and determine if an overflow occured
	    uint32_t result = performOperation(op, arg1, arg2);
		bool wasOverflow = detectOverflow(op, arg1, arg2, result);
		
		// print the findings
		printOutput(instr, result, wasOverflow);
	}
  	
  	inputFile.close();
  	
  	return 0;
}

uint32_t performOperation(std::string op, uint32_t a, uint32_t b) {
	if (op == "ADD")
		return (a + b);
}

bool detectOverflow(std::string op, uint32_t a, uint32_t b, uint32_t res) {
	if (op == "ADD") {
		if (a > res || b > res)
			return true;
		else return false;
	}
	
	return false;
}

std::string removeSpaces(std::string str) {
	std::string str2 = "";
	
	for (auto x : str) {
		if (x != ' ')
			str2.push_back(x);
	}
	
	return str2;
}

uint32_t convertToInt(std::string str) {
	uint32_t num;   
	std::stringstream ss;
	
	ss << std::hex << str;
	ss >> num;
	
	return num;
}

void printOutput(std::string instr, uint32_t result, bool wasOverflow) {
	std::cout << instr << ": 0x" << std::uppercase << std::hex << result << std::endl;
	std::cout << "Overflow: " << (wasOverflow ? "yes" : "no") << std::endl;
	std::cout << std::endl;
}
