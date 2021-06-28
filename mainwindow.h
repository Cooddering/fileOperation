#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QPushButton"
#include "QVector"
#include <QMap>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

public:


        QString filepath;
        QString filepathAndName;
        QStringList values;
        QMap<QString, QString> comboboxMapName ;


private slots:
    void on_pushButtonRemove_clicked();
    void on_pushButtonOpen_clicked();
    void on_pushButtonSave_clicked();
    void on_pushButtonLoading_clicked();
    void on_pushButtonEdit_clicked();
    void on_pushButtonAdd_clicked();
    void on_pushButtonRead_clicked();
    void on_pushButtonNext_clicked();
    void on_pushButtonPrevious_clicked();
    void on_comboBox_currentTextChanged(const QString &arg1);

private:
     QStringList findFiles(const QStringList &files, const QString &text);
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
