#include <iostream>
#include <fstream>
#include <string>
#include <exception>
#include <vector>

#include "Pipe.h"


IPipe* loadPipe(std::string filePath)
{
	IPipe* pipe;
	int size;
	std::string sizeValue;

	std::ifstream file;
	file.open(filePath);
	if (file.is_open()) {

	
	std::getline(file, sizeValue);
	size = stoi(sizeValue);

	pipe = new Pipe(size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			char c = file.get();
			if (c == '\n') {
				break;
			}
				
			pipe->insertElement(i, j, new PipeElement(c));
		}
	}
	file.close();
	return pipe;
	}
	else {
		return nullptr;
	}
	
}
int main()
{
	IPipe* pipe1 = loadPipe("pipe1.txt");
	if(pipe1 != nullptr){
	std::cout << pipe1->IsPipeOK() << std::endl;
	}
	else {
		std::cout << "Invalid file path" << std::endl;
	}

	IPipe* pipe2 = loadPipe("pipe2.txt");
	if (pipe2 != nullptr) {
		std::cout << pipe2->IsPipeOK() << std::endl;
	}
	else {
		std::cout << "Invalid file path" << std::endl;
	}

	IPipe* pipe3 = loadPipe("pipe3.txt");
	if (pipe3 != nullptr) {
		std::cout << pipe3->IsPipeOK() << std::endl;
	}
	else {
		std::cout << "Invalid file path" << std::endl;
	}

	IPipe* pipe4 = loadPipe("pipe4.txt");
	if (pipe4 != nullptr) {
		std::cout << pipe4->IsPipeOK() << std::endl;
	}
	else {
		std::cout << "Invalid file path" << std::endl;
	}

	IPipe* pipe5 = loadPipe("pipe5.txt");
	if (pipe5 != nullptr) {
		std::cout << pipe5->IsPipeOK() << std::endl;
	}
	else {
		std::cout << "Invalid file path" << std::endl;
	}

	IPipe* pipe6 = loadPipe("pipe6.txt");
	if (pipe6 != nullptr) {
		std::cout << pipe6->IsPipeOK() << std::endl;
	}
	else {
		std::cout << "Invalid file path" << std::endl;
	}

	IPipe* pipe7 = loadPipe("pipe7.txt");
	if (pipe7 != nullptr) {
		std::cout << pipe7->IsPipeOK() << std::endl;
	}
	else {
		std::cout << "Invalid file path" << std::endl;
	}

	IPipe* pipe8 = loadPipe("pipe8.txt");
	if (pipe8 != nullptr) {
		std::cout << pipe8->IsPipeOK() << std::endl;
	}
	else {
		std::cout << "Invalid file path" << std::endl;
	}

	std::cin.get();
}