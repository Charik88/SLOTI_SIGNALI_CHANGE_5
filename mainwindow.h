// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

// #include <QWidget>
// #include <QLabel>
// #include <QPushButton>
// #include <QTextBrowser>
// #include <QTimer>

// class Stopwatch : public QObject {
//     Q_OBJECT

// public:
//     Stopwatch(QObject *parent = nullptr);
//     void start();
//     void stop();
//     void reset();
//     bool isRunning() const;
//     int getCurrentTime() const;

// signals:
//     void timeUpdated(int seconds);

// private slots:
//     void updateTime();

// private:
//     QTimer *timer;
//     int elapsedTime; // в секундах
//     bool running;
// };

// class MainWindow : public QWidget {
//     Q_OBJECT

// public:
//     MainWindow(QWidget *parent = nullptr);
//     ~MainWindow();

// private slots:
//     void onStartStopClicked();
//     void onClearClicked();
//     void onLapClicked();
//     void updateTimeDisplay(int seconds);
//     void updateLapDisplay(int lapTime);

// private:
//     QLabel *timeLabel;
//     QPushButton *startStopButton;
//     QPushButton *clearButton;
//     QPushButton *lapButton;
//     QTextBrowser *textBrowser;
//     Stopwatch *stopwatch;
//     int lapCount;
//     int lastLapTime;

// };

// #endif // MAINWINDOW_H


// ЧАСТЬ 2


#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QLabel>
#include <QPushButton>
#include <QTextBrowser>

class Stopwatch : public QObject {
    Q_OBJECT

public:
    explicit Stopwatch(QObject *parent = nullptr);
    void start();
    void stop();
    void reset();
    bool isRunning() const;
    int getCurrentTime() const; // Возвращаем общее время в миллисекундах

signals:
    void timeUpdated(int totalMilliseconds); // Сигнал для обновления времени

private slots:
    void updateTime();

private:
    QTimer *timer;
    int elapsedTime; // Время в секундах
    int milliseconds; // Миллисекунды
    bool running;
};

class MainWindow : public QWidget {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onStartStopClicked();
    void onClearClicked();
    void onLapClicked();
    void updateTimeDisplay(int totalMilliseconds);
    void updateLapDisplay(int lapTime);

private:
    Stopwatch *stopwatch;
    QLabel *timeLabel;
    QPushButton *startStopButton;
    QPushButton *clearButton;
    QPushButton *lapButton;
    QTextBrowser *textBrowser;
    int lapCount;
    int lastLapTime;
};

#endif // MAINWINDOW_H
