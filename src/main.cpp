#include <iostream>
#include <QWidget>
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    QWidget* w = new QWidget();
    w->show();
    QWidget* widg = new QWidget();
    std::cout << "test1" << std::endl;
    return a.exec();
}
