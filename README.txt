In test_sorting_algorithms.cc I modify these functions:
1) VerifyOrder
	Verifies that a vector is sorted given a comparator. If vector is sorted as per given comparator return true otherwise return false.

2) GenerateRandomVector
	This function generates and returns random vector of size @size_of_vector using rand() function.

3) GenerateSortedVector
	This function generates and returns sortef vector of size @size_of_vector.If smaller_to_larger is true, returns vector sorted from small to large
        Otherwise returns vector sorted from large to small.

4) testSortingWrapper
	All algorithm's working checked in this function. If input type is random then generate random vector if sorted then generate sorted vector.
	If comparison_type is less then call all the algorithm by passing less<int>{} otherwise greater<int>{}.

In Sort.h I modify these functions:

In this I complete the implementation of all the algorithm given in this file. 
MergeSort function use to sort the vector using merge sort algorithm.
QuickSort function:
	If pivotType is 1 then quick sort select the pivot using median3.
	If pivotType is 2 then quick sort select the center vector index.
	If pivotType is 3 then quick sort select the first vector index.
	