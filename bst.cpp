#include "bst.hpp"

namespace BST
{

//Default constructor
BinarySearchTree::BinarySearchTree()
{
 root = nullptr;
}

//Copy constructor, 1/3 big 3
BinarySearchTree::BinarySearchTree(const BinarySearchTree &object)
{
 root = treeCopy(object.root);
}


//get func to return root
NodePtr BinarySearchTree::getRoot() const
{
 return root;
}

//Overloading assignment operator,2/3 big3
BinarySearchTree &BinarySearchTree::operator=(const BinarySearchTree &object)
{
  treeDelete(root);
  this->root = treeCopy(object.root);
  return *this;
}


//searchNode finds key in bst
NodePtr BinarySearchTree::searchNode(int key){
    NodePtr here = root;
    //if the node is pointing to null, return null
    if(root == nullptr)
    {
     return nullptr;
    }
    //While the specified node is not found and
    //is not pointing to null continue traversing
    while(here != nullptr && here->key != key ){
        //if the specified key value is greater than the current node key value,
        //traverse to the right subtree, else traverse to the left subtree
        if(here->key < key)
        {
            here = here->right;
        }
        else
        {
            here = here->left;
        }
    }
    return here;
}
//searchSuccessor find node with the closest, higher value than key
NodePtr BinarySearchTree::searchSuccessor(int key){
    NodePtr here = root;
    NodePtr successor = nullptr;

    //if the key was not found from search, return null
    if(searchNode(key) == nullptr)
    {
        return successor;
    }
    //if the node is pointing to null, return null
    if(root == nullptr)
    {
        return nullptr;
    }
    //While end of tree is not reached
    while(here != nullptr)
    {
        //if the specified key value is greater than or equal to the
        //current node key value, traverse to the nodes right subtree
        if(here->key <= key)
        {
            here = here->right;
        //else, if a value is larger than the key, it is made the successor,
        //and we continue to traverse to the left
        }
        else
        {
            successor = here;
            here= here->left;
        }
    }
    return successor;
}

//insertNode inserts a node of value key
bool BinarySearchTree::insertNode(int key)
{
    //if the node already exists in the tree,
    //return a warning message
    if(searchNode(key) != nullptr)
    {
        std::cout << "Node already exists in bst\n";
        return false;
    }
    NodePtr insert;
    NodePtr temp;
    NodePtr prev = nullptr;
    temp = root;
    insert = new Node;
    insert->key = key;
    //if the root points to null, insert the new node at root
    if(root == nullptr)
    {
        root = insert;
    }else
    {
        while(temp != nullptr)
        {
            //Traverses the tree until a null leaf is found,
            //traverse based on key sizes to keep the bst sorted
            if(temp->key > key)
            {
                prev = temp;
                temp = temp->left;
            }
            else
            {
                prev = temp;
                temp = temp->right;
            }
        }
        //Based on parent key value, will insert new node to the left or right of it
        if(prev->key > key){
            prev->left = insert;
        }else{
            prev->right = insert;
        }
        //Sets the parent pointer of the new node 
        insert->parent = prev;
    }
    return true;
}
//deleteNode deletes node of value key
bool BinarySearchTree::deleteNode(int key){
    NodePtr removeNode;
    NodePtr successor;
    removeNode = searchNode(key);
    
    //if the specified key does not exist,
    //return an error message
    if(removeNode == nullptr)
    {
        std::cout << "Node does not exist in bst\n";
        return false;
    }

    //Copying the keys successor value
    successor = searchSuccessor(key);
    
    //if the specified node has two child nodes, assign the successors
    //key value to the specified node
    if(removeNode->left != nullptr && removeNode->right != nullptr)
    {
        removeNode->key = successor->key;
        //if the successor node is to the left of its parent node,
        //assign the parents left pointer to null
        if(successor->parent->key > successor->key)
        {
            successor->parent->left = nullptr;
        //else assign the parents right pointer to null
        }
        else
        {
            successor->parent->right = nullptr;
        }
        //delete the successor node
        delete successor;
    }
    //if the specified node has only one child or is a leaf nodes
    else
    {
        //if the specified node has one child on the right
        if(removeNode->right != nullptr)
        {
            //Based on the key size, the child node to the node that is being removed,
            //will be assigned to the parent of remove node's left or right pointer
            if(removeNode->parent->key < key)
            {
                removeNode->parent->right = removeNode->right;
                removeNode->right->parent = removeNode->parent;
            }
            else
            {
                removeNode->parent->left = removeNode->right;
                removeNode->right->parent = removeNode->parent;
            }
        }
        //Same as other single child node but for the left child
        else if(removeNode->left != nullptr)
        {
            if(removeNode->parent->key < key)
            {
                removeNode->parent->right = removeNode->left;
                removeNode->left->parent = removeNode->parent;
            }
            else
            {
                removeNode->parent->left = removeNode->left;
                removeNode->left->parent = removeNode->parent;

            }
        }
        //else, if the specified node is a leaf node
        else
        {
            //if the leaf node is on the right, assign the 
            //parent nodes right pointer to null
            if(removeNode->parent->key < key)
            { 
                removeNode->parent->right = nullptr;
            //else assign its left pointer to null
            }else
            {
                removeNode->parent->left = nullptr;
            }
        }
        delete removeNode;
    }
    return true;
}