#include "enum.h"
#include <unordered_map> 
#include <iostream>

template <class T>
class BinarySearchTree: public BinaryTree<T> {
public:
   Error_code insert(const T&);
   Error_code remove(const T&);

protected:
   // Auxiliary functions
   Error_code search_and_insert(BinaryNode<T>*& sub_root, std::unordered_map<T, T>& treeNumberChecker, const T& new_data);
   Error_code search_and_delete(BinaryNode<T>*& sub_root, std::unordered_map<T, T>& treeNumberChecker, const T& target);

   void inOrderMinimumSuccesor(BinaryNode<T>*& sub_root);
   
};


template <class T>
Error_code BinarySearchTree<T>::insert(const T& new_data)
{
   return search_and_insert(this->root, this->treeNumberChecker ,new_data);
}


template <class T>
Error_code BinarySearchTree<T>::search_and_insert(
           BinaryNode<T>*& sub_root, std::unordered_map<T, T>& treeNumberChecker ,const T& new_data)
{
   if(treeNumberChecker.find(new_data) != treeNumberChecker.end())
   {
      std::cout << "That Data Member is already in the tree, Please try a different number \n";
   }
   else
   {
      if(sub_root == nullptr)
      {
         sub_root = new BinaryNode(new_data);
         treeNumberChecker[new_data] = new_data;
      }

      else if(new_data < sub_root->data)
      {
         search_and_insert(sub_root->left, treeNumberChecker,new_data);
      }
      else if(new_data > sub_root->data)
      {
         search_and_insert(sub_root->right, treeNumberChecker,new_data);
      }
   }

}


template <class T>
Error_code BinarySearchTree<T>::remove(const T& target)
/*
Post: If a T with a key matching that of target belongs to the
      BinarySearchTree, a code of success is returned, and the corresponding node
      is removed from the tree.  Otherwise, a code of not_present is returned.
Uses: Function search_and_destroy
*/
{
   return search_and_delete(this->root, this->treeNumberChecker, target);
}


template <class T>
Error_code BinarySearchTree<T>::search_and_delete(
           BinaryNode<T>*& sub_root, std::unordered_map<T, T>& treeNumberChecker ,const T& target)
/*
Pre:  sub_root is either NULL or points to a subtree of the BinarySearchTree.
Post: If the key of target is not in the subtree, a code of not_present
      is returned.  Otherwise, a code of success is returned and the subtree
      node containing target has been removed in such a way that
      the properties of a binary search tree have been preserved.
Uses: Functions search_and_delete recursively
*/
{
   if(treeNumberChecker.find(target) != treeNumberChecker.end())
   {
      //If deletetion is root
      //Inorder Succesor
      if(sub_root->right != nullptr)
      {
         inOrderMinimumSuccesor(sub_root->right);
      }

   }
   else{ std::cout << "Target is not in Tree, try a different target. \n"; }
   
}

template <class T>
void BinarySearchTree<T>::inOrderMinimumSuccesor(BinaryNode<T>*& sub_root)
{
   if(sub_root->left == nullptr)
   {
      this->root->data = sub_root->data;
      sub_root = nullptr;
   }
   else { inOrderMinimumSuccesor(sub_root->left); }
}



