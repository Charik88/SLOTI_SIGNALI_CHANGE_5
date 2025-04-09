
// #include "mainwindow.h"
// #include <QVBoxLayout>
// #include <QHBoxLayout>
// #include <QDebug>

// Stopwatch::Stopwatch(QObject *parent) : QObject(parent), elapsedTime(0), running(false) {
//     timer = new QTimer(this);
//     connect(timer, &QTimer::timeout, this, &Stopwatch::updateTime);
// }

// void Stopwatch::start() {
//     if (!running) {
//         running = true;
//         timer->start(100); // обновление круга каждые 100 мс
//     }
// }

// void Stopwatch::stop() {
//     if (running) {
//         running = false;
//         timer->stop();
//     }
// }

// void Stopwatch::reset() {
//    // stop();
//     elapsedTime = 0;
//     emit timeUpdated(elapsedTime);
// }

// bool Stopwatch::isRunning() const {
//     return running;
// }

// int Stopwatch::getCurrentTime() const {
//     return elapsedTime;
// }

// void Stopwatch::updateTime() {
//     elapsedTime++;
//     emit timeUpdated(elapsedTime);
// }

// MainWindow::MainWindow(QWidget *parent) : QWidget(parent), lapCount(0), lastLapTime(0) { // Инициализация счетчика кругов
//     stopwatch = new Stopwatch(this);

//     // Создание виджетов
//     timeLabel = new QLabel("00:00:00", this);
//     startStopButton = new QPushButton("Старт", this);
//     clearButton = new QPushButton("Очистить", this);
//     lapButton = new QPushButton("Круг", this);
//     textBrowser = new QTextBrowser(this);

//     // Установка компоновки
//     QVBoxLayout *layout = new QVBoxLayout(this);
//     layout->addWidget(timeLabel);

//     QHBoxLayout *buttonLayout = new QHBoxLayout();
//     buttonLayout->addWidget(startStopButton);
//     buttonLayout->addWidget(clearButton);
//     buttonLayout->addWidget(lapButton);

//     layout->addLayout(buttonLayout);
//     layout->addWidget(textBrowser);

//     // Подключение сигналов и слотов
//     connect(startStopButton, &QPushButton::clicked, this, &MainWindow::onStartStopClicked);
//     connect(clearButton, &QPushButton::clicked, this, &MainWindow::onClearClicked);
//     connect(lapButton, &QPushButton::clicked, this, &MainWindow::onLapClicked);
//     connect(stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateTimeDisplay);
// }

// MainWindow::~MainWindow() {
//     delete stopwatch;
// }

// void MainWindow::onStartStopClicked()
// // {
// //     if (stopwatch->isRunning()) {
// //         stopwatch->stop();
// //     } else {
// //         stopwatch->start();
// //     }
// // }
//    {
//     if (stopwatch->isRunning()) {
//         stopwatch->stop();
//         startStopButton->setText("Старт"); // Меняем текст на "Старт"
//         lapButton->setEnabled(false); // Блокируем кнопку "Круг"
//     } else {
//         stopwatch->start();
//         startStopButton->setText("Стоп"); // Меняем текст на "Стоп"
//         lapButton->setEnabled(true); // Разблокируем кнопку "Круг"
//     }
// }

// void MainWindow::onClearClicked() {
//     stopwatch->reset();
//     timeLabel->setText("00:00:00.0");
//     textBrowser->clear();
//     lapCount = 0; // Сброс счетчика кругов
//     lastLapTime = 0; // Сброс времени последнего круга ??

// }

// // void MainWindow::onLapClicked() {
// //     if (stopwatch->isRunning()) {
// //         lapCount++; // Увеличиваем номер круга
// //         int currentLapTime = stopwatch->getCurrentTime(); // Получаем общее время
// //         updateLapDisplay(currentLapTime);
// //     }
// // }
// // void MainWindow::onLapClicked() {
// //     if (stopwatch->isRunning()) {
// //         int currentLapTime = stopwatch->getCurrentTime(); // Получаем общее время
// //         int lapTime = currentLapTime - lastLapTime; // Вычисляем время круга
// //         lastLapTime = currentLapTime; // Обновляем время последнего круга
// //         lapCount++; // Увеличиваем номер круга
// //         updateLapDisplay(lapTime); // Передаем время круга для отображения
// //     }
// // }
// // void MainWindow::onLapClicked() {
// //     if (stopwatch->isRunning()) {
// //         qDebug() << "Lap button clicked"; // Добавьте это для отладки
// //         int currentLapTime = stopwatch->getCurrentTime(); // Получаем общее время
// //         int lapTime = currentLapTime - lastLapTime; // Вычисляем время круга
// //         lastLapTime = currentLapTime; // Обновляем время последнего круга
// //         lapCount++; // Увеличиваем номер круга
// //         updateLapDisplay(lapTime); // Передаем время круга для отображения
// //     }
// // }

