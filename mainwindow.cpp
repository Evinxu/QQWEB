//************//QQ web*************//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QDesktopWidget>
#include <QString>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);   //flash enable

    QString url = "https://w.qq.com/";

    QQweb = new SWebEngineView(this);
    QUrl QQurl = QUrl(url);
    QQweb->load(QQurl);
    QQweb->addItemUrl(QQurl);
    QQweb->show();

    this->setMaximumSize(1060,655.08);   //0.618
    this->setMinimumSize(1060,655.08);
    QQweb->setMaximumSize(1060,655.08);
    QQweb->setMinimumSize(1060,655.08);
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);

    QObject::connect(QQweb->page()->profile(),&QWebEngineProfile::downloadRequested,this,&MainWindow::downloadJumpSlot);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    QQweb->resize(this->size());
}

///////////////**************//////////////////下载
void MainWindow::downloadJumpSlot(QWebEngineDownloadItem*startdownload)
{
    qDebug()<<"download test!";
    startdownload->accept();
    QObject::connect(startdownload,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(setCurrentProgressSlot(qint64,qint64)));
}

void MainWindow::setCurrentProgressSlot(qint64 bytesreceived,qint64 bytestotal)
{
    QMessageBox *box = new QMessageBox;
    QTimer::singleShot(10*100,box,SLOT(close()));   //box information延迟1S

    qDebug()<<"bytesreceived value is:"<<bytesreceived;   //jia jindutiao zaixiegeSLOT bujiale...
    qDebug()<<"bytestotal value is:"<<bytestotal;

    if(bytesreceived == bytestotal)
    {
        box->setWindowTitle("successed");
        box->setText("download completed!");
        box->show();

        qDebug()<<"download is ok!";
    }else if(bytesreceived == 0)
    {
        box->setWindowTitle("start");
        box->setText("downloading...");
        box->show();

        qDebug()<<"downloading...";
    }
}
