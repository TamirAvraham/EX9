#pragma once

template<class T>
class BSNode
{
public:
	BSNode(T data);
	BSNode(const BSNode& other);

	~BSNode();

	void insert(T value);
	BSNode& operator=(const BSNode& other);

	bool isLeaf() const;
	T getData() const;
	int getCount() const;
	BSNode<T>* getLeft() const;
	BSNode<T>* getRight() const;


	bool search(T val) const;

	int getHeight() const;
	int getDepth(const BSNode<T>& root) const;

	void printNodes() const; //for question 1 part C

private:
	T _data;
	BSNode<T>* _left;
	BSNode<T>* _right;

	int _count; //for question 1 part B
	int getCurrNodeDistFromInputNode(const BSNode<T>* node) const; //auxiliary function for getDepth
	int getHeight(const BSNode<T>* root) const;

};
#include "BSNode.h"
#include <iostream>
#define ERROR -1;
template<class T>
BSNode<T>::BSNode<T>(T data) :_data(data), _right(nullptr), _left(nullptr), _count(1)
{
}
template<class T>
BSNode<T>::BSNode<T>(const BSNode<T>& other) :_data(other._data), _count(other._count)
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
template<class T>
BSNode<T>::~BSNode()
{
	delete _right;
	delete _left;
}
template<class T>
void BSNode<T>::insert(T value)
{
	if (value < _data)
	{
		if (_left == nullptr)
		{
			_left = new BSNode(value);
			return;
		}
		_left->insert(value);
	}
	else if (value > _data)
	{
		if (_right == nullptr)
		{
			_right = new BSNode(value);
			return;
		}
		_right->insert(value);
	}
	if (value == _data)
	{
		_count++;
	}
	return;
}
template<class T>
BSNode<T>& BSNode<T>::operator=(const BSNode<T>& other)
{

	*this = BSNode(other);
	return *this;
}
template<class T>
bool BSNode<T>::isLeaf() const
{
	return _right == nullptr && _left == nullptr;
}
template<class T>
std::string BSNode<T>::getData() const
{
	return _data;
}
template<class T>
int BSNode<T>::getCount() const
{
	return _count;
}
template<class T>
BSNode<T>* BSNode<T>::getLeft() const
{
	return _left;
}
template<class T>
BSNode<T>* BSNode<T>::getRight() const
{
	return _right;
}
template<class T>
bool BSNode<T>::search(T val) const
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
template<class T>
int BSNode<T>::getHeight() const
{
	return getHeight(this);
}
template<class T>
int BSNode<T>::getDepth(const BSNode<T>& root) const
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
template<class T>
void BSNode<T>::printNodes() const
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
template<class T>
int BSNode<T>::getCurrNodeDistFromInputNode(const BSNode<T>* node) const
{
	if (node == nullptr)
	{
		return ERROR;
	}
	else if (node->_data == _data) {
		return 0;
	}
	BSNode* goTo = _data < node->_data ? node->_left : node->_right;

	return getCurrNodeDistFromInputNode(goTo) + 1;
}
template<class T>
int BSNode<T>::getHeight(const BSNode* root) const
{
	if (root == nullptr)
	{
		return 0;
	}
	int rightHeight = getHeight(root->_right);
	int leftHeight = getHeight(root->_left);
	return (leftHeight < rightHeight ? rightHeight : leftHeight) + 1;
}
