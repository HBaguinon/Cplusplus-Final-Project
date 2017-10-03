// File: LinkedList.h
// LinkedList class with node and listIterator class
// Recognizes Multiple Copies of Items During Insertion
// 	Returns pointer to data if data found in list during insertion
//		does not insert item more than once
// Find returns pointer to data if found.

#ifndef _LinkedList_
#define _LinkedList_
#include <assert.h>
#include <iostream>

using namespace std;

// Need to prototype template classes if they are to be friends
template <typename eltType> class LinkedList;
template <typename eltType> class listItr;

template <typename eltType> class node
{private:
  node(eltType info, node* link = NULL ) :  data(info), next(link) {};
  eltType data;
  node*   next;
  friend class LinkedList<eltType>;
  friend class listItr<eltType>;
};

template <typename eltType> class LinkedList
{
 public:
  // Construct empty LinkedList
  LinkedList();
  // Construct deep copy of another LinkedList
  LinkedList(LinkedList& cl);

  // destroy LinkedList
  ~LinkedList();

  // Assign another LinkedList to this LinkedList; deep copy
  LinkedList& operator=(const LinkedList &cl);

  // Is the LinkedList empty?
  bool empty();
  
  // Find returns a pointer to the search key's record if found
  eltType* find(const eltType &elt);

  // Ordered insert/remove;
  eltType *orderedInsert(const eltType &elt);
  void remove(const eltType &elt);

  // Quick example of recursion
  int  countNodesInList() const;

 private:
  // linked list pointer
  node<eltType>*  head;

  // Get a copy of a (deep) node
  node<eltType>*  copy(node<eltType> *);

  // Free nodes of a linked list
  void    destroy(node<eltType> *);

  // Need this to count nodes in LinkedList
  int     countNodes(node<eltType> *) const;
  /*
        // Linked list to ostream
        friend ostream& operator<< <>(ostream&, LinkedList<eltType>);
  */

  // Needed to use a list iterator
  friend class listItr<eltType>;
};

template <typename eltType>
ostream& operator<<(ostream &os,const LinkedList<eltType> &l);

// Set up an iterator;
//      an object that provides a pointer to a linked list (in this case)
template <typename eltType> class listItr
{
 public:
  // Construct a List Iterator
  listItr( LinkedList<eltType> &l);

  // Construct a List Iterator off a const reference to a LinkedList
  listItr(const LinkedList<eltType> &l);

  // Set curr to point at the first node of itr
  void start();
  // Is curr null?
  bool more() const;
  // Go to curr->next
  void next();
  // Get the value out of curr's node
  eltType &value();
  const eltType &value() const;
 private:
  const LinkedList<eltType> &itr;
  node<eltType> *curr;
};


#endif