// void MainWindow::onLapClicked() {
//     if (stopwatch->isRunning()) {
//         qDebug() << "Lap button clicked"; // Отладочный вывод
//         int currentLapTime = stopwatch->getCurrentTime(); // Получаем общее время

//         // Если это первый круг, устанавливаем lastLapTime в текущее время
//         if (lapCount == 0) {
//             //lastLapTime = currentLapTime;
//             lastLapTime == 0;
//         }

//         int lapTime = currentLapTime - lastLapTime; // Вычисляем время круга
//         lastLapTime = currentLapTime; // Обновляем время последнего круга
//         lapCount++; // Увеличиваем номер круга
//         updateLapDisplay(lapTime); // Передаем время круга для отображения
//     }
// }


// // void MainWindow::updateTimeDisplay(int seconds) {
// //     int hours = seconds / 3600;
// //     int minutes = (seconds % 3600) / 60;
// //     int secs = seconds % 60;
// //     timeLabel->setText(QString("%1:%2:%3")
// //                            .arg(hours, 2, 10, QChar('0'))
// //                            .arg(minutes, 2, 10, QChar('0'))
// //                            .arg(secs, 2, 10, QChar('0')));
// // }

// void MainWindow::updateTimeDisplay(int milliseconds) {
//     int seconds = milliseconds / 10; // Переводим миллисекунды в секунды
//     int hours = seconds / 3600;
//     int minutes = (seconds % 3600) / 60;
//     secs = seconds % 60;
//     int ms = milliseconds % 1000 / 100; // Получаем миллисекунды для отображения
//     timeLabel->setText(QString("%1:%2:%3.%4")
//                            .arg(hours, 2, 10, QChar('0'))
//                            .arg(minutes, 2, 10, QChar('0'))
//                            .arg(secs, 2, 10, QChar('0'))
//                            .arg(ms, 1, 10, QChar('0'))); // Добавляем миллисекунды
// }



// // void MainWindow::updateLapDisplay(int lapTime) {
// //     // Форматируем время круга
// //     int hours = lapTime / 3600;
// //     int minutes = (lapTime % 3600) / 60;
// //     int secs = lapTime % 60;
// //     QString lapTimeStr = QString("%1:%2:%3")
// //                              .arg(hours, 2, 10, QChar('0'))
// //                              .arg(minutes, 2, 10, QChar('0'))
// //                              .arg(secs, 2, 10, QChar('0'));

// //     // Добавляем информацию о круге в текстовый браузер
// //     textBrowser->append(QString("Круг %1, время: %2 сек").arg(lapCount).arg(lapTimeStr));
// // }

// void MainWindow::updateLapDisplay(int lapTime) {
//     // Форматируем время круга
//     int hours = lapTime / 3600;
//     int minutes = (lapTime % 3600) / 60;
//     int secs = lapTime % 60;

//     // Создаем строку с отформатированным временем
//     QString lapTimeStr = QString("%1:%2:%3")
//                              .arg(hours, 2, 10, QChar('0'))
//                              .arg(minutes, 2, 10, QChar('0'))
//                              .arg(secs, 2, 10, QChar('0'));

//     // Добавляем информацию о круге в текстовый браузер
//     textBrowser->append(QString("Круг %1, время: %2 сек").arg(lapCount).arg(lapTimeStr));
// }


//ЧАСТЬ 2

#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

Stopwatch::Stopwatch(QObject *parent) : QObject(parent), elapsedTime(0), running(false), milliseconds(0) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Stopwatch::updateTime);
}

void Stopwatch::start() {
    if (!running) {
        running = true;
        timer->start(100); // обновление каждые 100 миллисекунд
    }
}

void Stopwatch::stop() {
    if (running) {
        running = false;
        timer->stop();
    }
}

void Stopwatch::reset() {
   // stop();
    elapsedTime = 0;
    milliseconds = 0;
    emit timeUpdated(elapsedTime * 1000 + milliseconds);
}

bool Stopwatch::isRunning() const {
    return running;
}

