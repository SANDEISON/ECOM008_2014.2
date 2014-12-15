#include "avltree.h"
#include <QDebug>
#include <node.h>


// Construção e Pesquisa

// Construtor
AvlTree::AvlTree()
{
    // Inicializamos a raíz com null.
    this->root = NULL;
}


// Destrutor
AvlTree::~AvlTree()
{
    this->Clear();
}

// Limpa a árvore (remove todos seus nós)
void AvlTree::Clear()
{
    // O destrutor de TreeNode cuidará
    //  de destruir todas as subárvores.
    delete root;
    this->root = NULL;
}



// Procura um item na árvore, realizando pesquisa binária.
//   aceita como parâmetro uma string como chave de busca.
//   retorna o item procurado ou NULL caso não o encontre.
bool AvlTree::Search(QByteArray chave, int value)
{
    // Começamos com a raiz
    treenode* current = this->root;

    // Como, por definição, a árvore AVL está
    //  ordenada, utilizamos a pesquisa binária




    while (current != NULL)
    {
        // Comparamos
        if (chave > current->Key)
        {
            // O valor está mais à direita
            current = current->Subtree[RIGHT];
        }
        else if (chave < current->Key)
        {
            // O valor está mais à esquerda
            current = current->Subtree[LEFT];
        }
        else
        {
            // Achamos, retornamos o item
            value = current->Value;
            return true;
        }
    }

    // O valor não estava na árvore
    return false;
}






// Rotacionando

// Realiza uma rotação simples numa determinada direção.
//  aceita como parâmetro um nó onde a operação será efetuada
//  e uma direção (esquerda ou direita) para realizar a rotação.
void AvlTree::rotateOnce(treenode*& node, Direction dir)
{
    int opposite = this->opposite(dir);

    treenode* child = node->Subtree[dir];
    node->Subtree[dir] = child->Subtree[opposite];
    child->Subtree[opposite] = node;

    node = child;
}

// Realiza uma rotação dupla numa determinada direção.
//  aceita como parâmetro um nó onde a operação será efetuada
//  e uma direção (esquerda ou direita) para realizar a rotação.
void AvlTree::rotateTwice(treenode*& node, Direction dir)
{
    int opposite = this->opposite(dir);

    treenode* child = node->Subtree[dir]->Subtree[opposite];
    node->Subtree[dir]->Subtree[opposite] = child->Subtree[dir];
    child->Subtree[dir] = node->Subtree[dir];
    node->Subtree[dir] = child;
    child = node->Subtree[dir];
    node->Subtree[dir] = child->Subtree[opposite];
    child->Subtree[opposite] = node;

    node = child;
}






// Retorna a direção oposta à direção dada
inline Direction AvlTree::opposite(Direction dir)
{
    return (dir == RIGHT) ? LEFT : RIGHT;
}




                            //   Balanceando



// Atualiza os fatores de balanceamento após uma rotação
void AvlTree::updateBalance(treenode* node, Direction dir)
{
    int opposite = this->opposite(dir);

    int bal = node->Subtree[dir]->Subtree[opposite]->Balance;

    // Se o fator está pesado no mesmo lado
    if (bal == dir)
    {
        node->Balance = EQUAL;
        node->Subtree[dir]->Balance = opposite;
    }

    // Se o fator está pesado do lado oposto
    else if (bal == opposite)
    {
        node->Balance = dir;
        node->Subtree[dir]->Balance = EQUAL;
    }

    else // O fator de balanceamento está igual
    {
        node->Balance = node->Subtree[dir]->Balance = EQUAL;
    }

    node->Subtree[dir]->Subtree[opposite]->Balance = EQUAL;
}




