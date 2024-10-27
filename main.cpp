#include <iostream>
#include <fstream>
using namespace std;
//function prototypes
int getNumber();
int primeFinder(int numberToScan);
int primeNumberSorter(int* pArray, int upperLimit);
int calculatePrimeDistances(int* pArray, int numberOfPrimes, int* pDistanceArray);
void writePrimeDistancesToFile(int* pDistanceArray, int count);
void countOccurrences(int* pDistanceArray, int distanceCount, int* pValueCounterArray, int upperLimit);
void countOccurrences2(int* pDistanceArray, int distanceCount, int* pValueCounterArray, int upperLimit);




int main()
{
    int upperLimit = getNumber();
    int* pArray = new int[upperLimit];

    int numberOfPrimes = primeNumberSorter(pArray, upperLimit);
    cout << "---" << endl;

    int* pDistanceArray = new int[numberOfPrimes - 1];

    int distanceCount = calculatePrimeDistances(pArray, numberOfPrimes, pDistanceArray);

    //writePrimeDistancesToFile(pDistanceArray, distanceCount);

    int* pValueCounterArray = new int[distanceCount];

    countOccurrences(pDistanceArray, distanceCount, pValueCounterArray, upperLimit);


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
//The pArray contains the prime numbers found.
int calculatePrimeDistances(int* pArray, int numberOfPrimes, int* pDistanceArray)
{
    cout << "Calculated distances between primes: " << endl;
    int distanceContainer = 0;
    int i = 0;
    int j = 0;
    while (i < numberOfPrimes - 1)
    {
        distanceContainer = pArray[i + 1] - pArray[i];//Calculating the distance between two consecutive prime numbers.
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

void countOccurrences(int* pDistanceArray, int distanceCount, int* pValueCounterArray, int upperLimit)
{
    //Azt kellene megkeresni, hogy az egyes távolságoknak milyen az előfordulása
    //Azt nézem meg, hogy előfoul-e a j értéke a pDistanceArray- ben

    //mibe keresek? pDistanceArray
    //méret: distanceCount

    //mibe tárolom az eredményt? pValueCounterArray
    //méret: ?

    cout << "***" << endl;
    cout <<"distanceCount = "<< distanceCount << endl;

    int number = 0;
    int i = 0;
    int j = 0;
    while (j<distanceCount)
    {
        i = 0;
        while (i < distanceCount)
        {
            if (pDistanceArray[i] == number)
            {
                cout << "kkk:" <<number<< endl;
                pValueCounterArray[number]++;
                
            }
            
            i++;
        }
        number++;
        j++;
    }

    cout << "zzz" << endl;

    i = 0;
    while ( i < distanceCount)
    {
        cout << pValueCounterArray[i] << endl;
        i++;
    }

    //idáig működik




    /*
        int i = 0;
        while (i < distanceCount)
        {
            if (pDistanceArray[i]==j)
            {
                pValueCounterArray[j]++;
            }
            i++;
        }
    */

    //ha kész van a keresés:

    /*
    i = 0;
    int index = 0;
    while (i < distanceCount)
    {
        cout << index << "-bol " << pValueCounterArray[i] << " db van!" << endl;
        index++;
        i++;
    }
    */
}






void countOccurrences2(int* pDistanceArray, int distanceCount, int* pValueCounterArray, int upperLimit)
{


    int i = 0;
    int number = 1;
    while (i < distanceCount)
    {
        if (pDistanceArray[i]==number)
        {
            cout << "x" << endl;
            pValueCounterArray[number] = pValueCounterArray[number] + 1;
        }
        i++;
    }

    i = 0;
    while (i<distanceCount)
    {
        cout << pValueCounterArray[i] << endl;
        i++;
    }


}
