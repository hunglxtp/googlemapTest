#include <QMouseEvent>
#include "googlemapwebengine.h"
#include "ui_googlemapwebengine.h"

GoogleMapWebEngine::GoogleMapWebEngine(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GoogleMapWebEngine)
{
//#ifdef Q_DEBUG
    qputenv("QTWEBENGINE_REMOTE_DEBUGGING", "1234");
//#endif
    ui->setupUi(this);

    m_webview = new QWebEngineView();

    m_webChannel = new QWebChannel();
    m_webChannel->registerObject("goolemainWindow", this);
    m_webview->page()->setWebChannel(m_webChannel);

    QUrl url = QUrl("qrc:/html/googlemap.html");
    m_webview->setUrl(url);
    ui->verticalLayout->addWidget(m_webview);
}

GoogleMapWebEngine::~GoogleMapWebEngine()
{
    m_webChannel->deregisterObject(this);
    delete ui;
}

void GoogleMapWebEngine::wheelEvent(QWheelEvent * event)
{
    if(event->modifiers().testFlag(Qt::ControlModifier)){
        QWidget::wheelEvent(event);
    } else {
        QWidget::wheelEvent(event);
    }
}