// Efetua o rebalanceamento após uma operação de inserção
void AvlTree::rebalanceInsert(treenode*& node, Direction dir,
                              bool& hChanged)
{
    int opposite = this->opposite(dir);

    // Se o fator de balanceamento do nó era
    //  igual a direção em que houve a inserção,
    if (node->Balance == dir) // (ou seja o nó foi inserido
    {                        //  na subárvore de maior altura
        // Temos 2 casos:
        if (node->Subtree[dir]->Balance == dir)
        {
            node->Subtree[dir]->Balance = 2;
            node->Balance = EQUAL;

            // Precisamos fazer uma rotação
            rotateOnce(node, dir);
        }
        else // Seu filho estava equilibrado ou
        {    //  pendendo para o lado oposto,

            updateBalance(node, dir);
            rotateTwice(node, dir);
        }

        hChanged = false;
    }

    // Já se foi exatamente o oposto,
    else if (node->Balance == opposite)
    {
        // O nó agora está balanceado
        node->Balance = 2;
        hChanged = false;
    }

    else // Se não, o nó já estava equilibrado
    {
        // e agora seu equilibrio foi deslocado.
        node->Balance = dir;
    }
}

// Efetua o rebalanceamento após uma operação de remoção
void AvlTree::rebalanceRemove(treenode*& node, Direction dir,
                              bool& hChanged)
{
    Direction opposite = this->opposite(dir);

    // Se o fator de balanceamento do nó era
    //  igual a direção em que houve a remoção,
    if (node->Balance == dir) // (ou seja, o nó foi removido
    {                        //da subárvore de maior altura)

        // o nó agora está balanceado.
        node->Balance = EQUAL;
    }

    // Já se era o oposto,
    else if (node->Balance == opposite)
    {
        // Temos 3 casos:
        if (node->Subtree[opposite]->Balance == opposite)
        {
            // Se o filho do outro lado estava "mais pesado"
            //  do lado oposto, então
            node->Subtree[opposite]->Balance = EQUAL;
            node->Balance = EQUAL;
            rotateOnce(node, opposite);
        }
        else if (node->Subtree[opposite]->Balance == EQUAL)
        {
            // Se o filho do outro lado estava equilibrado,
            node->Subtree[opposite]->Balance = dir;
            rotateOnce(node, opposite);
        }
        else
        {
            // Se o filho do outro lado estava "mais pesado"
            //  do lado mais próximo de onde foi feita a inserção,
            updateBalance(node, opposite);
            rotateTwice(node, opposite);
        }

        hChanged = false;
    }
    else
    {
        node->Balance = opposite;
        hChanged = false;
    }
}




            //Inserindo




// Insere um novo item na árvore, aceitando seus componentes
//   palavra (chave) e origem (dado)
void AvlTree::Insert(QByteArray chave, int value)
{
    bool hChanged = false; // Para passagem por referência

    // Chamamos o método recursivo para realizar a operação
    this->insert(chave, value, this->root, hChanged);
}


// Insere um novo item na árvore (recursivo)
void AvlTree::insert(QByteArray chave, int value,
                        treenode*& node, bool& hChanged)
{
    // Se o nó atual é nulo,
    if (node == NULL)
    {
        // é aqui mesmo onde vamos inserir
        node = new treenode(chave, value);

        // marcamos que a altura mudou, é
        //  preciso chegar o balanceamento
        hChanged = true;
    }

    else if (node->Key == chave)
    {
        // A informação já estava na árvore
        return;
    }

    else // Ainda não chegamos onde queríamos
    {
        // Prosseguimos com a pesquisa binária
        Direction dir = (chave > node->Key) ? RIGHT : LEFT;

        hChanged = false; // preparamos e chamamos recursão
        insert(chave, value, node->Subtree[dir], hChanged);


        if (hChanged) // Se a altura mudou,
        {
            // Efetuamos o rebalanceamento
            this->rebalanceInsert(node, dir, hChanged);
        }
    }
}



            //Removendo



// Remove um item da árvore a partir de sua chave (palavra)
//  retorna true caso o item tenha sido removido com sucesso,
//  falso caso o item não tenha sido encontrado na árvore.
bool AvlTree::Remove(QByteArray palavra)
{
    bool hChanged = false; // para passagem por referência

    // Chamamos o método recursivo para realizar a operação.
    return this->remove(palavra, this->root, hChanged);
}

