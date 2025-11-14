#include "widget.h"
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    ImageButton redButton(nullptr);
    redButton.setFixedSize(100, 100);
    redButton.move(1000, 400);
    QObject::connect(&redButton, &QPushButton::clicked, [](){ std::cout << "clicked\n"; });
    redButton.show();
    return app.exec();
}

#include "main.moc"
