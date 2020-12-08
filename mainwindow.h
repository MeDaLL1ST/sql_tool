#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "form.h"
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class lbl_osn; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
    void get_host(QString host_s,QString db_s,QString user_s,QString psswd_s);
private slots:
    void on_clr_clicked();
    void on_go_to_clicked();
    void on_push_ab_clicked();

private:
    Ui::lbl_osn *ui;
    form *sWin;
};
#endif // MAINWINDOW_H
