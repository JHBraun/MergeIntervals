# MergeIntervals
C++-application (windows console) to sort a list of intervals. If there are overlapping intervals, they will be merged.

## functionality
The core of the project is a function called merge(), which is able to take any list of intervals (e.g. [25,30] [2,19] [14, 23] [4,8]) and return a sorted merged list of these ([2,23] [25,30]). Therefore overlapping intervals will be merged into a new interval. The unchanged intervals stay the same.
The user can enter any number of intervals and will recieve the merged list as output on the console.

## concept
To find overlapping intervals, you have to compare the full set of intervals by themselves. For this, every single interval needs to be checked for overlapping ones to merge them and delete the overlapping one. This task takes a huge amount of processing time when worked with big inputs.
Therefore the approach of this solution is to firstly sort the given intervals by their individual start number. In this case, you are able to compare the intervals straight in a line, from the lowest to the highest startnumber. The reason is that if a interval(n), e.g. [2,5], can not be merged with the interval(n+1): [7,20], it will also never be possible to merge it with the next interal(n+2): [9,15], because the start number can never be lower. Eventually, you are able to compare the intervals one by one follwing the sorted list.

According to this solution, 3 options appear during a overlap-check:
a) N: [1,5]  N+1: [7,10]
If the current interval(n) does not overlap with the following one (n+1), both of them will remain.

b) N: [1,5]  N+1: [3,10]
If the current interval(n) overlaps with the following one (n+1) and the endnumber of interval(n+1) is higher than from (n), they will be merged and the end number will be updated. -> [1,10]

c) N: [1,5]  N+1: [2,4]
If the current interval(n) overlaps with the following one (n+1) an the endnumber of interval(n+1) is lower than from (n), interval (n+1) will be merged into interval (n).
-> [1,5]

Another advantage of this approach is a sorted output by the increasing start number.

## installation and running the build
This project can be imported directly into visual studio and uses the windows sdk version 10.0.17763.0. 
