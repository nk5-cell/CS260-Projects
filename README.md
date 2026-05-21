# CS260-Projects 

# Project 1

This is a program that helps keep track of engineer lists. It has an ADT for Engineer and an ADT for EngineerList

**Part I: The Engineer ADT**
The information about a engineer include: 
- First name (e.g., Jane): use dynamically allocated cstring and it should be just big enough, e.g. for a first name "Jane", only 5 chars should be allocated
- Last name (e.g., Smith): same implementation rules as first name
- Title level (L1-L8): use enum or named constants for this
- Assessment level (1-5 ): 1-5 have the following meanings respectively: unacceptable, needs improvement, meets expectations, exceeds expectations, outstanding)

**Part II: The EngineerList ADT**
The data members for EngineerList has a head pointer to a linear linked list of Engineer objects and the number of engineers in the list. The engineers are organized by last names, then first names if the last names are the same, alphabetically. It does not use a sorting algorithm. It keeps the list sorted all the time which means each add should insert the object to the correct position. 
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

# Project 2

**Part I: The Deque ADT**
The deque represent the command history of this program. 
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

Here is an example of undoing and redoing:

After loading from file, the command history:

copy line 3-6
paste line 3-6 after line 10
remove line 20-30
remove the first 3 words of line 1
join line 20 and 30
replace all occurrences of "num" to "number"
comment out line 4-5
indent line 12-15
unindent line 5-8
uncomment line 9-11
After undo 3 commands, the command history:

     8. indent line 12-15

     9. unindent line 5-8

    10. uncomment line 9-11

copy line 3-6
