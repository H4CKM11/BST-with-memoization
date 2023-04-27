#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <iostream>
#include <unordered_map>
#include "BinaryNode.h"

template <class T>
class BinaryTree {
public:
   BinaryTree();
   bool empty() const;
   void preorder(void (*visit)(T &));
   void inorder(void (*visit)(T &));
   void postorder(void (*visit)(T &));

   int size() const;
   void clear();
   int height() const;

   void print() const; // A method to print out the tree using preorder

   //Add the prototypes of the Big-Three below and add their definitions later

protected:
   // Auxiliary functions
   void recursive_preorder(BinaryNode<T>* sub_root, void (*visit)(T&));
   void recursive_inorder(BinaryNode<T>* sub_root, void (*visit)(T&));
   void recursive_postorder(BinaryNode<T>* sub_root, void (*visit)(T&));
   int recursive_size(BinaryNode<T>* sub_root) const;
   void recursive_clear(BinaryNode<T>* sub_root);
   int recursive_height(BinaryNode<T>* sub_root) const;
   BinaryNode<T>* recursive_copy(BinaryNode<T>* sub_root);

   void recursive_preorder_print_node(BinaryNode<T>* sub_root) const;

   // Data member
   BinaryNode<T>* root;
   std::unordered_map<T, T> treeNumberChecker;
};

template <class T>
BinaryTree<T>::BinaryTree()
/*
Post: An empty binary tree has been created.
*/
{
   root = nullptr;
}


template <class T>
bool BinaryTree<T>::empty() const
/*
Post: A result of true is returned if the binary tree is empty.
      Otherwise, false is returned.
*/
{
}

template <class T>
void BinaryTree<T>::preorder(void (*visit)(T&))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
}

template <class T>
void BinaryTree<T>::inorder(void (*visit)(T&))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
}

template <class T>
void BinaryTree<T>::postorder(void (*visit)(T &))
/*
Post: The tree has been traversed in inorder sequence.
Uses: The function recursive_inorder
*/
{
   
}

template <class T>
int BinaryTree<T>::size() const
/* 
Post: The number of entries in the binary tree is returned.
Uses: The function recursive_size
*/
{
}


template <class T>
void BinaryTree<T>::clear()
/* 
Post: Dispose of all the nodes of the binary tree.
Uses: The function recursive_clear.
*/
{
}

template <class T>
int BinaryTree<T>::height() const
/* 
Post: The height of the binary tree is returned.
Uses: The function recursive_height
*/
{
}

template <class Entry>
void BinaryTree<Entry>::print() const{
/* 
Post: The tree has been traversed in preorder.  Each node and its two children is printed 
Uses: The function recursive_preorder_print_node
*/
   std::cout << std::endl;
   std::cout << "++++++++++++++++++++++" << std::endl;
   if(root == NULL)
      std::cout << "EMPTY TREE" << std::endl;
   else{
      if(root->left == NULL && root->right == NULL)
         std::cout << root->data << ":  -  -" << std::endl;

      recursive_preorder_print_node(root);
   }
   std::cout << "++++++++++++++++++++++" << std::endl;
   std::cout << std::endl;
}

template <class Entry>
void BinaryTree<Entry>::recursive_preorder_print_node(BinaryNode<Entry> *sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the Binary_tree.
Post: The subtree has been traversed in preorder sequence.
Uses: The function recursive_preorder_print_node recursively
*/
{
   if (sub_root != NULL) {
      if(sub_root->left != NULL || sub_root->right != NULL){
         std::cout << sub_root->data << ":  ";
         if(sub_root->left != NULL)
            std::cout << sub_root->left->data << "  ";
         else
            std::cout << "-  "; // "-" represents no child
         if(sub_root->right != NULL)
            std::cout << sub_root->right->data << " ";
         else
            std::cout << "-  "; // "-" represents no child
         //cout << "; ";
         std::cout << std::endl;
      }
      recursive_preorder_print_node(sub_root->left);
      recursive_preorder_print_node(sub_root->right);
   }
}


template <class T>
void BinaryTree<T>::recursive_inorder(BinaryNode<T> *sub_root,
                                           void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in inorder sequence.
Uses: The function recursive_inorder recursively
*/
{
   
}

template <class T>
void BinaryTree<T>::recursive_postorder(BinaryNode<T> *sub_root,
                                             void (*visit)(T &))
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The subtree has been traversed in postorder sequence.
Uses: The function recursive_postorder recursively
*/
{
   
}

template <class T>
int BinaryTree<T>::recursive_size(BinaryNode<T> *sub_root) const
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: The number of entries in the subtree is returned.
Uses: The function recursive_size recursively
*/
{
   
}

template <class T>
void BinaryTree<T>::recursive_clear(BinaryNode<T> *sub_root)
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: All the nodes in the subtree are disposed of in postorder.
Uses: The function recursive_clear recursively
*/
{
   
}

template <class T>
int BinaryTree<T>::recursive_height(BinaryNode<T> *sub_root) const 
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: the height of the subtree is returned.
Uses: The function recursive_height recursively
*/
{
   
}   

template <class T>
BinaryNode<T>* BinaryTree<T>::recursive_copy(BinaryNode<T>* sub_root) 
/*
Pre:  sub_root is either NULL or points to a subtree of the BinaryTree.
Post: returns a pointer to the root of a new binary tree that has exactly the same structure and content as those of the subtree.
Uses: The function recursive_copy recursively
*/
{
   
}



#endif