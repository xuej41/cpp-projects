# Lab 2 - Linked List

This lab involved writing custom Linked List functions for an existing snake game that used an Array List, and measuring the time complexities of head insertion and tail deletion.

The report for this lab can be viewed at `Lab2_Report.pdf`.

Explanation of the functions:
Constructor and Destructor:
- Implement both to manage resources properly. The constructor should initialize the list with dummy head and tail nodes.

Size Management Functions:
- `getSize()`: Returns the number of elements in the list.
- `isEmpty()`: Checks if the list is empty.

Element Insertion Functions:
- `insertHead(const objPos &thisPos)`: Inserts an element at the beginning of the list, just after the dummy head.
- `insertTail(const objPos &thisPos)`: Adds an element at the end, just before the dummy tail.
- `insert(const objPos &thisPos, int index)`: Inserts an element at a specified index, with checks to delegate to `insertHead` or `insertTail` as appropriate.

Element Retrieval Functions:
- `getHead() const`: Retrieves the first real element after the dummy head.
- `getTail() const`: Gets the last real element before the dummy tail.
- `get(int index) const`: Fetches an element at a specified index, with boundary checks to return head or tail elements as needed.

Element Modification Function:
- `set(const objPos &thisPos, int index)`: Updates the element at the specified index with new data.

Element Removal Functions:
- `removeHead()`: Removes and returns the first real element.
- `removeTail()`: Deletes and returns the last real element.
- `remove(int index)`: Removes and returns an element at a specific index, with boundary checks to delegate to `removeHead` or `removeTail` as appropriate.

List Traversal and Debugging:
- **Persistent Read Head (`persistHead`)**: Manage a pointer for efficient list traversal, with two design choices for its behavior in advancing through the list.
- `printList() const`: Debugging utility to visually display the structure and content of the list, highlighting the connections between nodes.


Additionaly, you can type `make` under `/Lab1-Model (Improved)/src` and run `Project.exe` that appears under `/Lab1-Model (Improved)/bin` to run the game yourself and view the times for head insertion and deletion. To modify the test parameters yourself, go to `Player.cpp` and simply modify TEST_LENGTH under line 9, change the Array/Linked List being called under line 15, as well as comment and uncomment  `gmRef->StartMeasurement/endMeasurementAndRecord` under lines 111, 113, 116, and 118.