#include "mainwindow.h"
#include <QApplication>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QPushButton>
#include <QTextCodec>

//int main(int argc, char *argv[])
//{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    return a.exec();
//}
int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QWidget *vbox = new QWidget();
    vbox->setWindowTitle("Введите Ваш Возраст");

    QSpinBox *spinBox = new QSpinBox(vbox);

    QSlider *slider = new QSlider(Qt::Horizontal, vbox);
    spinBox->setRange(0, 130);
    slider->setRange(0, 130);

    QPushButton *btn = new QPushButton("Выход", vbox);

    QVBoxLayout *layout = new QVBoxLayout(vbox);
    layout->setContentsMargins(5, 5, 5, 5);
    layout->setSpacing(5);
    //vbox->setLayout(layout);

    layout->addWidget(spinBox);
    layout->addWidget(slider);
    layout->addWidget(btn);

    QObject::connect(spinBox, SIGNAL(valueChanged(int)),
                     slider,  SLOT(setValue(int)));

    QObject::connect(slider,  SIGNAL(valueChanged(int)),
                     spinBox, SLOT(setValue(int)));

    QObject::connect(btn,  SIGNAL(clicked(bool)),
                     vbox, SLOT(close()));

    spinBox->setValue(25);

    vbox->show();

    return a.exec();
}
