
#pragma once

#ifdef MESSAGEPARSER_EXPORTS
#define MESSAGEPARSER_API __declspec(dllexport)
#else
#define MESSAGEPARSER_API __declspec(dllimport)
#endif


#include <cstdint>
#include "node.h"
#include "exception.h"

class  MessageParser {
private:
    const unsigned char* buffer;
    int length;
    // Check the message header
    void validateHeader();

    // Extract values considering big-endian
    uint16_t extractBigEndianValue(int index);

    // Extract values considering little-endian
    uint16_t extractLittleEndianValue(int index);

    // Calculate checksum
    uint16_t calculateChecksum();

public:
    MESSAGEPARSER_API MessageParser(const unsigned char* inputBuffer, int len);
    // Function to parse the input message and return values
    MESSAGEPARSER_API Node* parseMessage();
};