// Remove um item da árvore a partir de sua chave (palavra)
//  retorna true caso o item tenha sido removido com sucesso,
//  falso caso o item não tenha sido encontrado na árvore. (recursivo)
bool AvlTree::remove(QByteArray chave, treenode*& node,
                    bool& hChanged)
{
   // debug("Tree: remocao recursiva: " + chave + ", " + node->Key);
    bool success = false;

    // O nó não foi encontrado
    if (node == NULL)
    {
        hChanged = false;
        return false;
    }

    // Achamos o nó
    else if (chave == node->Key)
    {

        // Se o nó tiver ambos os filhos
        if (node->Subtree[LEFT] != NULL && node->Subtree[RIGHT] != NULL )
        {
            // Encontraremos um substituto para o nó
            treenode* substitute = node->Subtree[LEFT];

            // Navegamos até o nó mais a direita da subárvore da esquerda
            while (substitute->Subtree[RIGHT] != NULL)
            {
                substitute = substitute->Subtree[RIGHT];
            }

            // Trocamos suas informações <chave,valor>
            node->Key   = substitute->Key;

            // Chamamos recursão para remover o nó
            success = remove(node->Key, node->Subtree[LEFT], hChanged);

            if (hChanged) // Se a altura mudou,
            {
                // Rebalanceamos
                rebalanceRemove(node, LEFT, hChanged);
            }
        }

        else // O nó tem apenas um ou nenhum filho
        {
            // Preparamos para apagar o nó
            treenode* temp = node;

            // Vemos se um dos seus filhos é diferente de NULL
            Direction dir = (node->Subtree[LEFT] == NULL) ? RIGHT : LEFT;

            // Substituímos o nó por um dos seus filhos
            node = node->Subtree[dir];

            // Deletamos o nó (lembramos que devemos
            //  setar os filhos para null para que o
            //  destrutor não inicie a destrução em cadeia
            temp->Subtree[LEFT]  = NULL;
            temp->Subtree[RIGHT] = NULL;
            delete temp;

            // A altura mudou, propagamos a mudança
            hChanged = true;
        }

        // Retornamos verdadeiro, achamos o nó
        //  e a operação foi concluída
        return true;
    }

    else // Ainda não encontramos o nó
    {
        // Continuamos procurando (pesquisa binária)
        Direction dir = (chave > node->Key) ? RIGHT : LEFT;

        if (node->Subtree[dir] != NULL)
        {
            // Recursão para a direção onde deverá estar a chave
            success = this->remove(chave, node->Subtree[dir], hChanged);
        }
        else
        {
            // O nó não está na árvore
            hChanged = false;
            return false;
        }

        if (hChanged) // Se a altura mudou,
        {
            // Rebalanceamos
            this->rebalanceRemove(node, dir, hChanged);
        }

        // Retornamos informando se achamos o nó ou não
        return success;
    }
}






// Exibe a árvore na tela utilizando arte ASCII. Árvores
//  muito grandes ou esparsas terão dificuldade para
//  caberem no console.
/*/void AvlTree::Print()
{
    // Verificamos se há árvore
    if (this->root != NULL)
    {
        // Instanciamos um novo objeto da classe AsciiTreeView
        AsciiTreeView treeView(this);

        // Solicitamos a impressão.
        treeView.Print();
    }
    else // A árvore está vazia
    {
        cout << "Arvore vazia" << endl;
    }
}
*/






// Imprime detalhes sobre cada nó da árvore,
//  percorrendo-a em ordem.
void AvlTree::PrintNodeDetails()
{
    this->printNodeDetails(this->root);
}

// Imprime detalhes sobre cada nó da árvore,
//  percorrendo-a em ordem (recursivo).
void AvlTree::printNodeDetails(treenode* node)
{

    if (node != NULL)
    {
        this->printNodeDetails(node->Subtree[LEFT]);
        qDebug() << "Node Key: "  << node->Key    << endl;
        qDebug() << "- Origem: "  << node->Value   << endl;
        qDebug() << "- Balance: " << node->Balance << endl;
        if (node->Subtree[LEFT] != NULL)
        qDebug() << "- Left: "  << node->Subtree[LEFT]->Key << endl;
        if (node->Subtree[RIGHT] != NULL)
        qDebug() << "- Right: " << node->Subtree[RIGHT]->Key << endl;

        qDebug() << endl;
        this->printNodeDetails(node->Subtree[RIGHT]);
    }
}

