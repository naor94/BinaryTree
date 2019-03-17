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
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)

  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_OK    (threetree.print())

  .print();

  ariel::Tree t;
  t.insert(2);
  t.insert(1);
  t.insert(3);
  badkan::TestCase a("empty");
  a
  .CHECK_EQUAL(t.size(), 3)
  .CHECK_OK    (t.remove(2))
  .CHECK_OK    (t.remove(1))
  .CHECK_OK    (t.remove(3))
  .CHECK_EQUAL (t.size(), 0);

  ariel::Tree t1;
  t1.insert(2);
  t1.insert(1);
  t1.insert(3);
  badkan::TestCase insertDup("insertDup");
  insertDup
  .CHECK_EQUAL(t.size(), 3)
  .CHECK_OK    (t1.insert(2))
  .CHECK_OK    (t.insert(1))
  .CHECK_OK    (t.insert(3))
  .CHECK_EQUAL (t.size(), 3);

  ariel::Tree t2;
  badkan::TestCase bb("removeEmptyTree");
  bb
  .CHECK_EQUAL(t2.size(), 0)
  .CHECK_THROWS(emptytree.remove(5));
  








  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}
