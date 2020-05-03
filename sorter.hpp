/*
*   Name    :   counting sort
*   Author  :   Manuel Vargas Evans
*
*   Desc    :   sortArray takes a defined array of int and returns a sorted array
*               in O(n) time.   
*
*   Source  :   "counting sort" is an integer sorting algorithm for small values.
*               http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap09.htm
*/ 
#include <iostream> 
#include <stdexcept>                

// Sorter implements utilities to execute sorting algorithm over integer arrays
class Sorter {
    private:
        void printArray(int* array){
            for (int i = 0 ; i < size; i++) {
                std::cout << array[i] << " ";
            }
            std::cout << std::endl;
        }

        int getMaxElement(int* array, int arraySize){
            int max = 0;
            for (int i = 0; i < arraySize; i++){
                max = array[i] > max ? array[i] : max;
            }
            return max;
        }

        /* areElements can be used to validate array-element properties.
        *   method = 'P' : Check if elements are positive )>= 0)
        */
        bool areElements(int* array, int arraySize, char method){               
            switch (method){
                case 'P':
                    return hasOnlyPositive(array, arraySize);
                default:
                    throw std::invalid_argument{"method not implement in areElements"};
            }
        }

        bool hasOnlyPositive(int* array, int arraySize) {
            for (int i = 0; i < arraySize; i++){
                if (array[i] < 0) { 
                    return false;
                }
            }
            return true;
        }

        void populate(int* input){
            for (int i = 0; i < size; i++){
                data[i] = input[i];
            }
        }

    public:
        int size;                           // array size
        int *data;                          // data holder for int types
        int *sorted;                        // sorted data

        Sorter(int* arr, int s) {           
            size = s;
            data = new int[s];
            sorted = new int[s];
            populate(arr);                  // Fills data with arr
        }

        ~Sorter(){                          
            delete(data);
            delete(sorted);
        }

        void printResults(){

            std::cout << "<------------------------- Sorter Results ------------------------->" << std::endl;
            std::cout << "input : ";
            printArray(data);
            std::cout << "sorted: ";
            printArray(sorted);
        }

        int* getSorted() {
            return sorted;
        }

        // countingSort requires an array of >=0 integers to sort in ascending order.
        // Normally operates at O(n+2k) or O(2(n+k)).
        // For O(n+k), with k << n, it is considered O(n).
        void countingSort(){

            // Obtaining the max value of the elements is O(n).
            // Normally, countingSort receives this value as input, for which
            // it is not normally considered into the time calculation.
            // If included, it adds O(n).
            int max;
            try {
                max = getMaxElement(data, size);
                if (!areElements(data,size, 'P')){
                    throw std::runtime_error("elements in counting sort must be >= 0");
                }
            } catch (const std::exception& e) {
                throw;
            }
            
            int frequency[max+1] = {0};

            // Fill frequency with the times each element is present in input.
            // This adds O(k)
            for(int i = 0; i < size; i++) {
                frequency[data[i]]++;
            }

            // Re-organize to hold a sum of the times each element is present
            // This adds O(k)
            for (int j = 1; j < max+1; j++){
                frequency[j] = frequency[j] + frequency[j-1];
            }

            // Re-allocate the data producing a sorted output 
            // by emptying the frequency array and placing it organize
            // by one in the output. This gives O(n) time.
            for (int i = size-1; i >= 0; i--){
                frequency[data[i]] = frequency[data[i]] - 1;
                sorted[frequency[data[i]]] = data[i];
            }
        }
};