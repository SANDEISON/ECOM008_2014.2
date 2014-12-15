#include "view.h"
#include "ui_view.h"
#include <QFileDialog>

View::View(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::View)
{
    ui->setupUi(this);
}

View::~View()
{
    delete ui;
}

// Função para selecionar arquivo.
void View::on_Search_clicked()
{
    fileAddress = QFileDialog::getOpenFileName(
                this,
                tr("Open File"),
                "C:://",
                "All Files (*.*);;Huffman(*.huff);;Text File (*.txt)"
                );
    ui->lineEdit_Search->setText(fileAddress);

    //Obtem as informações do arquivo
    info.setFile(fileAddress);


    if(info.suffix()!= "huff"){

        // Desabilita o botão de compresão
        ui->Decompress-> setEnabled(false);
    }

}

// Função para salvar o arquivo.
void View::on_Save_clicked()
{
    filesave = QFileDialog::getSaveFileName();
    filesave+= ".huff";
    ui->lineEdit_Save->setText(filesave);
}



//Função do Botão Cancelar
void View::on_Cancel_clicked()
{
    close();
}


// descompresão do arquivo
void View::on_Decompress_clicked()
{
    conexao_decompress.encodes(fileAddress,filesave);
}

// compresão do arquivo
void View::on_Compress_clicked()
{

    conexao_compress.encodes(fileAddress,filesave);
}





