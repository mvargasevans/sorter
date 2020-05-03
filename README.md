# Sorter

Sorter is a c++ implementation of a class for sorting algorithms on
int-based arrays.

This implementation includes counting sort to sort an array in ascending order.
The method works at O(n) time when the size of the array is bigger than the
maximum value of the elements inside.

See [this reference](http://staff.ustc.edu.cn/~csli/graduate/algorithms/book6/chap09.htm) for details.

## Usage

Refer to `testsort.cpp` for a detailed example of using `sorter`.

```C++
int input[30]   = {2,2,1,0,1,0,1,1,0,2,2,1,1,1,2,0,0,1,1,0,1,0,1,2,0,0,0,1,1,2};
    int length = sizeof(input)/sizeof(*input);
    Sorter mySorter = Sorter(input, length);

    try {
        mySorter.countingSort();                            // Other sorting methods could be added later.
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    int* sorted = mySorter.getSorted(); 

```

## Testing results

This implementation uses catch to apply unit testing.
```
<------------------------- Sorter Results ------------------------->
input : 2 2 1 0 1 0 1 1 0 2 2 1 1 1 2 0 0 1 1 0 1 0 1 2 0 0 0 1 1 2 
sorted: 0 0 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 
===============================================================================
All tests passed (4 assertions in 2 test cases)
```