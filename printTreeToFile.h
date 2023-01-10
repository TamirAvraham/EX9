#pragma once

#include <string>
#include "BSNode.h"
#include <fstream>
void printTreeToFile(const BSNode* bs, std::string output);
void BSTToFile(const BSNode* bs, std::string fname);