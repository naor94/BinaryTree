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
  ariel::Tree emptytree;
  ariel::Tree threetree;
  threetree.insert(5);
  threetree.insert(7);
  threetree.insert(3);

  badkan::TestCase tc("Binary tree");
  tc
  // size check
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
   // contain check
   .CHECK_EQUAL (emptytree.contains(5), true)
 //  remove check
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
 // insert check
  .CHECK_OK(emptytree.insert(7))
  .CHECK_THROWS(emptytree.insert(7))//throw exception wwhile tying existing number
  .CHECK_OK(emptytree.insert(9))
  .CHECK_OK(emptytree.insert(6))
  .CHECK_OK (emptytree.remove(7))
  .CHECK_EQUAL (emptytree.root() ,9)
  .CHECK_EQUAL (emptytree.left(9) ,6)


 // general
   .CHECK_EQUAL(emptytree.contains(7),false)
   .CHECK_EQUAL(emptytree.contains(6),true)
   .CHECK_OK    (emptytree.remove(9))
   .CHECK_EQUAL (emptytree.root() ,6)
   .CHECK_OK    (emptytree.remove(6))
   .CHECK_EQUAL (emptytree.size(), 0)
 // root check
   .CHECK_THROWS(emptytree.root())
   .CHECK_OK(emptytree.insert(2))
   .CHECK_EQUAL(emptytree.root(),2)
   .CHECK_EQUAL (threetree.size(), 3)
   .CHECK_EQUAL (threetree.root(), 5)
 // parent check
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_THROWS(threetree.parent(5))
  .CHECK_EQUAL (threetree.parent(7), 5)
 // left and right check
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_THROWS(threetree.left(3))
  .CHECK_THROWS(threetree.right(3))
  .CHECK_THROWS(threetree.right(7))
  .CHECK_THROWS(threetree.left(7))
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_OK  (threetree.insert(1))
  .CHECK_OK  (threetree.insert(4))
  .CHECK_OK  (threetree.insert(6))
  .CHECK_OK  (threetree.insert(10))
  .CHECK_OK  (threetree.insert(9))
  .CHECK_EQUAL (threetree.left(10), 9)
  .CHECK_EQUAL (threetree.parent(4), 3)
  .CHECK_EQUAL (threetree.right(7),10)
 .CHECK_OK  (threetree.remove(9))
 .CHECK_THROWS(threetree.left(10))
 .CHECK_OK  (threetree.insert(8))
 .CHECK_EQUAL (threetree.left(10),8)
 .CHECK_OK  (threetree.remove(7))
 .CHECK_EQUAL (threetree.right(5),8)
.CHECK_EQUAL (threetree.parent(6),8)
.CHECK_EQUAL (threetree.size(),7)
 .CHECK_OK  (threetree.remove(5))
 .CHECK_EQUAL (threetree.root(),6)


   .CHECK_OK  (threetree.print())


  .print();

  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;









}
;