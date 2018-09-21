#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QWebEngineView>
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

    this->setWindowFlags(Qt::FramelessWindowHint);

    this->setAttribute(Qt::WA_TranslucentBackground, true);

    QDesktopWidget *deskdop = QApplication::desktop();
    move((deskdop->width() - this->width())/2, (deskdop->height() - this->height())/2);

    QObject::connect(ui->openQQbutten,SIGNAL(clicked(bool)),this,SLOT(OpenQQwebButtonSlot()));
    QObject::connect(ui->QuitButton,SIGNAL(clicked(bool)),this,SLOT(quitButtonSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//打开QQ按钮
void MainWindow::OpenQQwebButtonSlot()
{
    QDesktopWidget *deskdop = QApplication::desktop();
    QWebEngineView * QQweb = new QWebEngineView;
    QQweb->load(QUrl("https://w.qq.com/"));
    QQweb->show();
    QQweb->setMaximumSize(500,809);
    QQweb->setMinimumSize(500,809);
    QQweb->move((deskdop->width() - this->width())/2,(deskdop->height() - this->height())/2);

    this->hide();
}

void MainWindow::quitButtonSlot()
{
    exit(0);
}
