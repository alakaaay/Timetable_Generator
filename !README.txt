|====================================================================================================================|
|                                 |Timetable Generator 2000 by Team NASA|                                            |
|====================================================================================================================|
|                                                                                                                    |
|The given generater generates the random timetable for University, School or etc. students according to data        |
|given as name of courses, student groups, available venues and proffessors. Moreover, it checks whether proffessor, |
|student group or venue are available at the given time or not, and whether the number of students is less than      |
|room size or not. According to given information, it generates the timetable.                                       |
|                                                                                                                    |
|====================================================================================================================|
|                                            |Getting Started|                                                       |
|                                                                                                                    |
|The given instruction will help you to run "Timetable Generetor 2000" by Team NASA                                  |
|                                                                                                                    |
|====================================================================================================================|
|                                             |Prerequisites|                                                        |
|Before running the program you have to open the root folder and then enter the data in .txt files called (in our    |
|case the data is already written and it was taken from registrar, but if you want you can change it):               |  
|1)courses.txt                                                                                                       |
|2)abb_hours.txt                                                                                                     |
|3)faculty.txt                                                                                                       |
|4)groups.txt                                                                                                        |
|5)rooms.txt                                                                                                         |
|                                                                                                                    |
|====================================================================================================================|
|***In file "courses.txt" you have to write a list of courses and the groups that take them. The name of the         |
|courses and groups could contain only Alphabetic characters, numbers and underscores(without spaces!). You must     |
|follow the following format: firstly, you have to write the name of the course and after put hyphen, then put       |
|group names. Every group name must be followed by comma and after the last group you have to put a dot.             |
|Example: Project_Management - CEY31, CEY32, MEY31, EEY31, EEY32, CHEY31, CHEY32, MEY41, CEY41, EEY41.               |
|                                                                                                                    |
|====================================================================================================================|
|***In file "abb_hours.txt" you have to write a list of courses, their abbreviations and the durations of the        |
|lessons. The name of the courses and its abbreviations could contain only Alphabetic characters, numbers and        |
|underscores(without spaces!). The durations of the lessons must be unsigned integer. You must follow the following  |
|format: firstly, you have to write the name of the course(IMPORTANT! It must be same as in "courses.txt", otherwise |
|program will not generate timetable!), and after put hyphen, then put abbreviation of the course. Finally, it       |
|must contain the duration of the lessons, which are divided by space and it must not be more than 4. At the end you |
|have to put the dot.                                                                                                |
|                                                                                                                    |
|Example: Separation_Processes_I - ECHE220 4 2 2 1 .                                                                 |
|====================================================================================================================|
|***In file "faculty.txt" you have to write a list of professors and lessons that they teach. The name of the        |
|professors and courses could contain only Alphabetic characters, numbers and underscores(without spaces!). You must |
|follow the following format: firstly you have to write the name of the professor and after put hyphen, then put     |
|the name of the course(IMPORTANT! It must be same as in "courses.txt", otherwise program will not generate          |
|timetable!). Every course name must be followed by comma and after the last group you have to put the dot.          |
|Example: Lyazzat_Saliyeva - Civil_Engineering_Materials, Engineering_Geology_and_Rock_Mechanics, Capstone_Project_1.|
|                                                                                                                    |
|====================================================================================================================|
|***In file "groups.txt" you have to write a list of student groups and the number of students in it. The name of the|
|groups could contain any character(without spaces!). The number of students must be unsigned integer. You must      |
|follow the following format: firstly, you have to write the name of the group(IMPORTANT! It must be same as in      |
|"courses.txt") and then put the number of the students in the given group.                                          |
|Example: CHEY22 30                                                                                                  |
|                                                                                                                    |
|====================================================================================================================|
|***In file "rooms.txt" you have to write a list of rooms and their capacity. The name of the rooms could contain any|
|character(without spaces!). The number of students must be unsigned integer. You must follow the following format:  |
|firstly you have to write the name of the rooms and then write their capacity.                                      |
|Example: 3.227 50                                                                                                   |
|                                                                                                                    |
|====================================================================================================================|
|                                             |Running the program|                                                  |
|After inputing the data in the given files, open the "Timetable Generator 2000.exe" and write the name of the       |
|groups separated by space, which timetable you want to access(IMPORTANT! it must be same as in "groups.txt").       |
|Example: BEng15 EEY21                                                                                               |
|After entering the needed groups, enter "End" to stop the programm.                                                 |
|(IMPORTANT NOTE: Every time you run the program, new timetables will be generated)                                  |
|====================================================================================================================|
|                                     |Output of the Timetable Generator 2000|                                       |
|To access the generated timetable for groups that you wanted to access, go to the root folder and open file         |
|"TimeTable.txt". Moreover in the given folder you can find the file namely "Timetable for All Groups.txt", where    |
|all the generated timetables are stored.                                                                            |
|                                                                                                                    |
|====================================================================================================================|
|                                                   |Authors|                                                        |
|Nuray Kenzhebekova - School of Engineering, Undeclared, Year 1.                                                     |
|Assel Kenessova - School of Engineering, Mechanical Engineering Department, Year 1.                                 |
|Serzhan Omarov - School of Engineering, Electical and Electronic Engineering Department, Year 1.                    |
|Alisher Aitbayev - School of Engineering, Electical and Electronic Engineering Department, Year 1.                  |
|                                                                                                                    |
|====================================================================================================================|
|                                             |Contact Information|                                                  |
|If you have any questions or suggestions regarding the given program, feel free to contact emails given below:      |
|alisher.aitbayev@nu.edu.kz                                                                                          |
|serzhan.omarov@nu.edu.kz                                                                                            |
|assel.kenessova@nu.edu.kz                                                                                           |
|nuray.kenzhebekova@nu.edu.kz                                                                                        |
|                                                                                                                    |
|====================================================================================================================|









