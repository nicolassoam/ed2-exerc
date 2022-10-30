#ifndef SORT_H__
#define SORT_H__


template <typename T>
void bubble_sort(T* array, int size, bool (*compare)(T&, T&))  
{
    // TODO: Implementação do Bubble Sort
    T aux;
     for(int i = 0; i < size-1; i++){
         for (int j = 0; j < size-i - 1; j++)
         {
            if(compare(array[j+1], array[j])){
                
                aux = array[j];
                array[j] = array[j+1];
                array[j+1] = aux;
            }
         }  
     }

}

template <typename T>
void insert_sort(T* array, int size,  bool (*compare)(T&, T&))
{
    // TODO: Implementação do Insert Sort
    T aux;
    int j = 0;
   for (int i = 1; i < size; i++)
   {
       aux = array[i];
       j = i-1;
       while((j>=0) && (compare(aux, array[j]))){
           array[j+1] = array[j];
           j--;
       }
       array[j+1] = aux;
   }
   
    
}


template <typename T>
void selection_sort(T* array, int size, bool (*compare)(T&, T&))
{
    // TODO: Implementação do selection Sort 
     int min;
     T aux;
    for (int i = 0; i < size-1; i++)
    {
        
        min = i;
        for(int j = i+1; j < size; j++){
            if(compare(array[j],array[min])){
                min = j;
            }
        }
        if(i!=min){
        aux = array[i];
        array[i] = array[min];
        array[min] = aux;
        }
    }
}


#endif /* SORT_H__ */
