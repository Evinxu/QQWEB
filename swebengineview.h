#ifndef SWEBENGINEVIEW_H
#define SWEBENGINEVIEW_H

#include <QWidget>
#include <QWebEngineView>
#include <QWebEngineSettings>

class SWebEngineView : public QWebEngineView
{
    Q_OBJECT
public:
    explicit SWebEngineView(QWidget *parent = 0);

    QList<QUrl> listUrl() const;
    void addItemUrl(QUrl url);
protected:
    /**
     * @brief createWindow
     * @param type
     * @return
     */
    QWebEngineView *createWindow(QWebEnginePage::WebWindowType type);
private:
    QList<QUrl> m_listUrl;

};

#endif // SWEBENGINEVIEW_H

