#include "parser.h"
#include "messageparser.h"
#include <vector>;
#include <iostream>
#include <sstream>
#include <iomanip>
//#include "..\\..\MessageParser\MessageParser\messageparser.h"

int main() {

	try {
		//uncomment these 3 lines and comment line 13 to line 27 to execute the success scenario with sample buffer.

		unsigned char inputMessage[] = { 0x05, 0x08, 0x01, 0xF4, 0x00, 0x64, 0x03, 0xE8, 0x02, 0x44 };
		int length = 10;
		MessageParser parser(inputMessage, length);

		//////////////////////////////////////////

		// Assuming the user will input the values

	  /*  std::vector<unsigned char> inputMessage;
		int length;

		std::cout << "Enter the length of the message: ";
		std::cin >> length;


		for (int i = 0; i < length; ++i) {
			unsigned int byte;
			std::cin >> byte;

			std::stringstream ss;
			ss << std::hex << "0x" << std::uppercase << std::setw(2) << std::setfill('0') << byte; // Ensuring two characters for each byte

			std::string hexString = ss.str();
			std::cout << "Hexadecimal representation: " << hexString << std::endl;

			inputMessage.push_back(static_cast<unsigned char>(byte));

		}

		MessageParser parser(inputMessage.data(), length);
		*/
		///////////////////////////////////////////////////////
		Node* parsedValues = parser.parseMessage();

		if (parsedValues != nullptr) {
			std::cout << "Message Parsing successful. ";
			Node* current = parsedValues;
			while (current != nullptr) {
				std::cout << "linked list values: " << current->value << current->valType << std::endl;
				current = current->next;
			}

			// Free memory for the linked list
			while (parsedValues != nullptr) {
				Node* temp = parsedValues;
				parsedValues = parsedValues->next;
				delete temp;
			}
		}
	}
	catch (...)
	{
		std::cout << "Parsing Failed";
	}

	return 0;
}

