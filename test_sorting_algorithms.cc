// Homework 4
// Testing Sorting Algorithms
// YOUR NAME

 
#include "Sort.h"
#include <chrono>
#include <iostream>
#include <fstream>
#include <functional>
#include <string>
#include <vector>
#include <algorithm>
#define LEFT(i) 2*(i)+1//for the left child
using namespace std;

//////////////////////
// the limits of type
#include <limits>
 
// Test function that shows how you can time a piece of code.
// Just times a simple loop.

// Computes duration given a start time and a stop time in nano seconds
long long ComputeDuration(chrono::high_resolution_clock::time_point start_time, chrono::high_resolution_clock::time_point end_time) {
	// Add code
	long long res = 0;
	res = chrono::duration_cast<chrono::nanoseconds>(end_time - start_time).count();
	return res;
 
} 
void TestingTiming() {
	cout << "Testing Timing" << endl;
	const auto begin_time = chrono::high_resolution_clock::now();
	// Time this piece of code.
	int sum = 0;
	for (int i = 1; i < 10000; ++i) sum++;
	// End of piece of code to time.
	const auto end_time = chrono::high_resolution_clock::now();
	cout << ComputeDuration(begin_time, end_time) << "ns" << endl;
 
}
 
// Generates and returns random vector of size @size_of_vector.
// Generates and returns random vector of size @size_of_vector.
vector<int> GenerateRandomVector(size_t size_of_vector) {
	vector<int> a;
	srand(time(0));
	for (size_t i = 0; i < size_of_vector; ++i)
		a.push_back(rand());
	return a;
}
 
