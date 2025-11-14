#ifndef WIDGET_H
#define WIDGET_H

#include <QApplication>
#include <QPushButton>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QMediaPlayer>
#include <QUrl>
// #include <QMediaContent>
#include <QAudioOutput>

class ImageButton : public QPushButton
{
    Q_OBJECT
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
    QMediaPlayer* player;
    //QMediaContent clickSound;
public:
    ImageButton() = default;
    ImageButton(QWidget *parent);
    void paintEvent(QPaintEvent *event) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent* e) override;
public slots:
    void setUp();
    void setDown();
};

#endif // WIDGET_H
