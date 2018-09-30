#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
#include <QWebEngineDownloadItem>
#include <QWebEngineProfile>
#include <QWebEngineSettings>
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

private slots:
    void downloadJumpSlot(QWebEngineDownloadItem *startdownload);

    void setCurrentProgressSlot(qint64 bytesreceived,qint64 bytestotal);

private:
    Ui::MainWindow *ui;
    SWebEngineView *QQweb = Q_NULLPTR;
};

#endif // MAINWINDOW_H
