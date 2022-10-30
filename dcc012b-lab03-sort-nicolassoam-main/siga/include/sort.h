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
            p->n_comp++;
            array[j + 1] = array[j];
            j = j - 1;
            p->n_mov++;
        }
        array[j + 1] = key;
        p->n_mov++;
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
            p->n_comp++;
            if (compare(array[j], array[min]))
                min = j;
        }
        p->n_mov+=3;
        troca(array[i], array[min]);
    }
}

template <typename T>
void merge(T *array, int start, int middle, int end, bool (*compare)(T&, T&),PerformanceMetrics *p ) {
    int esq = start;
    int dir = middle;
    T* aux = new T[end];
    for (int i = start; i < end; ++i) {
        p->n_comp++;
        if (esq < middle && ((dir >= end) || (compare(array[esq], array[dir])))) {
            aux[i] = array[esq];
            ++esq;
            p->n_mov++;
        }
        else {
            aux[i] = array[dir];
            ++dir;
            p->n_mov++;
        }
    }
   
    for (int i = start; i < end; ++i) {
        array[i] = aux[i];
        p->n_mov++;
    }
    delete [] aux;
}



template <typename T>
void mergesort_internal(T* array, int start, int end, bool (*compare)(T&, T&), PerformanceMetrics *p)
{
    // TODO: Implementar merge sort aqui
    if((end-start) < 2){
        return;
    }


    int middle = ((start + end)/2);
   
    mergesort_internal<T>(array ,start, middle,compare,p);
    mergesort_internal<T>(array,middle, end,compare,p);
    merge<T>(array ,start, middle, end,compare,p);

}


template <typename T>
void quicksort_internal(T* array, int low, int high, bool (*compare)(T&, T&), PerformanceMetrics *p)
{
    // TODO: Implementação do quicksort
    
  
    int i, j;

    T pivo;
	i = low;
	j = high;
	pivo = array[(int)((low + high) / 2)];
	while(i <= j)
	{
		while((compare(array[i],pivo)) && (i < high))
		{
            p->n_comp++;
			i++;
		}
		while(compare(pivo, array[j]) && (j >low))
		{
            p->n_comp++;
			j--;
		}
		if(i <= j)
		{
            p->n_comp++;
            p->n_mov+=3;
			troca(array[i],array[j]);

            i++;
            j--;
		}
	}
	if(j > low)
		quicksort_internal<T>(array, low, j+1, compare,p);
	if(i < high)
		quicksort_internal<T>(array, i, high, compare, p);
    
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
    mergesort_internal(array, 0, size, compare, &p);
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
