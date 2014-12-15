#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include<QString>
#include <QFileInfo>
#include <QFile>



class Decompress
{
public:
    Decompress();

    //Metodo que recebe os endereços de entrada e saida
    void encodes(QString nameInput, QString nameOutput);

    //Metodo para Leitura o arquivo
    void readInput(QString nameInput);

    //Metodo para escrita do arquivo
    void writeFile(QString nameOutput);

    //Metodo para Mensagens.
    void showDoneMessage(const char * msg);

    //Objeto para buscar informação do arquivo
    QFileInfo informationOpen;

    // Objeto para manipular os dados
    QFile file;

    // Objeto para criar o arquivo novo
    QByteArray newFile;


};

#endif // DECOMPRESS_H
