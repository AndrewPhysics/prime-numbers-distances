#include <iostream>
using namespace std;

int getNumber()
{
    int upperLimit = 0;
    cout<<"Please type upper limit of interval to be investigated!"<<endl;
    cin >> upperLimit;
    return upperLimit;
}

int primeFinder(int numberToScan) 
{
    int divisor = 2;
    while (divisor <= numberToScan)
    {
        if (numberToScan % divisor == 0)
        {
            break;
        }
        divisor++;
    }
    if (numberToScan == divisor)
    {
        return numberToScan;
    }
    else
    {
        return 0;
    }
}

int primeNumberSorter(int* pArray, int upperLimit)
{
    int i = 2;
    int j = 0;
    int c = 0;
    cout << "Zero means current number is not prime!" << endl;
    int container = 0;
    while (i < upperLimit)
    {
        container = primeFinder(i);
        cout <<j+1<<". " << container << endl;
        if (container != 0)
        {
            pArray[c] = container;
            c++;
        }
        i++;
        j++;
    }
    cout << "---" << endl;
    int count = c;
    i = 0;
    while (i < count)
    {
        cout <<i+1<<". " << pArray[i] << endl;
        i++;
    }
    cout << "number of primes found: " << count << endl;
    return count;
}

void calculatePrimeDistances(int* pArray, int NumberOfPrimes) 
{
    int* pDistanceArray = new int[NumberOfPrimes-1];
    int distanceContainer = 0;
    int i = 0;
    int j = 0;
    while (i<NumberOfPrimes-1)
    {
        distanceContainer = pArray[i+1] - pArray[i];
        pDistanceArray[j] = distanceContainer;
        cout <<i+1<<". " << pDistanceArray[j] << endl;
        i++;
        j++;
    }
    int count = NumberOfPrimes - 1;
    cout << "number of distances calculated: " << count << endl;
    delete[] pDistanceArray;
}

int main()
{
    int upperLimit = getNumber();
    int* pArray = new int[upperLimit];
    int numberOfPrimes = primeNumberSorter(pArray, upperLimit);
    cout << "---" << endl;
    calculatePrimeDistances(pArray, numberOfPrimes);
    delete[] pArray;
}
