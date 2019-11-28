# HW5_DatabaseBST
In this assignment, you will push your C++ skills to the limit by implementing a simple database system using binary search trees. Though the end product will be a far cry from Oracle or MySQL, your DB will allow the user to insert, delete, and query data. The data itself will be persistent (stored on disk), so that you may process it over several sessions.

The DB itself will contain data that would be commonly found in a university’s computer system. In our case, this information consists of student and faculty records. The information for each will be stored in its own tree (or “table” in DB terminology).

Though I will provide you with a general outline of the program, many of the implementation details will be up to you. In the same spirit, I will give you a point in the right direction as far as some of the C++ techniques go, but it will also be your responsibility to research the techniques in more detail.

Limitations
Rollback and Serialization do not work in their complete capacity. Each have attempts in implementation.

Links used for our sorry attempt at serialization
https://www.tutorialspoint.com/reading-and-writing-binary-file-in-c-cplusplus
https://www.boost.org/doc/libs/1_36_0/libs/serialization/example/demo.cpp
https://stackoverflow.com/questions/234724/is-it-possible-to-serialize-and-deserialize-a-class-in-c
