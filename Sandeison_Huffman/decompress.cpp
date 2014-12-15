#include "decompress.h"
#include <QDebug>
#include "QMessageBox"

Decompress::Decompress()
{
}

void Decompress::encodes(QString nameImput,QString nameOutput ) {

     //Obtem as informações do arquivo
     informationOpen.setFile(nameImput);

     // Verificar se o arquivo existi
     if (informationOpen.exists()){

        //Leitura do arquivo
        readInput(nameImput);


        //Gravação do Arquivo
        writeFile(nameOutput);



    }else{

        showDoneMessage("Please select a file!!! ");

    }


}


//Exibe as mensagens
void Decompress::showDoneMessage(const char * msg)
{
    QMessageBox msgBox;
    msgBox.setText(msg);
    msgBox.setWindowTitle("Information");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

// Abre o arquivo e faz uma copia para o newFile
void Decompress::readInput(QString nameImput)
{

    file.setFileName(nameImput);
    if(file.open (QIODevice::ReadOnly))
    {
        newFile = file.readAll();
    }

    file.close();
}





// Cria o novo arquivo e grava
void Decompress::writeFile(QString nameOutput)
{
    file.setFileName(nameOutput);
    if (file.open (QIODevice::WriteOnly)){
        file.write(newFile);
    }

    file.flush();
    file.close(); // Closes the file
}
