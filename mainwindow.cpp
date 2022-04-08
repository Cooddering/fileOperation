#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qfile.h"
#include "qdir.h"
#include "QFileDialog"
#include "QMessageBox"
#include "QStandardPaths"
#include "QComboBox"
#include "QDebug"
#include "QProgressDialog"
#include "QMimeDatabase"
#include "QWidget"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButtonOpen_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Save Adres Blok"), "", tr("All Files (*.);; Text Files (*.txt);; XML Files (*.xml)"));
        QFile openFile(fileName);
        openFile.open(QIODevice::ReadOnly);
        QByteArray content = openFile.readAll();
        ui->textEditAdres->setText(QString(content));
        //merhsbsbs
}
void MainWindow::on_pushButtonSave_clicked()
{
    QString path;
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text File"), path, tr("Text Files (*.txt)"));
       if (fileName != "")
       {
           QFile file(QFileInfo(fileName).absoluteFilePath());

           if (file.exists())
           {
               QMessageBox::StandardButton chosenButton
                   = QMessageBox::warning(this, tr("File exists"), tr("The file already exists. Do you want to overwrite it?"),
                       QMessageBox::Ok | QMessageBox::Cancel,
                       QMessageBox::Cancel);
               if (chosenButton != QMessageBox::Ok)
               {
                   return;
               }
           }
           if (!file.open(QIODevice::WriteOnly))
           {
               QMessageBox::critical(this, tr("Error"), tr("Failed to save file"));
               return;
           }

           QString text = ui->textEditAdres->toPlainText();
           QTextStream out(&file);
           out << text;
           file.close();
       }
}
void MainWindow::on_pushButtonLoading_clicked()
{
    filepathAndName = QFileDialog::getOpenFileName(this, tr("Save Adres Blok"), "", tr("Text Files (*.txt);; All Files (*.);;  XML Files (*.xml)"));
         QFile openFile(filepathAndName);
         openFile.open(QIODevice::ReadOnly);
         QByteArray content = openFile.readAll();
         ui->textEditAdres->setText(QString(content));
         ui->textEditName->setText(filepathAndName);
}
void MainWindow::on_pushButtonEdit_clicked()
{
    QString path;
    if(ui->textEditAdres->toPlainText() == " "){
      MainWindow::on_pushButtonLoading_clicked();
    }else{
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save Text File"), path, tr("Text Files (*.txt)"));
           if (fileName != "")
           {
               QFile file(QFileInfo(fileName).absoluteFilePath());

               if (file.exists())
               {
                   QMessageBox::StandardButton chosenButton
                       = QMessageBox::warning(this, tr("File exists"), tr("The file already exists. Do you want to overwrite it?"),
                           QMessageBox::Ok | QMessageBox::Cancel,
                           QMessageBox::Cancel);
                   if (chosenButton != QMessageBox::Ok)
                   {
                       return;
                   }
               }
               if (!file.open(QIODevice::WriteOnly))
               {
                   QMessageBox::critical(this, tr("Error"), tr("Failed to save file"));
                   return;
               }

               QString text = ui->textEditAdres->toPlainText();
               QTextStream out(&file);
               out << text;
               file.close();
           }
    }
}
void MainWindow::on_pushButtonAdd_clicked()
{

    filepathAndName = QFileDialog::getOpenFileName(this, tr("Save Adres Blok"), "", tr("All Files (*.);; Text Files (*.txt);; XML Files (*.xml)"));
    QFile openFile(filepathAndName);
    openFile.open(QIODevice::ReadOnly);
    QByteArray content = openFile.readAll();
    ui->textEditName->setText(filepathAndName);
    ui->textEditAdres->setText(QString(content));
    // ui->comboBox->addItem(filepathAndName);
    comboboxMapName[filepathAndName] = content;
    ui->comboBox->addItem(filepathAndName);

}
void MainWindow::on_pushButtonNext_clicked()
{


}
void MainWindow::on_pushButtonPrevious_clicked()
{
    QMapIterator<QString, QString>Iter(comboboxMapName);
    while (Iter.hasPrevious()) {
    Iter.previous();

    ui->textEditName->setText(comboboxMapName[filepathAndName]);

}
}
void MainWindow::on_pushButtonRead_clicked()
{
     filepathAndName = QFileDialog::getOpenFileName(this, tr("Save Adres Blok"), "", tr("All Files (*.);; Text Files (*.txt);; XML Files (*.xml)"));
     QFile openFile(filepathAndName);
     openFile.open(QIODevice::ReadOnly);
     QByteArray content = openFile.readAll();
     ui->textEditAdres->setText(QString(content));
     ui->textEditName->setText(filepathAndName);
}
void MainWindow::on_pushButtonRemove_clicked()
{
    ui->textEditName->clear();
    ui->textEditAdres->clear();
}

void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    ui->textEditAdres->setText(comboboxMapName[arg1]);
}
