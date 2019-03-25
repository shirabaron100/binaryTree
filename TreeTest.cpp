/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"

int main() {
    int a=0;
  ariel::Tree emptytree;
  ariel::Tree threetree;  
  ariel::Tree empty; 
  ariel::Tree emptyNoRoot;
ariel::Tree emptyRoot; 
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);
  
  ariel::Tree mytree;  

  badkan::TestCase tc("Binary tree");
  tc
  //trying to remove a node that doesnt exist
.CHECK_THROWS(empty.remove(5))

//trying to insert a node that allready in the tree
.CHECK_THROWS(threetree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())
  .print();
  
//trying to add to the empty tree number in 1-100 and cheack if it is already exist
for (int i=0;i<100;i++)
{
a=(a+97)%100;
tc.CHECK_EQUAL (emptytree.contains(a), false);
tc.CHECK_OK (emptytree.insert(a));
}

//trying to remove a node that doesnt exist
tc.CHECK_THROWS(empty.remove(5));
empty.insert(5);

//trying to insert a node that allready in the tree
tc.CHECK_THROWS(threetree.insert(5));

//trying to remove all the number 
for (int j=0;j<100;j++)
{
tc.CHECK_THROWS(emptytree.remove(j));
}

//trying to get a root from empty tree
tc.CHECK_THROWS(emptyNoRoot.root());

//trying to get the parent of the root
tc.CHECK_THROWS(emptyNoRoot.parent(emptyNoRoot.root()));

//trying to get left and right san and the tree has only one node
tc.CHECK_THROWS(emptyNoRoot.left(emptyRoot.root()));
tc.CHECK_THROWS(emptyNoRoot.right(emptyRoot.root()));

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}