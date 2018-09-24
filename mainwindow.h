#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWebEngineView>
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

private:
    Ui::MainWindow *ui;
    SWebEngineView* QQweb = Q_NULLPTR;
};

#endif // MAINWINDOW_H
