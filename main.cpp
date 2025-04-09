// #include <QApplication>
// #include "mainwindow.h"

// int main(int argc, char *argv[]) {
//     QApplication app(argc, argv);
//     MainWindow window;
//     window.setWindowTitle("Секундомер");
//     window.resize(300, 200);
//     window.show();
//     return app.exec();
// }


// ЧАСТ 2

#include <QApplication>
#include "mainwindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Секундомер");
    w.resize(400, 300);
    w.show();
    return a.exec();
}
