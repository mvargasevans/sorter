// Catch is a Unit Test framework.
// https://github.com/catchorg/Catch2
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "sorter.hpp"
#include <algorithm>
#include <iterator>

// compare assumes arrays have the same size
bool compare(int* A, int* B, int size) {
    
    for (int i = 0; i < size; i++){
        if (A[i] != B[i]) {
            return false;
        }
    }
    return true;
}

TEST_CASE("Comparing two arrays", "[compare]") {

    int A[4] = {1,2,3,4};
    int B[4] = {1,2,3,5};

    REQUIRE( compare(A,B, 4) == false );
    B[3] = 4;
    REQUIRE( compare(A,B,4) == true);
}


TEST_CASE("Counting sort", "[countingSort]") {

    int input[30]   = {2,2,1,0,1,0,1,1,0,2,2,1,1,1,2,0,0,1,1,0,1,0,1,2,0,0,0,1,1,2};
    int length = sizeof(input)/sizeof(*input);
    Sorter mySorter = Sorter(input, length);

    try {
        mySorter.countingSort();                            // Other sorting methods could be added later.
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    int *sorted = mySorter.getSorted();
    
    int resultFalse[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    int resultTrue[30]  = {0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2};

    REQUIRE( compare(sorted, resultFalse, length) == false );
    REQUIRE( compare(sorted, resultTrue, length) == true );
    mySorter.printResults();
}