#pragma once

template<class T>
class GenericBSNode
{
public:
	GenericBSNode(T data);
	GenericBSNode(const GenericBSNode<T>& other);

	~GenericBSNode();

	void insert(T value);
	GenericBSNode& operator=(const GenericBSNode& other);

	bool isLeaf() const;
	T getData() const;
	int getCount() const;
	GenericBSNode<T>* getLeft() const;
	GenericBSNode<T>* getRight() const;


	bool search(T val) const;

	int getHeight() const;
	int getDepth(const GenericBSNode<T>& root) const;

	void printNodes() const; //for question 1 part C

private:
	T _data;
	GenericBSNode<T>* _left;
	GenericBSNode<T>* _right;

	int _count; //for question 1 part B
	int getCurrNodeDistFromInputNode(const GenericBSNode<T>* node) const; //auxiliary function for getDepth
	int getHeight(const GenericBSNode<T>* root) const;

};
#include "BSNode.h"
#include <iostream>
#define ERROR -1;
template<class T>
GenericBSNode<T>::GenericBSNode(T data) :_data(data), _right(nullptr), _left(nullptr), _count(1)
{
}
template<class T>
GenericBSNode<T>::GenericBSNode(const GenericBSNode<T>& other) :_data(other._data), _count(other._count)
{
	if (&other != nullptr)
	{
		_data = other.getData();
		_count = other.getCount();
		if (other.getLeft() != nullptr)
			_left = new GenericBSNode(*other.getLeft());
		else
			_left = nullptr;
		if (other.getRight() != nullptr)
			_right = new GenericBSNode(*other.getRight());
		else
			_right = nullptr;
	}
}
template<class T>
GenericBSNode<T>::~GenericBSNode()
{
	delete _right;
	delete _left;
}
template<class T>
void GenericBSNode<T>::insert(T value)
{
	if (value < _data)
	{
		if (_left == nullptr)
		{
			_left = new GenericBSNode(value);
			return;
		}
		_left->insert(value);
	}
	else if (value > _data)
	{
		if (_right == nullptr)
		{
			_right = new GenericBSNode(value);
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
GenericBSNode<T>& GenericBSNode<T>::operator=(const GenericBSNode<T>& other)
{

	*this = GenericBSNode(other);
	return *this;
}
template<class T>
bool GenericBSNode<T>::isLeaf() const
{
	return _right == nullptr && _left == nullptr;
}
template<class T>
T GenericBSNode<T>::getData() const
{
	return _data;
}
template<class T>
int GenericBSNode<T>::getCount() const
{
	return _count;
}
template<class T>
GenericBSNode<T>* GenericBSNode<T>::getLeft() const
{
	return _left;
}
template<class T>
GenericBSNode<T>* GenericBSNode<T>::getRight() const
{
	return _right;
}
template<class T>
bool GenericBSNode<T>::search(T val) const
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
int GenericBSNode<T>::getHeight() const
{
	return getHeight(this);
}
template<class T>
int GenericBSNode<T>::getDepth(const GenericBSNode<T>& root) const
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
void GenericBSNode<T>::printNodes() const
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
int GenericBSNode<T>::getCurrNodeDistFromInputNode(const GenericBSNode<T>* node) const
{
	if (node == nullptr)
	{
		return ERROR;
	}
	else if (node->_data == _data) {
		return 0;
	}
	GenericBSNode* goTo = _data < node->_data ? node->_left : node->_right;

	return getCurrNodeDistFromInputNode(goTo) + 1;
}
template<class T>
int GenericBSNode<T>::getHeight(const GenericBSNode* root) const
{
	if (root == nullptr)
	{
		return 0;
	}
	int rightHeight = getHeight(root->_right);
	int leftHeight = getHeight(root->_left);
	return (leftHeight < rightHeight ? rightHeight : leftHeight) + 1;
}
