#include <iostream>
#include <fstream>
using namespace std;
//function prototypes
int getNumber();
int primeFinder(int numberToScan);
int primeNumberSorter(int* pArray, int upperLimit);
int calculatePrimeDistances(int* pArray, int numberOfPrimes, int* pDistanceArray);
void writePrimeDistancesToFile(int* pDistanceArray, int count);
void analizeDistances(int* pDistanceArray,int distanceCount, int upperLimit, int* pValueCounterArray);




int main()
{
    int upperLimit = getNumber();
    int* pArray = new int[upperLimit];

    int numberOfPrimes = primeNumberSorter(pArray, upperLimit);
    cout << "---" << endl;

    int* pDistanceArray = new int[numberOfPrimes - 1];

    int distanceCount = calculatePrimeDistances(pArray, numberOfPrimes, pDistanceArray);

    writePrimeDistancesToFile(pDistanceArray, distanceCount);

    int* pValueCounterArray = new int[distanceCount];

    analizeDistances(pDistanceArray, distanceCount, upperLimit, pValueCounterArray);


    delete[] pArray;
    delete[] pDistanceArray;
    delete[] pValueCounterArray;
}

int getNumber()
{
    int upperLimit = 0;
    cout << "Please type upper limit of interval to be investigated!" << endl;
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
    int index = 1;
    int j = 0;
    cout << "Zero means current number is not prime!" << endl;
    int container = 0;
    while (i < upperLimit)
    {
        container = primeFinder(i);
        cout << index << ". " << container << endl;
        if (container != 0)
        {
            pArray[j] = container;
            j++;
        }
        i++;
        index++;
    }
    cout << "---" << endl;
    int count = j;
    i = 0;
    while (i < count)
    {
        cout << i + 1 << ". " << pArray[i] << endl;
        i++;
    }
    cout << "number of primes found: " << count << endl;
    return count;
}
//pArray containes prime numbers
int calculatePrimeDistances(int* pArray, int numberOfPrimes, int* pDistanceArray)
{
    cout << "Calculated distances between primes: " << endl;
    int distanceContainer = 0;
    int i = 0;
    int j = 0;
    while (i < numberOfPrimes - 1)
    {
        distanceContainer = pArray[i + 1] - pArray[i];//Calculate distance
        pDistanceArray[j] = distanceContainer;
        cout << i + 1 << ". " << pDistanceArray[j] << endl;
        i++;
        j++;
    }
    int count = numberOfPrimes - 1;
    cout << "number of distances calculated: " << count << endl;
    cout << "---" << endl;
    return count;
}
void writePrimeDistancesToFile(int* pDistanceArray, int count)
{
    ofstream outPut;
    outPut.open("distances.txt");
    int i = 0;
    while (i < count)
    {
        outPut << pDistanceArray[i] << endl;
        i++;
    }
    outPut.close();
}

void analizeDistances(int* pDistanceArray, int distanceCount, int upperLimit, int* pValueCounterArray)
{
    //azt kellene megkeresesni, hogy melyik számból hány van!
    int i = 0;
    while (i<distanceCount)
    {
        pValueCounterArray[i] = 0;
        i++;
    }
    i = 0;
    int index = 0;
    while (i< distanceCount)
    {
        pValueCounterArray[pDistanceArray[i]]++;
        cout << index<<"-bol " << pValueCounterArray[i] <<" db van!" << endl;
        index++;
        i++;
    }
}



