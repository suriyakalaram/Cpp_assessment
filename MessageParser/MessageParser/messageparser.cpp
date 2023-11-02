#include "pch.h"
#include "messageparser.h"


MESSAGEPARSER_API  MessageParser::MessageParser(const unsigned char* inputBuffer, int len) : buffer(inputBuffer), length(len) {}


void MessageParser:: validateHeader() {
    if (length < 10 || buffer[0] != 0x05 || buffer[1] != 0x08) {
        throw exception("Invalid message format.");
    }
}

uint16_t MessageParser::extractBigEndianValue(int index) {
    return (buffer[index] << 8) | buffer[index + 1];
}

uint16_t MessageParser:: extractLittleEndianValue(int index) {
    return (buffer[index] | (buffer[index + 1] << 8));
}

uint16_t MessageParser::calculateChecksum() {
    uint16_t checksum = 0;
    for (int i = 2; i <= 7; i++) {
        checksum += buffer[i];
    }
    return checksum;
}

MESSAGEPARSER_API  Node* MessageParser::parseMessage() {
        try {
            validateHeader();

            uint16_t speed = extractBigEndianValue(2);
            uint16_t heading = extractBigEndianValue(4);
            uint16_t altitude = extractBigEndianValue(6);
            uint16_t receivedChecksum = extractBigEndianValue(8);

            uint16_t checksum = calculateChecksum();

            // Verify against the given checksum in the message
            if (checksum != receivedChecksum) {
                throw exception("Checksum mismatch.");
            }

            // Create linked list with given values
            Node* parsedValues = new Node(speed, " km/h");
            parsedValues->next = new Node(heading, " degrees");
            parsedValues->next->next = new Node(altitude, " meters");

            return parsedValues;
        }
        catch (const std::exception& e) {
            std::string errorMessage = "Parsing failed: ";
            errorMessage += e.what();
            throw std::runtime_error(errorMessage);
        }
};