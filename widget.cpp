#include "widget.h"
#include <iostream>
// #include "./ui_widget.h"

ImageButton::ImageButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("Пуск");
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    // mButtonDownPixmap   = QPixmap("F:\\Code\\skillbox\\38_1\\resources\\red_Button_Down.png");
    // mButtonUpPixmap     = QPixmap("F:\\Code\\skillbox\\38_1\\resources\\red_Button_Up.png");
    mButtonDownPixmap   = QPixmap("..\\..\\resources\\red_Button_Up.png");
    mButtonUpPixmap     = QPixmap("..\\..\\resources\\red_Button_Up.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this, &QPushButton::clicked, this, &ImageButton::setDown);
    player = new QMediaPlayer();
    QString audio_path = "F:\\Code\\skillbox\\38_1\\click.mp3";
    auto audioOutput = new QAudioOutput();
    player->setAudioOutput(audioOutput);
    player->setSource(QUrl::fromLocalFile(audio_path));
    audioOutput->setVolume(0.7);
    std::cout << "player->activeAudioTrack() " << player->activeAudioTrack() << ", player->isAvailable() " << player->isAvailable() << "\n";
};

ImageButton::~ImageButton()
{
    delete player;
}

void ImageButton::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.drawPixmap(event->rect(), mCurrentButtonPixmap);
}

QSize ImageButton::sizeHint() const
{
    return QSize(100, 100);
}

QSize ImageButton::minimumSizeHint() const
{
    return sizeHint();
}

void ImageButton::keyPressEvent(QKeyEvent* e)
{
    setDown();
}

void ImageButton::setDown()
{
    player->stop();
    player->play();
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100, this, &ImageButton::setUp);
}

void ImageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}
