
#include <iostream>
#include "BSTNode.hpp"

template<class T>
GenericBSNode<T>* sortedArrayToBST(T arr[], int len)
{
    GenericBSNode<T>* ret = new GenericBSNode<T>(arr[0]);
    for (int i = 1; i < len; i++)
    {
        ret->insert(arr[i]);
    }
    return ret;
}
int main() {

	
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    std::string arrString[] = { "a","c","b","d" };
    int n = sizeof(arr) / sizeof(arr[0]);
    int arrStringLen = sizeof(arrString) / sizeof(arrString[0]);
    
    auto bst = sortedArrayToBST(arr,n);
    bst->printNodes();
    auto bstS = sortedArrayToBST(arrString, arrStringLen);
    bstS->printNodes();
	return 1;
}