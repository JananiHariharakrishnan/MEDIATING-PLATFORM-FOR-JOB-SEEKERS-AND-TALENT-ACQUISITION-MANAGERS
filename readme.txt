Project : MEDIATING PLATFORM FOR JOB SEEKERS AND TALENT ACQUISITION MANAGERS

Team Members: CSE A ,First year

1) Janani Hariharakrishnan , 3122225001046
2) K Hishitha, 3122225001040
3) Madhumitha E ,3122225001068
----------------------------------------------------------------------------------
This guide provides an overview of how the source code is divided between multiple files and explains the steps to compile and link them. The project consists of the following files:

main.c: Contains the main code for the project.
hr_ranks.csv: Stores the details of accepted suggestions by the HR Managers.
ap_ranks.csv: Stores the details of accepted suggestions by the applicants.
hr_details_comp.csv: Stores the compulsory details of the HR Managers.
hr_details_des.csv: Stores the desirable details of the HR Managers.
ap_details_comp.csv: Stores the compulsory details of the Job Seekers.
ap_details_des.csv: Stores the desirable details of the Job Seekers.
------------------------------------------------------------------------------------
Source Code Organization

The source code is organized as follows:

main.c: Contains the main code of the project. It includes function definitions, data structures, and the program's entry and exit points.
------------------------------------------------------------------------------------
Compilation and Linking Steps

To compile and link the source code, follow these steps:

1. Ensure that you have a C compiler installed on your system.

2. Open a terminal or command prompt and navigate to the project directory.

3. Compile the source code files using the appropriate compiler command. 
For example, you can use the following command to compile main.c:

gcc main.c -o project_executable
This command compiles the source code file and generates an object file (main.o).

4. You will have an executable file generated in your project directory.

*CSV files should not be compiled. They are typically read or written by the compiled program at runtime to interact with the data they contain.

-------------------------------------------------------------------------------
Running the Executable

To run the executable, use the following command:

./project_executable

Make sure to provide the required input files (hr_ranks.csv, ap_ranks.csv, etc.) in the same directory as the executable for the program to access them properly.

---------------------------------------------------------------------------------
Conclusion

Following these steps will allow you to compile and run the source code files in your project.