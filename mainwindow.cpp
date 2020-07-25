#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->centralwidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionNew_triggered()
{
    file_path =" ";
    ui->textEdit->setText("");

}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionOpen_triggered()
{

    QString fileName = QFileDialog::getOpenFileName(this,"open file");
    QFile myfile {fileName};
    file_path = fileName;
    if(!myfile.open(QFile::ReadOnly | QFile::Text)){
        qDebug()<<"File not found";
        return;
    } else{
        QTextStream in(&myfile);
        QString text = in.readAll();
        ui->textEdit->setText(text);
        myfile.close();
    }
}

void MainWindow::on_actionSave_triggered()
{
    if(file_path==" "){ on_actionSave_as_triggered();
                        return; }
    QFile myfile {file_path};
    if(!myfile.open(QFile::WriteOnly | QFile::Text)){
        qDebug()<<"File not found";
        return;
    } else{
        QTextStream out(&myfile);
        QString text = ui->textEdit->toPlainText();
        out<<text;
        myfile.flush();
        myfile.close();
    }
}

void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this,"open file");
    QFile myfile {fileName};
    if(!myfile.open(QFile::WriteOnly | QFile::Text)){
        qDebug()<<"File not found";
        return;
    } else{
        QTextStream out(&myfile);
        QString text = ui->textEdit->toPlainText();
        out<<text;
        myfile.flush();
        myfile.close();
    }
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::information(this,"Info about product","This is the text editor that i have copied/made myself");

}

void MainWindow::on_actionExit_triggered()
{
    exit(0);
}
