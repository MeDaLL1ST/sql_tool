#include "form.h"
#include "ui_form.h"
#include "form.h"
#include <QSqlError>
#include "mainwindow.h"

form::form(QWidget *parent) :  QWidget(parent),   ui(new Ui::form) {
    ui->setupUi(this);
    ui->label->setWordWrap(true);
     ui->label_5->setWordWrap(true);
     lab=new QLabel;
     ui->scrollArea->setWidget(lab);
}

form::~form(){delete ui;}

void form::conn(QString host,QString db1,QString user,QString psw){
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("DRIVER={MySQL ODBC 5.3 Unicode Driver};SERVER="+host+";DATABASE="+db1+"");
    db.setUserName(user);
    db.setPassword(psw);
    query=new QSqlQuery(db);
}

void form::on_db_conn_clicked() {
    if (db.open()){
        ui->label->setText("Success connection");
    } else {
         ui->label->setText(db.lastError().text());
    }
    db.close();
}

void form::on_db_read_clicked() {
    lab->setText("");
    QString table=ui->num_table->toPlainText();
    QString field=ui->num_field->toPlainText();
    if(field=="")
        field="*";
    if (db.open()){
       if (query->exec("SELECT "+field+" FROM "+table)) {
        while (query->next()){
        QString res = query->value(0).toString();
        lab->setText(lab->text()+" "+res);
          ui->label->setText("Success reading");
        }
       }else{
           ui->label->setText(query->lastError().text());
       }
    }
   db.close();
}

void form::on_push_num_clicked() {
   QString num=ui->num_edit->toPlainText();
   QString table=ui->num_table->toPlainText();
   QString field=ui->num_field->toPlainText();

    if (db.open()){
        if (query->exec("INSERT INTO "+table+"("+field+") VALUES("+num+")")){
            ui->label->setText("Success writing");
        }else{
           ui->label->setText(query->lastError().text());
        }
    }

db.close();
ui->num_edit->setText("");
}

void form::on_db_del_clicked() {
    QString table=ui->num_table->toPlainText();
    QString field=ui->num_field->toPlainText();
    if (db.open()){
        if (query->exec("DELETE FROM "+table+" WHERE "+field))
            ui->label->setText("Success deleting");
        else
            ui->label->setText(query->lastError().text());
    }
    db.close();
}

void form::on_push_clr_clicked() {
     ui->label->setText("");
     ui->num_edit->setText("");
     lab->setText("");
     ui->num_field->setText("");
     ui->num_table->setText("");
}

