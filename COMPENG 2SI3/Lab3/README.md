Lab3 - Stack and Queue

The lab report for this lab can be found as `Lab3_Report.pdf`. It answers the questions outlined in the lab manual.

Here, I delved deep into stack and queue implementations, learning how to work with this abstract data type. This code was used as an add-on to an existing snake game implementation to improve efficiency and run-time. This code was deeply analyzed to ensure time and space complexity optimization.

- objPosStack Implementation:
  - Use `objPosDLinkedList` for stack functionalities.
  - Implement stack operations: constructor/destructor, `generateObjects` for random objPos creation, `sortByTenScoreBS` for bubble sort, `populateRandomItems` for initial population and sorting, `push`/`pop` operations, `top` for peeking, `size` for stack length, and `printMe` for debugging.

- cmdQueue Implementation:
  - Utilize `DLinkedList<char>` for queue functionalities.
  - Define queue operations: constructor/destructor, `enqueue` to add commands, `dequeue` to remove the oldest command, `getSize` for queue length, `clearQueue` to empty the queue, and `printMe` for outputting queue contents.

Both modules are aimed at enhancing the 2-Player Snake Game by ensuring fair keyboard input processing and implementing a pre-generated food scoring system that scales with game progress.
Type `make` under `/Lab3-Model/src` and run `Project.exe` that appears under `/Lab3-Model/bin`. Use the WASD keys to control player 1 and the IJKL keys for player 2.