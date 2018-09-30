#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebEngineDownloadItem>
#include <QWebEngineProfile>
#include "swebengineview.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void resizeEvent(QResizeEvent *);

signals:
    void downloadRequested(QWebEngineDownloadItem *softdownload);

    void dataChanged(qint64,qint64);

private slots:
    void downloadJumpSlot(QWebEngineDownloadItem *softdownload);

    void setCurrentProgressSlot(qint64 bytesreceived,qint64 bytestotal);

private:
    Ui::MainWindow *ui;
    SWebEngineView* QQweb = Q_NULLPTR;
};

#endif // MAINWINDOW_H
