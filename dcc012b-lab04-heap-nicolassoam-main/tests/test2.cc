
#include <string>
#include <iostream>
using namespace std;


#include "leftist_heap.h"

// Testa a a funcçao findMax de uma Heap Esquerdistas

int main(int argc, char *argv[])
{

    int array1[] = {4,3,20,1,52,6,80,8,98,10};
    int array2[] = {6,4,121,5, 45};
    int size1 = sizeof(array1)/sizeof(array1[0]);
    int size2 = sizeof(array2)/sizeof(array2[0]);

    // Cria uma heap esquerdista vazia.
    LeftistHeap<int> heap;

    // Insere os elementos do array na heap.
    for (int i = 0; i < size1; i++) {
        cout << "Inserindo " << array1[i] <<":"<< endl;
        heap.Insert(array1[i]); 
    }

    cout << "O maior elemento da heap eh: " << heap.FindMax() << endl;
    if(heap.FindMax() != 98)
        return -1; // indica que o teste falhou
    
    for(int i = 0; i < size2; i++)
    {
        cout << "Inserindo " << array2[i] <<":"<< endl;
        heap.Insert(array2[i]); 
    }
    cout << "O maior elemento da heap eh: " << heap.FindMax() << endl;
    if(heap.FindMax() != 121)
        return -1; // indica que o teste falhou


    if(!heap.isLeftistHeap())
        return -1; // indica que o teste falhou
        
    return 0; // indica que o teste passou

}


