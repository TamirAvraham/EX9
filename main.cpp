
#include <iostream>
#include "BSTNode.hpp"

template<class T>
GenericBSNode<T>* sortedArrayToBST(T arr[], T start, T end)
{
   
    if (start > end)
        return NULL;

    
    int mid = (start + end) / 2;
    GenericBSNode<T>* root = new GenericBSNode<T>(arr[mid]);

    
    root->getLeft() = sortedArrayToBST(arr, start,mid - 1);

   
    root->getRight() = sortedArrayToBST(arr, mid + 1, end);

    return root;
}
int main() {

	
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    int n = sizeof(arr) / sizeof(arr[0]);

    
    auto bst = sortedArrayToBST(arr, 0, n - 1);
    bst->printNodes();
	return 1;
}