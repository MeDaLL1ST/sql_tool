#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMainWindow>
#include <QLabel>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) , ui(new Ui::lbl_osn) {
    ui->setupUi(this);
    sWin=new form();
    connect(this, SIGNAL(get_host(QString,QString,QString,QString)), sWin, SLOT(conn(QString,QString,QString,QString)));
}

MainWindow::~MainWindow() {delete ui;}

void MainWindow::on_clr_clicked() {
    ui->host_edit->setText("");
    ui->db_edit->setText("");
    ui->user_edit->setText("");
    ui->lineEdit->setText("");
}

void MainWindow::on_go_to_clicked() {
    QString hst=ui->host_edit->toPlainText();
    QString dtb=ui->db_edit->toPlainText();
    QString usr=ui->user_edit->toPlainText();
    QString psw=ui->lineEdit->text();
    if (hst==""||dtb==""||usr==""||psw==""){
        ui->label_5->setText("Fill in all fields");
    } else {
   emit get_host(hst,dtb,usr,psw);
   sWin->show();
   this->close();
    }
}

void MainWindow::on_push_ab_clicked() {
    QMessageBox::about(this, "About this program", "This program is made for quick and handy MySql database management.\nTo connect correctly, enter the database address,database name,\n and password with the user.After connecting, click the connect\n button again to confirm the connection.The program will display all connection errors in the top line.\nDon't forget that the problem can easily be related to the database itself,not the application.\nDeveloper's email address:nikitakorablev@gmail.com");
}
