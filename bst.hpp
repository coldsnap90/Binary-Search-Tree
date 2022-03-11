#include<iostream>
#include<vector>
#ifndef BST_HPP_
#define BST_HPP_
using namespace std;

namespace BST {
  
  struct Node {
    int key; // key value of the node
    struct Node *parent; // pointer to parent node
    struct Node *left; // pointer to left subtree
    struct Node *right; // pointer to right subtree
  };
  typedef struct Node* NodePtr;
  

class BinarySearchTree
{
  //friend func to output 
 friend std::ostream& operator<<(std::ostream&,const BinarySearchTree& tree);
 public:
 //constructor
 BinarySearchTree();
 //copy constructor, 1/3 big 3
 BinarySearchTree(const BinarySearchTree& object);
 //assignment operator, 2/3 big 3
 BinarySearchTree& operator=(const BinarySearchTree& object);
 //destructor , 3/3 Big 3
 ~BinarySearchTree();
 //get func
 NodePtr getRoot() const;
 //searches for key
 NodePtr searchNode(int key);
 //if key DNE finds the closest higher value
 NodePtr searchSuccessor(int key);
 //insertion and deletion of node == key
 bool insertNode(int key);
 bool deleteNode(int key);
 
 private:
 //not required outsie of class, good practice
 //to see private
 NodePtr treeCopy(NodePtr node) const;
 void treeDelete(NodePtr clear);
 //initialze struct
 NodePtr root;

};
#endif
}