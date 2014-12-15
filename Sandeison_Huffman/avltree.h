#ifndef AVLTREE_H
#define AVLTREE_H

#include <Qfile>
#include <QString>
#include <treenode.h>




// Classe Árvore AVL
//  Fornece métodos para criar e manipular Árvores AVL.
//  Trabalha com nós cuja chave e informação são do tipo string,
//  mas a classe poderia ser facilmente adaptada para trabalhar
//  com templates. Mantida nesta forma para uma maior didática.
class AvlTree
{

    public:

        // Construtor e destrutor padrões
        AvlTree();
        ~AvlTree();

        // Insere uma nova entrada na árvore, aceitando
        //   um arranjo chave e valor como parâmetros
        void Insert(QByteArray key, int value);

        // Remove uma entrada da árvore, aceitando
        //   um arranjo chave e valor como parâmetros
        //   Retorna falso caso a palavra não exista.
        bool Remove(QByteArray value);

        // Procura um valor na árvore, aceitando uma  chave como
        //  parâmetro. Se encontrado, o valor será armazenado na
        //  variável value e retornado como referência. Retorna
        //  verdadeiro se encontrar o valor, falso caso contrário.
        bool Search(QByteArray key,int value);

        // Limpa a árvore
        void Clear();

        // Exibe a árvore na tela
        void Print();
        void PrintNodeDetails();

        // Carrega uma árvore do arquivo, aceitando o caminho do arquivo
        //  (path) como parâmetro. Caso esta não exista, retorna NULL
        static AvlTree* Load(const char* path);

        // Armazena uma árvore em arquivo, aceitando o caminho do arquivo
        //  (path) como parâmetro. O arquivo é armazenado em pós-ordem.
        bool Save(const char* path);


        bool bitBusca(QByteArray key,int value);



    private:

        // Raiz da árvore
        treenode* root;


        // Rotações
        void rotateTwice(treenode*& node, Direction dir);
        void rotateOnce (treenode*& node, Direction dir);


        // Rebalanceamentos
        void updateBalance  (treenode* tree,  Direction dir);
        void rebalanceInsert(treenode*& tree, Direction dir,
                              bool& hChanged);
        void rebalanceRemove(treenode*& tree, Direction dir,
                              bool& hChanged);


        // Inserção e remoção recursivos
        void insert(QByteArray key, int value,
                    treenode*& node, bool& hChanged);
        bool remove(QByteArray key, treenode*& node, bool& hChanged);


        // Métodos auxiliares
        //bool save(ofstream& stream, treenode* node);
        void printNodeDetails(treenode* node);
        inline Direction opposite(Direction dir);
};








#endif // AVLTREE_H
