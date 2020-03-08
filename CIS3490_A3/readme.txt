****************************************************
Danyal Mahmood                          0956989
CIS 3490                                Assignment 3
dmahmood@uoguelph.ca                    Mar 09, 2020
****************************************************

Program Description
****************************************************

Additional Program  Details
****************************************************
To compile simulation simply type "make all"
Executable 'cis3490a3’ will be created

The user MUST specify two file names in the command line with the program, the first file runs with the anagrams algorithm and the second file runs the string search algorithms

The user can select which program to run based on the options menu

Q 2.4
****************************************************
Comparing the brute force method and horspools method, the brute force on average takes 1.2x longer and requires 4.9x more shit operations on average. The calculation to determine these numbers can be noted below, which used 10 different inputs of different lengths. The reason for this is brute force exhaustively visits every character in the file, but the horspools uses a preprocessed shift table which allows the algorithm to shift through characters at a rate of higher than 1. The longer the input, the more flexibility and larger shift values the shift table has, which makes the horspools algorithm even faster which can be noticed in the calculations below. It can be noted that when the input lengths are shorter the closer the Horspools algorithm performance is to brute force.

Calculations
*****************************

Average shift ratio: 4.89
Average runtime ratio: 1.20

Word length 1: a
*******************
Occurrences: 212358

Brute shifts: 3296592
Brute runtime: 0.025
Horspool shifts: 3296503
Horspool runtime: 0.027

Shift ratio: 1
Runtime ratio: 0.93

Word length 2: it
*******************
Occurrences: 23366

Brute shifts: 3296592
Brute runtime: 0.026
Horspool shifts: 1693072
Horspool runtime: 0.025

Shift ratio: 1.95
Runtime ratio: 1.08

Word length 3: The
*******************
Occurrences: 3221

Brute shifts: 3296592
Brute runtime: 0.023
Horspool shifts: 1118570
Horspool runtime: 0.022

Shift ratio: 2.95
Runtime ratio: 1.05

Word length 4: full
*******************
Occurrences: 733

Brute shifts: 3296592
Brute runtime: 0.022
Horspool shifts: 862934
Horspool runtime: 0.02

Shift ratio: 3.82
Runtime ratio: 1.1

Word length 5: refer
*******************
Occurrences: 1219

Brute shifts: 3296592
Brute runtime: 0.026
Horspool shifts: 723974
Horspool runtime: 0.019

Shift ratio: 4.55
Runtime ratio: 1.37

Word length 6: member
*******************
Occurrences: 2102

Brute shifts: 3296592
Brute runtime: 0.022
Horspool shifts: 602689
Horspool runtime: 0.016

Shift ratio: 5.47
Runtime ratio: 1.38

Word length 7: degrees
*******************
Occurrences: 5

Brute shifts: 3296592
Brute runtime: 0.023
Horspool shifts: 534176
Horspool runtime: 0.019

Shift ratio: 6.17
Runtime ratio: 1.21

Word length 8: Calendar
*******************
Occurrences: 25

Brute shifts: 3296592
Brute runtime: 0.022
Horspool shifts: 501665
Horspool runtime: 0.02

Shift ratio: 6.57
Runtime ratio: 1.1

Word length 9: activitie
*******************
Occurrences: 682

Brute shifts: 3296592
Brute runtime: 0.023
Horspool shifts: 418270
Horspool runtime: 0.016

Shift ratio: 7.88
Runtime ratio: 1.44

Word length 10: Statistics
*******************
Occurrences: 88

Brute shifts: 3296592
Brute runtime: .02
Horspool shifts: 396269
Horspool runtime: 0.015

Shift ratio: 8.32
Runtime ratio: 1.33
