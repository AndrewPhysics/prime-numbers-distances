Analyzing distances between prime numbers
1. getNumber
This function requests the upper limit of the examined interval.

2. primeFinder
The task of this function is to determine whether the input parameter is a prime number based on integer division. If so, the return value is the prime number itself. If not, the function returns 0.

3. primeNumberSorter
This function sorts the prime numbers. If the prime finder function returns non-zero, we store the given prime in a dynamic array. (pArray) The size of the dynamic array is the entire examined interval.

4. calculatePrimeDistances
This function calculates the distance between 2 consecutive prime numbers using subtraction. The results are stored in a dynamic array.(pDistanceArray)

5. counting function and helper function
These 2 functions count the occurrences of prime distances.
The examined number variable has 2 roles:
1. we pass it to the calculation function as the searched value
2. it indexes the dynamic array
3. we also use it as a loop variable
Result: The number of times the distance occurs is entered in the appropriate place.
The frequency of the distances is stored in another dynamic array. A histogram can be made from this later.