// Generate and returns sorted vector of size @size_of_vector
// If smaller_to_larger is true, returns vector sorted from small to large
// Otherwise returns vector sorted from large to small
vector<int> GenerateSortedVector(size_t size_of_vector, bool smaller_to_larger) {
	// Add code
	vector<int> res;
	if (smaller_to_larger){
		for (size_t i = 0; i < size_of_vector; i++){
			res.push_back(i);
		}
	}
	else{
		for (size_t i = size_of_vector; i > 0; i--){
			res.push_back(i);
		}
	}
	return res;
}
 
 
// Verifies that a vector is sorted given a comparator
template <typename Comparable, typename Comparator>
bool VerifyOrder(const vector<Comparable> &input, Comparator less_than) {

	if(input.size() == 0)
		return true;
	
	for(size_t i = 0; i < input.size()-1; i++)
	{
		if(less_than(input[i+1], input[i])) 
			return false;
	}		
	return true;
}
 

 
// Wrapper function to test the different sorting algorithms
int testSortingWrapper(int argc, char **argv) {
	const string input_type = string(argv[1]);
	const int input_size = stoi(string(argv[2]));
	const string comparison_type = string(argv[3]);
 
	if (input_type != "random" && input_type != "sorted_small_to_large" && input_type != "sorted_large_to_small" && input_type != "sorted") {
		cout << "Invalid input type" << endl;
		return 0;
	}
	if (input_size <= 0) {
		cout << "Invalid size" << endl;
		return 0;
	}
	if (comparison_type != "less" && comparison_type != "greater") {
		cout << "Invalid comparison type" << endl;
		return 0;
	}
 
	// This block of code to be removed for your final submission.
	// removed
	// TestingTiming();
	//sort();
 
	cout << "Running sorting algorithms: " << input_type << " " << input_size << " numbers " << comparison_type << endl;
	vector<int> input_vector;
	if (input_type == "random") {
		// Generate random vector
		input_vector = GenerateRandomVector(input_size);
	}
	else {
		// Generate sorted vector.
		if (input_type == "sorted"){
			input_vector = GenerateSortedVector(input_size, true);
		}
		else if (input_type == "sorted_small_to_large"){
			input_vector = GenerateSortedVector(input_size, true);
		}
		else{
			input_vector = GenerateSortedVector(input_size, false);
		}
		
	}
	
	// Call quicksort / heapsort / mergesort using appropriate input.
	// ...
	// if comparison type is "less" then call 
	// MergeSort(input_vector, less<int>{})
	// otherwise call
	// MergeSort(input_vector, greater<int>{})
	// ...
 
	if (comparison_type == "less"){
		cout << "HeapSort" << endl<<endl;
		auto begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		HeapSort(input_vector, less<int>{});
		
		// End of piece of code to time.
		auto end = chrono::high_resolution_clock::now();
		cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
		cout<<"Verified: "<<VerifyOrder(input_vector, less<int>{})<<endl;
 
		cout <<endl<< "MergeSort" << endl<<endl;
		begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		MergeSort(input_vector, less<int>{});
		
		// End of piece of code to time.
		end = chrono::high_resolution_clock::now();
		cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
		cout<<"Verified: "<<VerifyOrder(input_vector, less<int>{})<<endl;
 
 
		cout <<endl<< "QuickSort" << endl<<endl;
		begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		QuickSort(input_vector, less<int>{});
		// End of piece of code to time.
		end = chrono::high_resolution_clock::now();
		cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
		cout<<"Verified: "<<VerifyOrder(input_vector, less<int>{})<<endl;

		cout<<endl<<endl<<"Testing Quicksort Pivot Implementations"<<endl<<endl;

		cout<<"Median of Three"<<endl<<endl;


		input_vector = GenerateSortedVector(input_size, true);
		begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		QuickSort(input_vector, less<int>{});
		// End of piece of code to time.
		end = chrono::high_resolution_clock::now();
		cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
		cout<<"Verified: "<<VerifyOrder(input_vector, less<int>{})<<endl;
		
                //input_vector = GenerateSortedVector(input_size, true);	
 		cout<<endl<<"Middle"<<endl<<endl;
		  
		  begin = chrono::high_resolution_clock::now();
		  // Time this piece of code.
		  QuickSort2(input_vector, less<int>{});
		  
		  // End of piece of code to time.
		  end = chrono::high_resolution_clock::now();
		  cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
		  cout<<"Verified: "<<VerifyOrder(input_vector, less<int>{})<<endl;
                                                                                    
		  //input_vector = GenerateSortedVector(input_size, true);
		  cout<<endl<<"First"<<endl<<endl;
	
		  begin = chrono::high_resolution_clock::now();
		  // Time this piece of code.
		  QuickSort3(input_vector, less<int>{});
		  // End of piece of code to time.
		  end = chrono::high_resolution_clock::now();
		  cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
		  cout<<"Verified: "<<VerifyOrder(input_vector, less<int>{})<<endl;
	}else{
		cout << "HeapSort" << endl << endl;;
		 auto begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		 HeapSort(input_vector, greater<int>{});
		 
		// End of piece of code to time.
		 auto end = chrono::high_resolution_clock::now();
		 cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
		 cout<<"Verified: "<<VerifyOrder(input_vector, greater<int>{})<<endl;
 
 
		 cout <<endl<< "MergeSort" << endl << endl;;
		begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		MergeSort(input_vector, greater<int>{});
		// End of piece of code to time.
		end = chrono::high_resolution_clock::now();
		cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
                cout<<"Verified: "<<VerifyOrder(input_vector, greater<int>{})<<endl;

   

 
		begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		QuickSort(input_vector, greater<int>{});
		// End of piece of code to time.
		end = chrono::high_resolution_clock::now();
		cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
                cout<<"Verified: "<<VerifyOrder(input_vector, greater<int>{})<<endl;

		cout<<endl<<"Testing Quicksort Pivot Implementations"<<endl<<endl;

		cout<<"Median of Three"<<endl<<endl;	
		input_vector = GenerateSortedVector(input_size, false);
                begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		QuickSort(input_vector, greater<int>{});
		// End of piece of code to time.
		end = chrono::high_resolution_clock::now();
		cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
		cout<<"Verified: "<<VerifyOrder(input_vector, greater<int>{})<<endl;	

		//input_vector = GenerateSortedVector(input_size, false);
		cout <<endl<< "Middle" <<endl<<endl;
		begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		QuickSort2(input_vector, greater<int>{});
		
		// End of piece of code to time.
		end = chrono::high_resolution_clock::now();
		cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
                cout<<"Verified: "<<VerifyOrder(input_vector, greater<int>{})<<endl;
 
 
		//input_vector = GenerateSortedVector(input_size, false);
		cout <<endl<< "First" <<endl<< endl;
		begin = chrono::high_resolution_clock::now();
		// Time this piece of code.
		QuickSort3(input_vector, greater<int>{});
		
		// End of piece of code to time.
		end = chrono::high_resolution_clock::now();
		cout << "Runtime: <" << ComputeDuration(begin, end) << "> ns" << endl;
                cout<<"Verified: "<<VerifyOrder(input_vector, greater<int>{})<<endl;
	}
 
 
	// Call quicksort with median of three as pivot / middle as pivot / first as pivot using appropriate input.
	// ...
	// if comparison type is "less" then call 
	// QuickSort(input_vector, less<int>{})
	// otherwise call
	// QuickSort(input_vector, greater<int>{})
	// ...
	return 0;
}
 
// Do not change anything below
 
int main(int argc, char **argv) {
	if (argc != 4) {
		cout << "Usage: " << argv[0] << "<input_type> <input_size> <comparison_type>" << endl;
		return 0;
	}
	
	testSortingWrapper(argc, argv);
	return 0;
}