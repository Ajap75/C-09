#!/bin/bash

./RPN  # Error
./RPN "3 4 +" # should print 7
./RPN "10 2 +" # should print Error
./RPN "6 3 /" #should print 2
./RPN "2 3 *" #should print 6
./RPN "5 1 2 + 4 * + 3 -" #should print 14
./RPN "7 2 3 * -" #should print 1
./RPN "3 4 + 2 * 7 /" #should print 2
./RPN "4 0 /" #should print Error (/ 0)
./RPN "3 2 /" #should return 1.5
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +" #42
./RPN "9 8 * 4 * 4 / 2 + 9 - 8 - 8 - 1 - 6 -" # should return 42
./RPN "1 2 * 2 / 2 + 5 * 6 - 1 3 * - 4 5 * * 8 /" #should return 15

# Three steps to make a script : 
# 1) create a .sh file for shell file
# 2) write a the top of it : #!/bin/bash to tell the system to run the script with bash
# 3) Right your test the same way as if you were in a shell. 
# 4) Make the file eecutable : chmod +x 