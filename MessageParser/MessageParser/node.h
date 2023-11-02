#pragma once

#include <string>

class Node {
public:
    int value;
    std::string valType;
    Node* next;
    Node(int val, std::string type);
};