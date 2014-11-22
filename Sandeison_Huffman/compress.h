#ifndef COMPRESS_H
#define COMPRESS_H

#include<QString>
#include <QFileInfo>



class Compress
{
public:
    Compress();

     //Metodo que recebe os endereços de entrada e saida
     void encodes(QString nameInput, QString nameOutput);

    //Objeto para buscar informação do arquivo
    QFileInfo informationOpen;

    // Informações do arquivo    
    QString nameFile; // Nome do Arquivo
    int tamFile; // tamanho do file

    //Metodo para Mensagens.
    void showDoneMessage(const char * msg);

};

#endif // COMPRESS_H
