#ifndef GOOGLEMAPWEBENGINE_H
#define GOOGLEMAPWEBENGINE_H

#include <QWidget>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWebEngineWidgets/QWebEnginePage>
#include <QtWebChannel/QWebChannel>
#include <QtWebEngineWidgets/QWebEngineSettings>

namespace Ui {
class GoogleMapWebEngine;
}

class GoogleMapWebEngine : public QWidget
{
    Q_OBJECT

public:
    explicit GoogleMapWebEngine(QWidget *parent = nullptr);
    virtual ~GoogleMapWebEngine() override;

protected:
    virtual void wheelEvent(QWheelEvent * event) override;

private:
    Ui::GoogleMapWebEngine *ui;
    QWebEngineView* m_webview;
    QWebChannel* m_webChannel;
};

#endif // GOOGLEMAPWEBENGINE_H
