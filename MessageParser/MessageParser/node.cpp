#include "pch.h"
#include "node.h"

Node::Node(int val, std::string type) : value(val), valType(type), next(nullptr) {}
