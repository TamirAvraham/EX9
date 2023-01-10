#include "BSNode.h"
#include <iostream>
#define ERROR -1;
BSNode::BSNode(std::string data):_data(data),_right(nullptr),_left(nullptr),_count(1)
{
}

BSNode::BSNode(const BSNode& other):_data(other._data),_count(other._count)
{
	if (&other != nullptr)
	{
		_data = other.getData();
		_count = other.getCount();
		if (other.getLeft() != nullptr)
			_left = new BSNode(*other.getLeft());
		else
			_left = nullptr;
		if (other.getRight() != nullptr)
			_right = new BSNode(*other.getRight());
		else
			_right = nullptr;
	}
}

BSNode::~BSNode()
{
	delete _right;
	delete _left;
}

void BSNode::insert(std::string value)
{
	if (value < _data) 
	{
		if (_left==nullptr)
		{
			_left = new BSNode(value);
			return;
		}
		_left->insert(value);
	}
	else if (value > _data) 
	{
		if (_right==nullptr)
		{
			_right = new BSNode(value);
			return;
		}
		_right->insert(value);
	}
	if (value==_data)
	{
		_count++;
	}
	return;
}

BSNode& BSNode::operator=(const BSNode& other)
{
	
	*this = BSNode(other);
	return *this;
}

bool BSNode::isLeaf() const
{
	return _right == nullptr && _left == nullptr;
}

std::string BSNode::getData() const
{
	return _data;
}

int BSNode::getCount() const
{
	return _count;
}

BSNode* BSNode::getLeft() const
{
	return _left;
}

BSNode* BSNode::getRight() const
{
	return _right;
}

bool BSNode::search(std::string val) const
{
	if (val == _data)
		return true;
	if (val < _data)
	{
		if (_left != NULL)
			return _left->search(val);
		return false;
	}
	if (_right != NULL)
		return _right->search(val);
	return false;
}

int BSNode::getHeight() const
{
	return getHeight(this);
}

int BSNode::getDepth(const BSNode& root) const
{
	try
	{
		return getCurrNodeDistFromInputNode(&root);
	}
	catch (int)
	{
		return -1;
	}
	
}

void BSNode::printNodes() const
{
	if (_left)
	{
		_left->printNodes();
	}
	std::cout << _data << " " << _count << "\n";
	if (_right)
	{
		_right->printNodes();
	}
}

int BSNode::getCurrNodeDistFromInputNode(const BSNode* node) const
{
	if (node==nullptr)
	{
		return ERROR;
	}
	else if (node->_data == _data) {
		return 0;
	}
	BSNode* goTo = _data < node->_data ? node->_left : node->_right;
	
	return getCurrNodeDistFromInputNode(goTo) + 1;
}

int BSNode::getHeight(const BSNode* root) const
{
	if (root==nullptr)
	{
		return 0;
	}
	int rightHeight = getHeight(root->_right);
	int leftHeight = getHeight(root->_left);
	return (leftHeight < rightHeight ? rightHeight : leftHeight) + 1;
}
