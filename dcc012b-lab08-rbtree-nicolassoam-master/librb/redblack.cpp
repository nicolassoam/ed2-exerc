#include <iostream>
#include <fstream>
using namespace std;
#include "redblack.h"
#include "config.h"

// Metodos da classe RBNode
// Construtors
RBNode::RBNode(int key) : key(key), left(nullptr), right(nullptr), parent(nullptr), color(RED) {}

RBNode::RBNode(int key, RBNode *parent, RBNode *left, RBNode *right, bool color) : key(key), parent(parent), left(left), right(right), color(color)
{
}

RBNode::RBNode(const RBNode &other) : key(other.key), parent(other.parent), left(other.left), right(other.right), color(other.color)
{
}

RBNode::~RBNode()
{
}

int RBNode::getKey()
{
    return key;
}

RBNode *RBNode::getParent()
{
    return parent;
}

RBNode *RBNode::getLeft()
{
    return left;
}

RBNode *RBNode::getRight()
{
    return right;
}

// Cria uma arvore vermelho e preta
// Faz root aporentar a nullptr e cria um nó sentinela nil
RBTree::RBTree() : root(nullptr)
{
    nil = new RBNode(0, nullptr, nullptr, nullptr, BLACK);
}

void RBTree::insert(int key)
{
    RBNode *tmp = this->root;
    RBNode *parent = nil;
    // arvore esta vazia
    // Cria um novo nó com a chave passada como argumento
    // e insere o novo nó na raiz da árvore
    if (tmp == nullptr)
    {
        this->root = new RBNode(key, nil, nil, nil, BLACK);
        return;
    }

    // procura o nó onde a chave deve ser inserida
    while (tmp != nil)
    {
        parent = tmp;
        if (key < tmp->key)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    // cria um novo nó com a chave passada como argumento
    // e insere o novo nó na árvore
    RBNode *newNode = new RBNode(key, parent, nil, nil, RED);
    if (key < parent->key)
        parent->left = newNode;
    else
        parent->right = newNode;

    // corrige a árvore a partir do novo nó inserido
    this->insertFixUp(newNode);
}

// retorna o nó com a chave mínima da árvore
RBNode *RBTree::minimum()
{
    return minimum(this->root);
}

// retorna o nó com a chave mínima da subárvore
// enraizada no nó passado como argumento
RBNode *RBTree::minimum(RBNode *node)
{
    RBNode *tmp = node;
    if (tmp == nullptr)
        return nullptr;
    while (tmp->left != nil)
        tmp = tmp->left;
    return tmp;
}

// procura o nó com a chave máxima na arvore
RBNode *RBTree::maximum()
{
    return maximum(this->root);
}

//  procura o nó com a chave máxima na subarvore enraizada por node
RBNode *RBTree::maximum(RBNode *node)
{
    RBNode *tmp = node;
    if (tmp == nullptr)
        return nullptr;
    while (tmp->right != nil)
        tmp = tmp->right;
    return tmp;
}

// Retornar o sucessor no nó passado como argumento
RBNode *RBTree::successor(RBNode *node)
{
    if (node->right != nil)
        return minimum(node->right);
    RBNode *tmp = node->parent;
    while (tmp != nil && node == tmp->right)
    {
        node = tmp;
        tmp = tmp->parent;
    }
    return tmp;
}

//
// Pesquisa pela chave key na arvore.
// Se não encontrado, retorna sentinela nil
RBNode *RBTree::search(int key)
{
    RBNode *tmp = this->root;
    while (tmp != nil)
    {
        if (key < tmp->key)
            tmp = tmp->left;
        else if (key > tmp->key)
            tmp = tmp->right;
        else
            return tmp;
    }
    return nil;
}

// transplant substitui a subárvore enraizada
// no nó u pela subárvore enraizada no nó v, o pai do nó u tornase o pai do nó v, e o pai de u acaba ficando com v como
// seu filho adequado.
//
void RBTree::transplant(RBNode *u, RBNode *v)
{
    if (u->parent == nil)
        this->root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    v->parent = u->parent;
}

void RBTree::remove(int key)
{
    RBNode *y;
    RBNode *x;
    RBNode *z = search(key);
    if (z == nil)
        return;

    y = z;
    int y_original_color = y->color;
    if (z->left == nil)
    {
        x = z->right;
        transplant(z, z->right);
    }
    else if (z->right == nil)
    {
        x = z->left;
        transplant(z, z->left);
    }
    else
    {
        y = minimum(z->right);
        y_original_color = y->color;
        x = y->right;
        if (y->parent == z)
        {
            x->parent = y;
        }
        else
        {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }

        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
        y->color = z->color;
    }
    delete z;
    if (y_original_color == 0)
    {
        deleteFixUp(x);
    }
}

void RBTree::rotateLeft(RBNode *x)
{
    RBNode *y = x->right;
    x->right = y->left;
    if (y->left != nil)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == nil)
        this->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void RBTree::rotateRight(RBNode *x)
{
    RBNode *y = x->left;
    x->left = y->right;
    if (y->right != nil)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == nil)
        this->root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->right = x;
    x->parent = y;
}

