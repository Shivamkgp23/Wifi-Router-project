Algorithms Term Project
Title: Wi-Fi Router Placement
Group Members:
Gaurav Jha : 19CH10074
Ayush Airan: 19CH10072



In order to compile and run our code :

Step 1 - Download the algopro.cpp file in a folder of your choice.

Step 2 - Open this folder in terminal and type  "g++ algopro.cpp" to compile our code in command line.

Step 3 - After the code gets compiled correctly, type "./a.out" in the command line to run the file

******Sample Input and Output************

SAMPLE INPUT 1:

Enter matrix dimensions : 5 5
Enter matrix : 
- * - * - 
- - * * -
- - * - *
* - - * -
- * - - *
Enter Budget : 20
Enter Cost : 9
Enter signal strength : 2

SAMPLE OUTPUT 1 :

Router No. : 1
Points covered : 6
x : 1, y : 3
global_visited : 
0 0 1 1 1 
0 1 1 1 1 
0 0 1 1 1 
0 0 0 1 0 
0 0 0 0 0 
---------------------------
Router No. : 2
Points covered : 3
x : 2, y : 1
global_visited : 
0 1 1 1 1 
1 1 1 1 1 
1 1 1 1 1 
1 1 1 1 0 
0 1 0 0 0 
---------------------------


SAMPLE INPUT 2:

Enter matrix dimensions : 6 8
Enter matrix : 
- - * * * - - #
# * * * - - # #
* * * * * - - -
- - # * * - * * 
* * * * * * * * 
* - * - * - # -
Enter Budget : 1000
Enter Cost : 200
Enter signal strength : 2


SAMPLE OUTPUT 2 :

Router No. : 1
Points covered : 10
x : 1, y : 3
global_visited : 
0 0 1 1 1 0 0 0 
0 1 1 1 1 1 0 0 
0 0 1 1 1 0 0 0 
0 0 0 1 0 0 0 0 
0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 
---------------------------
Router No. : 2
Points covered : 8
x : 4, y : 3
global_visited : 
0 0 1 1 1 0 0 0 
0 1 1 1 1 1 0 0 
0 0 1 1 1 0 0 0 
0 0 0 1 1 0 0 0 
0 1 1 1 1 1 0 0 
0 0 1 1 1 0 0 0 
---------------------------
Router No. : 3
Points covered : 4
x : 3, y : 0
global_visited : 
0 0 1 1 1 0 0 0 
0 1 1 1 1 1 0 0 
1 1 1 1 1 0 0 0 
1 1 0 1 1 0 0 0 
1 1 1 1 1 1 0 0 
1 0 1 1 1 0 0 0 
---------------------------
Router No. : 4
Points covered : 4
x : 3, y : 6
global_visited : 
0 0 1 1 1 0 0 0 
0 1 1 1 1 1 0 0 
1 1 1 1 1 1 1 1 
1 1 0 1 1 1 1 1 
1 1 1 1 1 1 1 1 
1 0 1 1 1 0 0 0 
---------------------------
Router No. : 5
No need of this router as all coverage points already covered
