#include "compress.h"
#include <QDebug>
#include "QMessageBox"

Compress::Compress()
{
}

void Compress::encodes(QString nameImput,QString nameOutput ) {

     //Obtem as informações do arquivo
     informationOpen.setFile(nameImput);

     // Verificar se o arquivo existi
     if (informationOpen.exists()){
         // Nome do Arquivo
             nameFile = informationOpen.fileName();
        // Tamanho do arquivo
            tamFile = informationOpen.size();




        qDebug() << nameFile << endl;
        qDebug() << tamFile << endl;
        qDebug() << nameImput << endl;
        qDebug() << nameOutput << endl;

        // Abrindo o arquivo
        file.setFileName(nameImput);

        // QIODevice - Input and output device; ReadOnly - read only -


    }else{

        showDoneMessage("Please select a file!!! ");

    }



}


void Compress::showDoneMessage(const char * msg)
{
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.setWindowTitle("Information");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}