int Stopwatch::getCurrentTime() const {
    return elapsedTime * 1000 + milliseconds; // возвращаем общее время в миллисекундах
}

void Stopwatch::updateTime() {
    milliseconds += 100; // увеличиваем миллисекунды на 100
    if (milliseconds >= 1000) { // если миллисекунды достигли 1000, увеличиваем секунды
        elapsedTime++;
        milliseconds = 0; // сбрасываем миллисекунды
    }
    emit timeUpdated(elapsedTime * 1000 + milliseconds);
}

MainWindow::MainWindow(QWidget *parent) : QWidget(parent), lapCount(0), lastLapTime(0) {
    stopwatch = new Stopwatch(this);

    // Создание виджетов
    timeLabel = new QLabel("00:00:00.000", this);
    startStopButton = new QPushButton("Старт", this);
    clearButton = new QPushButton("Очистить", this);
    lapButton = new QPushButton("Круг", this);
    textBrowser = new QTextBrowser(this);

    // Установка компоновки
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(timeLabel);

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addWidget(startStopButton);
    buttonLayout->addWidget(clearButton);
    buttonLayout->addWidget(lapButton);

    layout->addLayout(buttonLayout);
    layout->addWidget(textBrowser);

    // Подключение сигналов и слотов
    connect(startStopButton, &QPushButton::clicked, this, &MainWindow::onStartStopClicked);
    connect(clearButton, &QPushButton::clicked, this, &MainWindow::onClearClicked);
    connect(lapButton, &QPushButton::clicked, this, &MainWindow::onLapClicked);
    connect(stopwatch, &Stopwatch::timeUpdated, this, &MainWindow::updateTimeDisplay);
}

MainWindow::~MainWindow() {
    delete stopwatch;
}

void MainWindow::onStartStopClicked() {
    if (stopwatch->isRunning()) {
        stopwatch->stop();
        startStopButton->setText("Старт"); // Меняем текст на "Старт"
        lapButton->setEnabled(false); // Блокируем кнопку "
        lapButton->setEnabled(false); // Блокируем кнопку "Круг"
    } else {
        stopwatch->start();
        startStopButton->setText("Стоп"); // Меняем текст на "Стоп"
        lapButton->setEnabled(true); // Разблокируем кнопку "Круг"
    }
}

void MainWindow::onClearClicked() {
    stopwatch->reset();
    timeLabel->setText("00:00:00.000");
    textBrowser->clear();
    lapCount = 0; // Сброс счетчика кругов
}

void MainWindow::onLapClicked() {
    if (stopwatch->isRunning()) {
        int currentLapTime = stopwatch->getCurrentTime(); // Получаем общее время

        // Если это первый круг, устанавливаем lastLapTime в текущее время
        if (lapCount == 0) {
            lastLapTime = 0; // устанавливаем начальное время
        }

        int lapTime = currentLapTime - lastLapTime; // Вычисляем время круга
        lastLapTime = currentLapTime; // Обновляем время последнего круга
        lapCount++; // Увеличиваем номер круга
        updateLapDisplay(lapTime); // Передаем время круга для отображения
    }
}

void MainWindow::updateTimeDisplay(int totalMilliseconds) {
    int hours = totalMilliseconds / 3600000;
    int minutes = (totalMilliseconds % 3600000) / 60000;
    int seconds = (totalMilliseconds % 60000) / 1000;
    int milliseconds = totalMilliseconds % 1000;

    timeLabel->setText(QString("%1:%2:%3.%4")
                           .arg(hours, 2, 10, QChar('0'))
                           .arg(minutes, 2, 10, QChar('0'))
                           .arg(seconds, 2, 10, QChar('0'))
                           .arg(milliseconds, 3, 10, QChar('0')));
}

void MainWindow::updateLapDisplay(int lapTime) {
    // Форматируем время круга
    int hours = lapTime / 3600000;
    int minutes = (lapTime % 3600000) / 60000;
    int seconds = (lapTime % 60000) / 1000;
    int milliseconds = lapTime % 1000;

    // Создаем строку с отформатированным временем
    QString lapTimeStr = QString("%1:%2:%3.%4")
                             .arg(hours, 2, 10, QChar('0'))
                             .arg(minutes, 2, 10, QChar('0'))
                             .arg(seconds, 2, 10, QChar('0'))
                             .arg(milliseconds, 3, 10, QChar('0'));

    // Добавляем информацию о круге в текстовый браузер
    textBrowser->append(QString("Круг %1, время: %2").arg(lapCount).arg(lapTimeStr));
}
