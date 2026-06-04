# CS260-Projects 

# PROJECT 1: ENGINEER MANAGEMENT SYSTEM

This is a program that helps keep track of engineer lists. It has an ADT for Engineer and an ADT for EngineerList

**Part I: The Engineer ADT**

The information about a engineer include: 
- First name (e.g., Jane): use dynamically allocated cstring and it should be just big enough, e.g. for a first name "Jane", only 5 chars should be allocated
- Last name (e.g., Smith): same implementation rules as first name
- Title level (L1-L8): use enum or named constants for this
- Assessment level (1-5 ): 1-5 have the following meanings respectively: unacceptable, needs improvement, meets expectations, exceeds expectations, outstanding)

**Part II: The EngineerList ADT**

The data members for EngineerList has a head pointer to a **linear linked list** of Engineer objects and the number of engineers in the list. The engineers are organized by last names, then first names if the last names are the same, alphabetically. It does not use a sorting algorithm. It keeps the list sorted all the time which means each add should insert the object to the correct position. 
This ADT have public member functions to perform the following:
- Constructor: Construct an object and initialize the data members
- Destructor: Release all dynamic memory 
- Add a new engineer by inserting it according to the order of the list which is sorted by names
- Promote an engineer by increasing the title level by 1 with the highest possible level as 8
- Edit the assessment level of an engineer identified by index (first show all engineers with indices)
- Display all engineers in the list sorted by name (in order of last name, then first name meaning if the last names are the same, order them by first names)
- Display all engineers of a certain level
- Remove all engineers with performance rating 1

**Part III: The driver or the test program** 

The test program first load the test data set from external file at the beginning of the program.
The menu-based user interface allow user to use/test ALL the functionalities of the program. 
Always prompt user when input data is needed.

# PROJECT 2: UNDO-REDO SYSTEM

**Part I: The Deque ADT**

The **deque** represent the command history of this program. 
The command includes:
- sequence number of the command, e.g. 1, 2, .., and they do not change throughout the program
- command description, e.g. copy line 3-6
The deque implemented using a doubly linked list of commands, where the front pointer points to the command that was used for redo and the rear pointer points to the most recent command. 
Implemented:
- addToEnd
- removeFromEnd
- addToFront
- removeFromFront
- peekEnd
- peekFront
- display

**Part II: The Driver or the Test Program**

The test program first load the test data set from external file at the beginning of the program. The menu-based user interface allow user to do the following:
- Show the entire command history
- Undo a certain number of commands
- Redo a certain number of commands (the opposite of undo)

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

