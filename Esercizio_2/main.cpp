#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unistd.h>
#include "SortingAlgorithm.hpp"


using namespace std;
using namespace chrono;

int main()
{
    int numvettori = 10; // scelgo il numero di vettori da valutare
    int i = 0;

    double tempiMerge = 0.0;
    double tempiBubble = 0.0;

    for (i=0; i< numvettori; i++){
        int size = 10; //lunghezza vettore
        vector<int> v(size);

        generate(v.begin(), v.end(), []() { return (rand() % 100)+1; }); // stampa i vettori con numeri generati casualmente tra 1 e 100

        // Stampo il vettore random
        cout << "Vettore " <<i+1<<": ";
        for (int i : v) {
            cout << i << " ";
        }
        cout << endl;

        // calcolo la performance con MergeSort
        steady_clock::time_point tm_begin
            = steady_clock::now();
        SortLibrary::MergeSort(v);
        _sleep(2);
        steady_clock::time_point tm_end
            = steady_clock::now();

        double durationm = duration_cast<milliseconds>
                          (tm_end - tm_begin).count();
        tempiMerge += durationm;
        cout<<"Il tempo che impiega MergeSort e': " <<durationm<<endl;

        // vettore iniziale
        generate(v.begin(), v.end(), []() { return (rand() %100)+1; });


        // calcolo la performance con BubbleSort
        steady_clock::time_point tb_begin
            = steady_clock::now();
        SortLibrary::BubbleSort(v);
        _sleep(2);
        steady_clock::time_point tb_end
            = steady_clock::now();

        double durationb = duration_cast<milliseconds>
                          (tb_end - tb_begin).count();
        tempiBubble += durationb;
        cout<<"Il tempo che impiega BubbleSort e': " << durationb<<endl;
    }

    //calcolo la media dei tempi
    double mediaMerge = tempiMerge/(numvettori);
    cout << "Tempo medio MergeSort: " << mediaMerge << " microsecondi" << endl;

    double mediaBubble = tempiBubble/(numvettori);
    cout << "Tempo medio BubbleSort: " << mediaBubble << " microsecondi" << endl;


    return 0;
}

