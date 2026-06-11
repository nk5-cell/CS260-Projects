# PROJECT 4: PCC ACADEMIC STANDING SYSTEM

This is a program that create a binary search tree (BST) and implement the BST algorithms recursively. The advantage of a binary search tree is the ability to retrieve the data using a logarithmic performance assuming that the tree is relatively balanced and be able to search for a range of information and obtain our data in sorted order. 

**Part I: BST ADT**

The binary search tree has a non-linear implementation (using left and right pointers). Each item in tree will have the following information (at a minimum), which is stored as a struct or a class:
  - Program name (e.g., “Computer Science”)
  - use dynamically allocated cstring
  - Student G#: this serve as the searching key for the BST
  - Student name
  - Academic standing
    - 1-5 have the following meanings respectively: unacceptable, needs improvement, meets expectations, exceeds expectations, outstanding)

The ADT operations performed on this data are: 
  - Constructor – initialize all data members
  - Destructor – deallocate (release) all dynamic memory and reset the data members to their zero equivalent value; this call a recursive function that performs postorder
  - traversal (recursively) to deallocate all data and nodes.
  - Insert a new student based on G#
  - Remove all students in a program
  - Remove a particular student based on G# (only one match)
  - Retrieve the information about a particular student based on G#. 
  - routine through the argument list
  - Display all students (sorted by G#!).
  - Monitor the height of the tree. Evaluate the performance of storing and retrieving items from this tree.

**Part II: The Driver or the Test Program**

The test program needs to first load the test data set from external file at the beginning of the program. The test program test all the functionalities of the tree ADT.
The menu-based user interface allow the user to use/test ALL the functionalities of the program. 

