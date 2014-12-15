#ifndef TREENODE_H
#define TREENODE_H

#include <QString>




// Enumeração para acesso às subárvores e direção
//  de procura da pesquisa binária. Serve também
//  para indicar o fator de balanceamento dos nós.
enum Direction
{
    // Indica que a subárvore esquerda tem maior altura,
    // Que devemos caminhar para a esquerda na pesquisa
    // ou que queremos acessar a Subárvore da esquerda.
    LEFT  = 0,

    // Indica que a subárvore direita tem maior altura,
    // Que devemos caminhar para a direita na pesquisa
    // ou que queremos acessar a Subárvore da direita.
    RIGHT = 1,

    // Indica que as subárvore tem alturas iguais.
    // Não é válida nos outros contextos.
    EQUAL = 2,
};


class treenode
{

    public:
        // Constrói um novo nó a partir de um item e uma chave
        treenode(QByteArray chave, int value)
        {
            this->Key   = chave;
            this->Value = value;
            this->Subtree[LEFT]  = NULL;
            this->Subtree[RIGHT] = NULL;
            this->Balance = EQUAL;
        }

        // Destrutor
        ~treenode()
        {
            // Note que destruição de um nó iniciará uma operação
            //   em cadeia em todos os seus filhos. Caso um dos
            //   filhos não deva ser apagado, deve-se setar NULL
            //   em sua referência antes de destruir este nó.
            delete this->Subtree[LEFT];
            delete this->Subtree[RIGHT];
        }


        // Balanceamento do nó
        unsigned short Balance;

        // Filhos da árvore
        // As subárvores direita e esquerda devem ser acessadas
        // utilizando apenas ->Subtree[LEFT] e ->Subtree[RIGHT]
        treenode* Subtree[2];

        // Arranjo <chave, valor>
        //  associado ao nó
        QByteArray Key;
        int Value;
};





#endif // TREENODE_H
