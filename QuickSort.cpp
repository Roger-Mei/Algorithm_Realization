#include <iostream>
#include <vector> 
#include <stdlib.h>

/* Partition function:
vec --> the vector waiting to be partitioned; low --> starting index; high --> ending index
This function takes last element as pivot.
It will place the pivot element at its correct position by placing all smaller element to its left and greater element
at its right.
*/
int partition (std::vector<int>& vec, int low, int high){
    // Chosose random pivot
    int pivot = vec[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++){
        // if current element is less than pivot
        if (vec[j] < pivot){
            std::swap(vec[++i], vec[j]);
        }
    }
    
    std::swap(vec[i+1], vec[high]);

    return ++i;
}

/* QuickSort function:
vec --> the vector waiting to be sorted; low --> starting index; high --> ending index
This is the main part of quickSort function which will use divide and conquer method to recursively sort the vector
*/
void quickSort(std::vector<int>& vec, int low, int high){
    if (low < high) {
        // pivot is the partitioning index 
        int pivot = partition (vec, low, high);

        // divide and conquer
        quickSort(vec, low, pivot - 1);
        quickSort(vec, pivot + 1, high);
    }
}

// Helper function : Help print the list
void printList(std::vector<int> vec){
    for (std::vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i){
        std::cout << *i << ' ';
    }
    std::cout << std::endl;
} // end of Helper function

int main() {
    //Input your unsorted list
    std::cout << "Please specify your vector size" << std::endl;
    int VSIZE;
    std::cin >> VSIZE;
    std::cout << "The list size is: " << VSIZE << std::endl;
    std::cout << "PLease input your vector" << std::endl;
    std::vector<int> unsortedVec;
    int i = 0;
    int input;
    while ((std::cin >> input) && (i++ < VSIZE)){
        unsortedVec.push_back(input);
    }

    std::cout << "The list you entered is:" << std::endl;
    printList(unsortedVec);

    // Sort and output your result
    quickSort(unsortedVec, 0, VSIZE - 1);
    
    // Output result
    std::cout << "The list after sorting is: " << std::endl;
    printList(unsortedVec);

    return 0;
}
