#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStringListModel>
#include <QStringList>
#include <QStandardItemModel>
#include <QCheckBox>
#include <QItemSelectionModel>
#include <QHostInfo>
#include <QNetworkInterface>
#include <QPainter>
#include "ChangeText.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_plainTextEdit_textChanged();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_listView_clicked(const QModelIndex &index);

    void on_up_button_clicked();

    void on_down_button_clicked();

private:
    Ui::MainWindow *ui;
    ChangeText *changetext;
    QStandardItemModel *model;
    QStandardItemModel *model2;
    QStandardItem *item;
    QStandardItem *item2;
    int *list_r = new int;
};
#endif // MAINWINDOW_H
