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

        frequencia();

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
        file.write(newFile);
    }

    file.flush();
    file.close(); // Closes the file



}






// Verifica a frequencia do arquivo
void Compress::frequencia(){

    int frequency[256];

    for(int i = 0; i < 256; i++){
        frequency[i] = newFile.count(i);
     }

    recebelista(frequency);

}





// Passa a frequencia para a arvore
void Compress::recebelista(int  vetor[]){

    for(int i = 0; i < 256; ++i)
    {
        if(vetor[i])
        {


            Node * tmp = new Node;
            tmp->frequency = vetor[i];
            tmp->character.append(i);
            inserearvore.Insert(tmp->character,tmp->frequency);



            lista << * tmp;
        }
    }


    inserearvore.PrintNodeDetails();



    //sortList();

}



/*
// Ordena a lista
void Compress :: sortList(){

    bool swapped = true;

    if(lista.size() == 1){
        return;

    }

    while(swapped)
    {
        swapped = false;
        for(int i = 1; i < lista.size(); ++i)
            if(lista[i].frequency < lista[i - 1].frequency)
            {
                lista.swap(i, i-1);
                swapped = true;
            }

    }

    for(int i=0; i<lista.size(); i++){
       qDebug () <<  lista[i].frequency;
       qDebug () <<  lista[i].character;
    }

    arvore();



}

*/











