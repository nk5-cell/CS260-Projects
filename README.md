

# PROJECT 3: PCC ACADEMIC STANDING SYSTEM

**Part I: The Table ADT**

The Table ADT is implemented using a **hash table** with chaining (array of linked lists). The hashing keys that is used are program names.

For each student, keep tracked of the following information: 
  - Program name (e.g., “Computer Science”)
  - use dynamically allocated cstring 
  - Student G#
  - Student name
  - use dynamically allocated cstring
  - Academic standing
  - 1-5 have the following meanings respectively: unacceptable, needs improvement, meets expectations, exceeds expectations, outstanding)

The required functions for Table ADT are:
  - Constructor
  - Destructor (deallocate the hash table)
  - Insert a new student by program (add student’s information into the hash table)
  - Retrieve (retrieve all students based on the program)
  - Retrieve will need an array of students and the number of matchings as arguments for the ADT to fill. It returns a success/fail flag for whether or not it found a match.
  - Retrieve’s arguments might be something like:
      - bool retrieve(char * program, Student all_matches[], int & num_found);
      - Retrieve does not correspond with the user (i.e., it should not prompt, echo, input, or output data). The client code that invokes retrieve does the input gathering and output printing.
  - Edit (modify the academic standing for a particular program and student match)
  - Remove (remove all students with a unacceptable standing)
  - Display all
  - Monitor the performance of hashing function by displaying each chain length

**Part II: The Driver or the Test Program**

The test program first load the test data set from external file at the beginning of the program. The test program allow user to add a new student, retrieve all students from a given program, edit a student's standing, remove all students with unacceptable academic standing, and display all (not in order!). It also allow user to monitor the performance of the hash table (the monitor function in the ADT). The menu-based user interface allow user to use/test ALL the functionalities of the program. 

