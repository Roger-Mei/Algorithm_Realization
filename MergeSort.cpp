#include <iostream>
#include <vector>

// merge function: merge two vectors into 1
std::vector<int> merge(std::vector<int> left, std::vector<int> right, int v_size){
    std::vector<int> result;
    int leftCount = 0, rightCount = 0;
    bool leftFlag;
    for (int k = 0; k < v_size; ++k){
        if (leftCount < left.size()){
            if (rightCount < right.size()){
                leftFlag = (left[leftCount] < right[rightCount]);
            }
            else{
                leftFlag = true;
            }
        }
        else{
            leftFlag = false;
        }

        if (leftFlag) {
            result.push_back(left[leftCount]);
            if (leftCount < left.size()){
                leftCount++;
            }
        }
        else{
            result.push_back(right[rightCount]);
            if (rightCount < right.size()){
                rightCount++;
            }
        }
    }
    return result;
} // end of merge function

// merge sort function: recursive merge sort
std::vector<int> mergeSort(std::vector<int> arr) {
	if (arr.size() <= 1) {
		return arr;
	}
	int len = arr.size() / 2;
	std::vector<int> left(arr.begin(), arr.begin() + len);
	std::vector<int> right(arr.begin() + len, arr.end());

	return merge(mergeSort(left), mergeSort(right), arr.size());
}//end of merge sort 

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
    std::vector<int> sortedVec = mergeSort(unsortedVec);
    
    // Output result
    std::cout << "The list after sorting is: " << std::endl;
    printList(sortedVec);

    return 0;
}
