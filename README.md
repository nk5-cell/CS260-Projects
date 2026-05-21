# CS260-Projects

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
