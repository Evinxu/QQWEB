//************//v1.0*************//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QDesktopWidget>
#include <QRect>
#include <QString>
#include <QImage>
#include <QPixmap>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QQweb = new SWebEngineView(this);
    QUrl url = QUrl("https://w.qq.com/");
    QQweb->load(url);
    QQweb->addItemUrl(url);
    QQweb->show();

    //    this->setWindowFlags(Qt::FramelessWindowHint);
    //    this->setAttribute(Qt::WA_TranslucentBackground, true);

    this->setMaximumSize(1040,642.72);
    this->setMinimumSize(1040,642.72);
    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    QQweb->resize(this->size());
}
