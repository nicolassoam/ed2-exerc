#ifndef BTREE_H__
#define BTREE_H__
#include <string.h>

//-----------------------------------------------------------------------------
// B-Tree implementation
// 

template<typename T> class BTree;

// TODO: Implementar a  classe BTreeNode
//       Use friend 
template<typename T>
class BTreeNode {
    friend class BTree<T>;
    public:
            BTreeNode(int n);
            ~BTreeNode();
            int findkey(T element);
            void removeFromLeaf(int x);
            void removeFromNonLeaf(int x);
            void insertNonFull(T element);
            void removeN(T x);
            T getPred(int x);
            T getSucc(int x);
            void traverse();
            void BTree_Split_Child(BTreeNode<T> *x, int i);
    private:
            bool leaf;              // booleano true para nó folha
            int n;                  // numero de chaves
            int t;                 // numero de filhos
            T* key;                 // vetor de chaves do node
            BTreeNode** children;   // vetor de filhos
};

template <typename T>
BTreeNode<T>::BTreeNode(int t){
    key = new T[2*t-1];
    children = new BTreeNode*[2*t];

    for(int i =0; i< 2*t; i++)
        children[i] = nullptr;
    
    leaf = true;
    this->t = t;
    this->n = 0;
};

template <typename T>
void BTreeNode<T>::traverse(){
    int i;
    for (i = 0; i < 2*t; i++)
    {
        if(this->leaf == false)
            children[i]->traverse();
        cout << " "<<key[i] << endl;
    }

    if (leaf ==false)
    {
        children[i]->traverse();
    }
};

template <typename T>
int BTreeNode<T>::findkey(T element){
    for(int i =0; i< 2*t-1; i++){
        if(key[i] == element)
            return i;
    }
};

template <typename T>
void BTreeNode<T>::removeFromLeaf(int x){
   for (int i=x+1; i< n; ++i)
        key[i-1] = key[i];
    n--;
};

template <typename T>
T BTreeNode<T>::getPred(int x){
   BTreeNode<T> *aux = children[x];
   while(aux->leaf == false){
        aux = aux->children[aux->cN];
   }
   return aux->key[(aux->t*2-1)];
};

template <typename T>
T BTreeNode<T>::getSucc(int x){
   BTreeNode<T> *aux = children[x];
   while(aux->leaf == false){
        aux = aux->children[0];
   }
   return aux->key[0];
};


template <typename T>
void BTreeNode<T>::removeFromNonLeaf(int x){
    T chave = key[x];
    if(children[x]->x == 2*t-1){
        T pred = getPred(x);
        key[x] = pred;
        children[x]->remove(pred);
    }
};

template<typename T>
void BTreeNode<T>::BTree_Split_Child(BTreeNode<T> *x, int i){

    BTreeNode<T>*z = new BTreeNode<T>(t);

    z->leaf= x->leaf;
    z->n = t-1;
    
    for(int j=0; j< 2*t-1;j++)
        z->key[j] = x->key[j+t];

    if(x->leaf == false){
        for(int j = 0; j<2*t;j++)
            z->children[j] = x->children[j+t];
    }

    x->n = t-1;

    for(int j = n; j >= i+1; j--){
        children[j+1] = children[j];
    }

    children[i+1] = z;

    for(int j = n-1; j>=i;j--)
        key[j+1] = key[j];

    key[i] = x->key[t-1];
    
    n = n + 1;
}


template <typename T>
void BTreeNode<T>::removeN(T x){
/*    int z = findkey(x);

   if(z < n && key[z] == x){
        if(leaf == true)
            removeFromLeaf(z);
        else
            removeFromLeaf(z);
   } else {
        if(leaf == true){
            return;
        }

   } */
};

template <typename T>
BTreeNode<T>::~BTreeNode(){
   
}


template<typename T>
void BTreeNode<T>::insertNonFull(T element){
    int i = 2*t-1;
    if(leaf == true){
        while(i>=0 && key[i] > element){
            key[i+1] = key[i];
            i--;
        }
        key[i+1] = key[i];
        n = n+1;
    }else{
        while(i>= 0 && key[i] > element)
            i--;
        if(children[i+1]->n == n-1){
            BTree_Split_Child(children[i+1], i+1);
            if(key[i]<element)
                i++;
        }
        children[i+1]->insertNonFull(element);
    }
}


// TODO: Implementar a classe BTree
//  Os seguintes métodos deve ser implementados:
//   - BTree(int ordem): Cria uma Btree com a ordem passada como parâmetro.
//   - ~BTree(): Destrutor da Btree.
//   - void insert(T element): Insere o elemento passado como parâmetro na Btree.
//   - void remove(T element): Remove o elemento passado como parâmetro da Btree.
//   - bool search(T element): Retorna true se o elemento passado como parâmetro está na Btree, false caso contrário.
//   - void print(): Imprime a Btree in-order

template<typename T>
class BTree {
    public:
        BTree(int ordem);            //construtor;
        ~BTree();                    //destrutor;

        void insert(T element);      //inserção de elementos;
        void remove(T element);      //remoção de elementos;
        bool search(T element);      //retorna se elemento esta presente na Btree;
        void print();                //imprime em ordem;
        

    private:
        BTreeNode<T> *root;          //raiz da BTree;
        int ordem;                   //ordem da BTree;
        void deallocate(BTreeNode<T>*x);
};

template<typename T>
BTree<T>::BTree(int ordem){
    this->ordem = ordem;
    root = new BTreeNode<T>(ordem);
}


template<typename T>
bool BTree<T>::search(T element){
    int i =0;
    BTreeNode<T>* node = root;
    while(node->n >= i && element > node->key){
        i++;
        if(node->n <= i && element == node->key)
            return true;
        else if(node->leaf == true)
            return false;
        else
            return false;
    }
}


template<typename T>
void BTree<T>::insert(T element){
    if(root == NULL){
        root->key[0] = element;
        root->n = root->n + 1;
    } else {
        if(root->n == ordem-1){
            BTreeNode<T>* s = new BTreeNode<T>(ordem);
            s->children[0] = root;
            s->BTree_Split_Child(root,0);
            int i =0;
            if(s->key[0] < element)
                i++;
            s->children[0]->insertNonFull(element);
            root = s;
        }else
            root->insertNonFull(element);
    }
}


template<typename T>
void BTree<T>::remove(T element){
    BTreeNode<T>*node = root;
    
}

template<typename T>
void BTree<T>::print(){
    if(root!=NULL)
        root->traverse();
}

template <typename T>
void BTree<T>::deallocate(BTreeNode<T>*x){
    if(x == nullptr)
        return;
    for (int i = 0; i < 2*ordem; i++)
    {
        deallocate(x->children[i]);
    }
    delete x;
}


template<typename T>
BTree<T>::~BTree(){
    deallocate(root);
}

template<typename T>
bool compareStr(T& a, T&b){
    return strcmp(*a,*b) < 0;
}



#endif /* BTREE_H__ */
