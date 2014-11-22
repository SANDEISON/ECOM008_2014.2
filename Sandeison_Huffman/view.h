#ifndef VIEW_H
#define VIEW_H

#include <QMainWindow>
#include <compress.h>
#include <decompress.h>

namespace Ui {
class View;
}

class View : public QMainWindow
{
    Q_OBJECT

public:
    explicit View(QWidget *parent = 0);
    ~View();


    Compress conexao_compress; // Conexão, envia os endereços do arquivo abrir e do salvar
    Decompress conexao_decompress; // conexao, envia os endereços do arquivo abrir e do salvar


    // Definindo o objeto para salvar o endereço do arquivo
    QString fileAddress;

    // Definindo o objeto para salvar o endereço onde o arquivo sera salvo.
    QString filesave;

private slots:
    void on_Search_clicked();

    void on_Cancel_clicked();

    void on_Save_clicked();

    void on_Decompress_clicked();

    void on_Compress_clicked();

private:
    Ui::View *ui;
};

#endif // VIEW_H
