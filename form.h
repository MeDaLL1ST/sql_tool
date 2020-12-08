#ifndef FORM_H
#define FORM_H
#include <QWidget>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlDriver>
#include <QSqlDriverPlugin>
#include <QLabel>
#include <QString>

namespace Ui {
class form;
}

class form : public QWidget {
    Q_OBJECT

public:
    explicit form(QWidget *parent = nullptr);
    ~form();

signals:
    void firstWindow();

public slots:
    void on_db_conn_clicked();
    void on_db_read_clicked();
    void on_push_num_clicked();
    void conn(QString host,QString db1,QString user,QString psw);

private slots:
    void on_push_clr_clicked();
    void on_db_del_clicked();

private:
    Ui::form *ui;
    QSqlDatabase db;
    QSqlQuery *query;
     QLabel *lab;
};

#endif // FORM_H
