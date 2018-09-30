//************//v1.0*************//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QDesktopWidget>
#include <QString>
#include <QtWebEngineWidgets/QWebEngineSettings>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);   //支持 flash

    QString url = "https://w.qq.com/";

    QQweb = new SWebEngineView(this);
    QUrl QQurl = QUrl(url);
    QQweb->load(QQurl);
    QQweb->addItemUrl(QQurl);
    QQweb->show();

    this->setMaximumSize(1060,642.72);
    this->setMinimumSize(1060,642.72);
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);

    QObject::connect(QQweb->page()->profile(),&QWebEngineProfile::downloadRequested,this,&MainWindow::downloadJumpSlot);   //下载

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    QQweb->resize(this->size());
}

///////////////**************//////////////////下载操作
void MainWindow::downloadJumpSlot(QWebEngineDownloadItem*softdownload)
{
    qDebug()<<"download test!";
    softdownload->accept();
    QObject::connect(softdownload,SIGNAL(downloadProgress(qint64,qint64)),this,SLOT(setCurrentProgressSlot(qint64,qint64)));
}

void MainWindow::setCurrentProgressSlot(qint64 bytesreceived,qint64 bytestotal)
{
    emit dataChanged(bytesreceived,bytestotal);
    QMessageBox *box = new QMessageBox;
    QTimer::singleShot(10*100,box,SLOT(close()));   //box information延迟1S

    qDebug()<<"bytesreceived value is:"<<bytesreceived;
    qDebug()<<"bytestotal value is:"<<bytestotal;

    if(bytesreceived == bytestotal)
    {
        box->setWindowTitle("successed");
        box->setText("download completed!");
        box->show();

        //        QMessageBox::information(NULL,"successed","download completed!");
        qDebug()<<"download is ok!";
    }else if(bytesreceived == 0)
    {
        box->setWindowTitle("start");
        box->setText("downloading...");
        box->show();
        //        QMessageBox::information(NULL,"start","downloading...");
        qDebug()<<"downloading...";
    }
}
