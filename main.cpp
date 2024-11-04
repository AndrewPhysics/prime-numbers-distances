#include <iostream>
#include <fstream>
using namespace std;
//function prototypes
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
void calculatePrimeDistances(int* pArray, int numberOfPrimes, int* pDistanceArray)
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



int szamoloFuggveny(int* pDistanceArray, int vizsgalt_szam, int distanceCount)
{
    int i = 0;
    int count = 0;
    while (i < distanceCount)//Megszámolja egy adott szám előfordulását
    {
        if (pDistanceArray[i] == vizsgalt_szam)
        {
            count++;
        }
        i++;
    }
    return count;
}
void segedFuggveny(int* pDistanceArray, int distanceCount, int* pValueCounterArray)
{


    int vizsgalt_szam = 0;
    while (vizsgalt_szam < distanceCount)
    {
        //trükk: A vizsgált szám változónak 2 szerepe van:
        //1. átadjuk a számoló függvénynek mint keresett értéket
        //2. indexeli a dinamikus tömböt
        //3. ciklus változóként is felhasználjuk

        //Eredmeny: A vizsgalt_szam adik helyre beírja, hogy a vizsgált szám hányszor fordul elő

        pValueCounterArray[vizsgalt_szam] = szamoloFuggveny(pDistanceArray, vizsgalt_szam, distanceCount);
        vizsgalt_szam++;
    }
}

void readArray(int* pDistanceArray, int distanceCount)
{
    int i = 0;
    while (i < distanceCount)
    {
        cout << i << "  : " << pDistanceArray[i] << " db" << endl;
        i++;
    }
}






int main()
{
    int upperLimit = getNumber();
    int* pArray = new int[upperLimit];

    int numberOfPrimes = primeNumberSorter(pArray, upperLimit);
    cout << "---" << endl;

    int* pDistanceArray = new int[numberOfPrimes];

    calculatePrimeDistances(pArray, numberOfPrimes, pDistanceArray);

    writePrimeDistancesToFile(pDistanceArray, numberOfPrimes-1);

    int* pValueCounterArray = new int[numberOfPrimes-1];


    segedFuggveny(pDistanceArray, numberOfPrimes-1, pValueCounterArray);

    readArray(pValueCounterArray, numberOfPrimes-1);

    delete[] pArray;
    delete[] pDistanceArray;
    delete[] pValueCounterArray;
}

