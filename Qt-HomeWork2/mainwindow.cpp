#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    changetext = new ChangeText();
    if(!changetext) close();

    model = new QStandardItemModel(this);
    ui->listView->setModel(model);
    model->appendRow(new QStandardItem(QIcon("../Qt-HomeWork2/icos/cpp.ico"), "C++"));
    model->appendRow(new QStandardItem(QIcon("../Qt-HomeWork2/icos/python.ico"), "Python"));
    model->appendRow(new QStandardItem(QIcon("../Qt-HomeWork2/icos/java.ico"), "Java"));
    model->appendRow(new QStandardItem(QIcon("../Qt-HomeWork2/icos/.net.ico"), "C#"));
    model->appendRow(new QStandardItem(QIcon("../Qt-HomeWork2/icos/php.ico"), "PHP"));
    model->appendRow(new QStandardItem(QIcon("../Qt-HomeWork2/icos/js.ico"), "JavaScript"));

    model2 = new QStandardItemModel(this);
    ui->listView_2->setModel(model2);
    model2->appendRow(new QStandardItem("PC Name: " + QHostInfo::localHostName()));
    QString addr;
    const QHostAddress &localhost = QHostAddress(QHostAddress::LocalHost);
    for (const QHostAddress &address: QNetworkInterface::allAddresses()) {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != localhost)
             addr = address.toString();
    }
    model2->appendRow(new QStandardItem("IP addr: " + addr));
    foreach(QNetworkInterface netInterface, QNetworkInterface::allInterfaces())
        {
            if (!(netInterface.flags() & QNetworkInterface::IsLoopBack))
                model2->appendRow(new QStandardItem("MAC addr: " + netInterface.hardwareAddress()));
            break;
        }
}

MainWindow::~MainWindow()
{
    if(changetext){
        delete changetext;
        changetext = nullptr;
    }
    delete list_r;
    delete model;
    delete model2;
    delete item;
    delete item2;
    delete ui;
}


void MainWindow::on_plainTextEdit_textChanged()
{
    QString str = ui->plainTextEdit->toPlainText();
    if (changetext->change(str))
    {
        ui->plainTextEdit->setPlainText(changetext->getText());
    }
}


void MainWindow::on_pushButton_clicked()
{
    QString language_name = ui->l_name->text();
    model->appendRow(new QStandardItem(QIcon("../Qt-HomeWork2/icos/prog_lang.ico"), language_name));
}


void MainWindow::on_pushButton_2_clicked()
{
    model->removeRow(*list_r);
}


void MainWindow::on_checkBox_stateChanged(int arg1)
{

    if(arg1){
        ui->listView->setViewMode(QListView::IconMode);
    }
    else{
        ui->listView->setViewMode(QListView::ListMode);
    }
}


void MainWindow::on_listView_clicked(const QModelIndex &index)
{
    item = model->itemFromIndex(index);
    *list_r = item->row();
}

void MainWindow::on_up_button_clicked()
{
    if(*list_r != 0){
        item = model->takeItem(*list_r);
        model->removeRow(*list_r);
        item2 = model->takeItem((*list_r)-1);
        model->removeRow(*list_r-1);
        model->insertRow((*list_r)-1,item);
        model->insertRow(*list_r,item2);
    }
}


void MainWindow::on_down_button_clicked()
{
    if(*list_r != model->rowCount()-1){
        item = model->takeItem(*list_r);
        item2 = model->takeItem((*list_r)+1);
        model->removeRow(*list_r);
        model->removeRow((*list_r));
        model->insertRow(*list_r,item2);
        model->insertRow((*list_r)+1,item);

    }
}
