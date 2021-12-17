/*
  UC Berkeley - MSSE Program
  Chem 279-B  Introduction to Software Engineering
  Fall 2021

 mergesort2.cxx  contains a function that divides the input array into two halves, 
 calls itself for the two halves, and then merges the two sorted halves. 
 merge() function is merges two halves of the array. 
 
 Merge(arr, l, m, r) is a key process that assumes that arr[l..m] and arr[m+1..r] are sorted.
 

MergeSort(arr[], l,  r)
If r > l
     1. middle point to divide the array into two halves:  
             middle m = l+ (r-l)/2
     2. mergeSort for first half:   
             Call mergeSort(arr, l, m)
     3. mergeSort for second half:
             Call mergeSort(arr, m+1, r)
     4. Merge sorted subarrays:
              merge(arr, l, m, r)

C++ program for Merge Sort

*/