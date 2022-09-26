#pragma once
#include <QMainWindow>
#include <QTimer>
#include <QTextEdit>
#include <QSlider>

enum Mode {
    Play,
    Pause,
    Stop,
    Rewind,
    Forward
};

const int MIN_POSITION = 0;
const int MAX_POSITION = 100;
const int MAX_BUTTON_WIDTH = 30;
const int MIN_SLIDER_WIDTH = 50;

class PlayerMainWindow : public QMainWindow {
Q_OBJECT
private:
    Mode mode;
    int position = 0;
public:
    QTimer timer;
    QTextEdit *playerWindow;
    QSlider *slider;
    PlayerMainWindow(QWidget *parent = nullptr) : QMainWindow(parent){}
public slots:
    void play();
    void pause();
    void stop();
    void rewind();
    void forward();
    void seek(int value);
    void setPosition(int pos);
    int getPosition() const;
    void simulatePlay();
    void printStatus() const;
};