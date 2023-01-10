#include "BSNode.h"

BSNode::BSNode(std::string data):_data(data),_right(nullptr),_left(nullptr),_count(1)
{
}

BSNode::BSNode(const BSNode& other):_data(other._data),_count(other._count)
{
	BSNode left = *other._left;
	BSNode right = *other._right;
	_left = &left;
	_right = &right;
}

BSNode::~BSNode()
{
	delete _right;
	delete _left;
}

bool BSNode::isLeaf() const
{
	return !(_right && _left);
}
