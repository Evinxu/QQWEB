//************//v1.0*************//

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QUrl>
#include <QWebEngineView>
#include <QWebEngineSettings>
#include <QtWebChannel/QtWebChannel>
#include <QDesktopWidget>
#include <QRect>
#include <QString>
#include <QtWebEngineWidgets/QWebEngineSettings>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::JavascriptEnabled, true);
    QWebEngineSettings::globalSettings()->setAttribute(QWebEngineSettings::PluginsEnabled,true);

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

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    QQweb->resize(this->size());
}