void RBTree::print_tree(RBNode *node, const std::string &prefix, bool isLeft, std::ostream &out)
{
    if (node == nil)
        return;

    out << prefix;
    out << (isLeft ? "├──" : "└──");

    string color = node->color ? "(R)" : "(B)";
    // print the value of the node
    out << "[" << node->key << "]" << color << std::endl;

    print_tree(node->left, prefix + (isLeft ? "│   " : "    "), true, out);
    print_tree(node->right, prefix + (isLeft ? "│   " : "    "), false, out);
}

void RBTree::print()
{
#ifndef ENABLE_CLASSROOM_TESTING
    print_tree(this->root, "", true, std::cout);
#else
    print_transversal(this->root, std::cout);
#endif
    std::cout << std::endl;
}

void RBTree::print(const char *fname)
{
    std::ofstream out(fname);
#ifndef ENABLE_CLASSROOM_TESTING
    print_tree(this->root, "", true, out);
#else
    print_transversal(this->root, out);
#endif
    out << std::endl;
    out.close();
}

void RBTree::print_transversal(RBNode *node, std::ostream &out)
{
    if (node == nil)
        return;

    print_transversal(node->left, out);
    out << node->key << " (" << node->color << ") ";
    print_transversal(node->right, out);
}

// TODO: implementar o método insertFixUp
void RBTree::insertFixUp(RBNode *node)
{
    RBNode *pai = node->parent;
    RBNode *avo = pai->parent;
    while (pai->color == RED)
    {
        if (pai == avo->left)
        {
            RBNode *y = avo->right;
            if (y->color == RED)
            {
                pai->color = BLACK;
                y->color = BLACK;
                avo->color = RED;
                node = avo;
            }
            else if (node == node->parent->right)
            {
                node = node->parent;
                rotateLeft(node);
            }
            else
            {
                pai->color = BLACK;
                avo->color = RED;
                rotateRight(avo);
            }
        }
        else
        {
            RBNode *y = avo->left;
            if (y->color == RED)
            {
                pai->color = BLACK;
                y->color = BLACK;
                avo->color = RED;
                node = avo;
            }
            else if (node == node->parent->left)
            {
                node = node->parent;
                rotateRight(node);
            }
            else
            {
                pai->color = BLACK;
                avo->color = RED;
                rotateLeft(avo);
            }
        }
    }
    root->color = BLACK;
}

// TODO: implementar o método deleteFixUp
void RBTree::deleteFixUp(RBNode *node)
{
    RBNode *pai = node->parent;
    RBNode *y = nullptr;
    while ((node != root) && node->color == BLACK)
    {
        if (node == pai->left)
        {
            y = pai->right;
            if (y->color == RED)
            {
                y->color = BLACK;
                pai->color = RED;
                rotateLeft(pai);
                y = pai->right;
            }
            if ((y->left->color == BLACK) && (y->right->color == BLACK))
            {
                y->color = RED;
                node = pai;
            }
            else if (y->right->color == BLACK)
            {
                y->left->color = BLACK;
                y->color = RED;
                rotateRight(y);
                y = pai->right;
            }
        }
        else
        {
            y = pai->left;
            if (y->color == RED)
            {
                y->color = BLACK;
                pai->color = RED;
                rotateRight(pai);
                y = pai->left;
            }
            if ((y->right->color == BLACK) && (y->left->color == BLACK))
            {
                y->color = RED;
                node = pai;
            }
            else if (y->left->color == BLACK)
            {
                y->right->color = BLACK;
                y->color = RED;
                rotateLeft(y);
                y = pai->left;
            }
        }
    }
}

// TODO: implementar o destrutor
RBTree::~RBTree()
{
    deallocate(root);
    root = nil;
}

void RBTree::deallocate(RBNode *node)
{
    if(node == nil)
        return;
    deallocate(node->left);
    deallocate(node->right);

    delete node;
}
