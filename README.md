# PROJECT 2: UNDO-REDO SYSTEM

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
