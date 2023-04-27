#include <iostream>
#include <string>
#include "BinaryNode.h"
#include "BinaryTree.h"
#include "BinarySearchTree.h"

using namespace std;

void menu();
void insert_msg();
void delete_msg();

int main()
{
   string input = "";
   bool exit_now = false;
   BinarySearchTree<int> stree;
   while (!exit_now)
   {
      menu();
      getline(cin, input);
      if (input == "i")
      {
         insert_msg();
         getline(cin, input);
         while (input != "q")
         {
            stree.insert(stoi(input));
            stree.print();
            getline(cin, input);
         }
      }
      else if (input == "r")
      {
         delete_msg();
         getline(cin, input);
         while (input != "q")
         {
            stree.remove(stoi(input));
            stree.print();
            getline(cin, input);
         }
      }
      else if (input == "c")
         stree.clear();
      else if (input == "p")
         stree.print();
      else if (input == "h")
         cout << "\nThe height of the binary tree is " << stree.height() << endl;
      else if (input == "s")
         cout << "\nThe size (node count) of the binary tree is " << stree.size() << endl;
      else if (input == "x")
         exit_now = true;
   }
}

void menu()
{
   cout << "\n";
   cout << "***********************\n";
   cout << "Menu:\n";
   cout << "i. Incremental Insert\n";
   cout << "r. Incremental Delete\n";
   cout << "c. Clear tree\n";
   cout << "p. Print tree\n";
   cout << "h. Print tree height\n";
   cout << "s. Print tree size\n";
   cout << "x. Exit\n";
   cout << "***********************\n";
}

void insert_msg()
{
   cout << "\nEnter new integer keys to insert.  Enter \"q<Enter>\" to quit.\n\n";
}

void delete_msg()
{
   cout << "\nEnter integer keys to delete.  Enter \"q<Enter>\" to quit.\n\n";
}
