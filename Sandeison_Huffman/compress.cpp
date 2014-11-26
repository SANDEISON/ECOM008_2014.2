#include "compress.h"
#include <QDebug>
#include "QMessageBox"

Compress::Compress( )
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
            tamNameFile = nameFile.size();

        //Leitura do arquivo
        readInput(nameImput);






        //Gravação do Arquivo
        writeFile(nameOutput);



    }else{

        showDoneMessage("Please select a file!!! ");

    }


}

//Exibe as mensagens
void Compress::showDoneMessage(const char * msg)
{
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.setWindowTitle("Information");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

// Abre o arquivo e faz uma copia para o newFile
void Compress::readInput(QString nameImput)
{

    file.setFileName(nameImput);
    if(file.open (QIODevice::ReadOnly))
    {
        newFile = file.readAll();
    }

    file.close();
}

// Cria o novo arquivo e grava
void Compress::writeFile(QString nameOutput)
{
    file.setFileName(nameOutput);
    if (file.open (QIODevice::WriteOnly)){
        qDebug() << "File was written" << endl << endl;
        file.write(newFile);
    }

    file.flush();
    file.close(); // Closes the file
}


void Compress::frequencia(){

    int frequency[256];

    for(int i = 0; i < 256; i++){
        frequency[i] = newFile.count(i);
        qDebug () << frequency[i];
     }


}
