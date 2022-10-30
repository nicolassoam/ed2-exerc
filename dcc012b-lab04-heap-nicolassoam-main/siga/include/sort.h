#ifndef SORT_H
#define SORT_H

#include <chrono>
#include <iostream>
#include <vector>
using namespace std;

#include "metrics.h"


// Use essa função para movimentar dados 
template <typename T>
void troca(T& a, T& b)
{
    T tmp = a;
    a     = b;
    b     = tmp;
}


template <typename T>
void bubble_sort_internal(T* array, int size, bool (*compare)(T&, T&), PerformanceMetrics *p)  
{
    // bubble sort
    for (int i = size-2; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            p->n_comp++;   // incrementa o número de comparações

            if (compare(array[j+1], array[j]))
            {
                p->n_mov+=3; // troca realiza tres movimentacoes de dados
                troca<T>(array[j], array[j + 1]);
            }
        }
    }
}



template <typename T>
void insertion_sort_internal(T* array, int size,  bool (*compare)(T&, T&), PerformanceMetrics *p)
{
    // Implementação do Insert Sort
    // TODO: Insira as métricas de performance
    for (int i = 1; i < size; i++)
    {
        T key = array[i];
        int j = i - 1;
        while (j >= 0 && compare(key, array[j]))
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}


template <typename T>
void selection_sort_internal(T* array, int size, bool (*compare)(T&, T&), PerformanceMetrics *p)
{
    // TODO: Insira as métricas de performance
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (compare(array[j], array[min]))
                min = j;
        }
        troca(array[i], array[min]);
    }
}



template <typename T>
void mergesort_internal(T* array, int start, int end, bool (*compare)(T&, T&), PerformanceMetrics *p)
{
    // TODO: Implementar merge sort aqui


}


template <typename T>
void quicksort_internal(T* array, int low, int high, bool (*compare)(T&, T&), PerformanceMetrics *p)
{
    // TODO: Implementação do quicksort

}


template <typename T>
void bubble_sort(T* array, int size, bool (*compare)(T&, T&))  
{
    PerformanceMetrics p;
    SetUpPerformanceMetrics(&p);
    auto t1 = Clock::now();
    bubble_sort_internal<T>(array, size, compare, &p);
    auto t2 = Clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    PerformanceMetricsCPUTime(&p, diff.count());
    cout << "Bubble Sort:" << endl; 
    PerformanceMetricsPrint(&p);
}

template <typename T>
void insertion_sort(T* array, int size, bool (*compare)(T&, T&))  
{
    PerformanceMetrics p;
    SetUpPerformanceMetrics(&p);
    auto t1 = Clock::now();
    insertion_sort_internal(array, size, compare, &p);
    auto t2 = Clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    PerformanceMetricsCPUTime(&p, diff.count());
    cout << "Insertion Sort:" << endl; 
    PerformanceMetricsPrint(&p);
}

template <typename T>
void selection_sort(T* array, int size, bool (*compare)(T&, T&))  
{
    PerformanceMetrics p;
    SetUpPerformanceMetrics(&p);
    auto t1 = Clock::now();
    selection_sort_internal(array, size, compare, &p);
    auto t2 = Clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    PerformanceMetricsCPUTime(&p, diff.count());
    cout << "Selection Sort:" << endl; 
    PerformanceMetricsPrint(&p);
}

template <typename T>
void merge_sort(T* array, int size, bool (*compare)(T&, T&))  
{
    PerformanceMetrics p;
    SetUpPerformanceMetrics(&p);
    auto t1 = Clock::now();
    mergesort_internal(array, 0, size-1, compare, &p);
    auto t2 = Clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    PerformanceMetricsCPUTime(&p, diff.count());
    cout << "Merge Sort:" << endl; 
    PerformanceMetricsPrint(&p);
}

template <typename T>
void quick_sort(T* array, int size, bool (*compare)(T&, T&))  
{
    PerformanceMetrics p;
    SetUpPerformanceMetrics(&p);
    auto t1 = Clock::now();
    quicksort_internal(array, 0, size-1, compare, &p);
    auto t2 = Clock::now();
    std::chrono::duration<double> diff = t2 - t1;
    PerformanceMetricsCPUTime(&p, diff.count());
    cout << "Quick Sort:" << endl; 
    PerformanceMetricsPrint(&p);
}

#endif /* SORT_H */
