#include "swebengineview.h"
#include <QDebug>
#include <QWebEngineSettings>
#include <QString>
#include <mainwindow.h>

SWebEngineView::SWebEngineView(QWidget *parent) : QWebEngineView(parent)
{
}

QList<QUrl> SWebEngineView::listUrl() const
{
    return m_listUrl;
}

void SWebEngineView::addItemUrl(QUrl url)
{
    m_listUrl << url;
}

QWebEngineView *SWebEngineView::createWindow(QWebEnginePage::WebWindowType type)
{
    qDebug()<<"open a new page";

    SWebEngineView *popup = new SWebEngineView;
    popup->setAttribute(Qt::WA_DeleteOnClose);
    popup->show();
    return popup;
    //    return this;

}
