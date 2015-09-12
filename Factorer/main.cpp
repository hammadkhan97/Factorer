//
//  main.cpp
//  Factorer
//
//  Created by hakhan2 on 9/11/15.
//  Copyright (c) 2015 hakhan2. All rights reserved.
//

#include <iostream>
using namespace std;

int i = 0;
int j = 0;
int k = 1;

void factor(int number, int arr[], int arrP[]) {
    if (number == 1)
        return;
    else if (number % 2 == 0) {
        number /= 2;
        arr[j++] = 2;
        factor(number, arr, arrP);
    } else {
        while (number != arrP[k]) {
            while (number % arrP[k] == 0) {
                number /= arrP[k];
                arr[j++] = arrP[k];
            }
            k++;
            factor(number, arr, arrP);
            return;
        }
        number = 1;
        arr[j++] = arrP[k];
        return;
    }
}

bool testIfPrime(int x) {
    int counter = 2;
    while (counter != x) {
        if (x % counter == 0)
            return false;
        counter++;
    }
    return true;
}

void findPrimes(int x, int arr[]) {
    if (testIfPrime(x))
        arr[i++] = x;
    x += 1;
    
    if (i == 50)
        return;
    
    findPrimes(x, arr);
}

void print(int arr[]) {
    int i = 0;
    cout << "\n\n";
    cout << "Factors: 1, ";
    while (arr[i] != 0) {
        cout << arr[i++] << ", ";
    }
}

int main() {
    int number;
    cout << "\nEnter the number to factor: ";
    cin >> number;
    
    //The coefficients of all the prime nos. will be stored in an array:
    //Array of primes is the list of the first 50 prime numbers.
    
    int array[50], arrayOfPrimes[50];
    findPrimes(2, arrayOfPrimes);
    factor(number, array, arrayOfPrimes);
    print(array);
    cout << number;
    return 0;
}