Operating System Scheduling Algorithms
Overview

This project implements various process scheduling algorithms commonly used in operating systems. It is written in C programming language and includes functionalities for First-Come First-Served (FCFS), Shortest Job First (SJF), Round Robin Scheduling (RRS), Priority Scheduling (PPSS), Shortest Remaining Time First (SRTF), and Longest Remaining Time First (LRTF) algorithms.
Files Included

    main.c: Contains the main code implementing the scheduling algorithms.
    Output.txt: Output file storing the results of the scheduling algorithms, including average turnaround time, average waiting time, and Gantt chart.
    result.txt: Output file storing the Gantt chart.
    Text.csv: Input file containing process details such as arrival time, burst time, and priority.

Compilation and Execution

To compile the code, use any C compiler such as GCC:

css

gcc main.c -o scheduler

To execute the program:

bash

./scheduler

Usage

    Upon running the program, you will be presented with a main menu.
    Choose a scheduling algorithm by entering the corresponding number.
    Depending on the selected algorithm, the program will read process details from the "Text.csv" file and perform scheduling.
    Results will be displayed on the console and stored in the "Output.txt" file, including Gantt charts and average times.

Description of Algorithms

    First-Come First-Served (FCFS): Processes are executed in the order they arrive.
    Shortest Job First (SJF): Processes with the shortest burst time are executed first.
    Round Robin Scheduling (RRS): Each process is assigned a fixed time slice in a cyclic order.
    Priority Scheduling (PPSS): Processes with the highest priority are executed first.
    Shortest Remaining Time First (SRTF): A preemptive version of SJF where the process with the shortest remaining time is executed.
    Longest Remaining Time First (LRTF): A preemptive version of SJF where the process with the longest remaining time is executed.

Dependencies

    This program depends on the standard C library and assumes a POSIX-compatible environment.

Contributors

    Manav Pandya (21BCE143)
    Ekta Kalavadiya (21BCE106)

License

This project is licensed under the MIT License.
