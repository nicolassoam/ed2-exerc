#include <iostream>
#include <string>

using namespace std;

#include "splay.h"

// Testa algumas funções da arvore de busca.
int main()
{
    // Cria um SplayTree vazia
    SplayTree splayTree;

    // Insere alguns elementos
    splayTree.insert(20);
    splayTree.insert(10);
    splayTree.insert(30);
    splayTree.insert(5);
    splayTree.insert(15);
    splayTree.insert(25);
    splayTree.insert(35);
    splayTree.insert(1);
    splayTree.remove(35);
    
    // Imprime a arvore
    splayTree.print_tree();


    // Busca por um nó  
    SplayNode* node = splayTree.find(10);

    if (node == nullptr)
    {
        cout << "Node not found" << endl;
    
        return 0;
    }
    
    
    // Imprime a arvore
    splayTree.print_tree();

    // Busca por um nó  
    node = splayTree.find(5);
    if (node == nullptr)
    {
        cout << "Node not found" << endl;
        return 0;
    }

    
    // Imprime a arvore
    splayTree.print_tree();
    splayTree.print_in_order();

    return 0;
}
