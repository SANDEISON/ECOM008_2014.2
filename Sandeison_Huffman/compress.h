#ifndef COMPRESS_H
#define COMPRESS_H

#include<QString>
#include <QFileInfo>
#include <QFile>
#include "node.h"


class Compress
{
public:
    Compress();

     //Metodo que recebe os endereços de entrada e saida
     void encodes(QString nameInput, QString nameOutput);

     //Metodo para çeitura o arquivo

     void readInput(QString nameInput);

     //Metodo para escrita do arquivo
     void writeFile(QString nameOutput);

     //Metodo para Mensagens.
     void showDoneMessage(const char * msg);

    void frequencia();

    //Objeto para buscar informação do arquivo
    QFileInfo informationOpen;

    // Informações do arquivo    
    QString nameFile; // Nome do Arquivo
    int tamNameFile; // tamanho do  nome do arquivo


    // Objeto para manipular os dados
    QFile file;

    // Objeto para criar o arquivo novo
    QByteArray newFile;

    QList<Node> lista;




};

#endif // COMPRESS_H
