#include "PlayerMainWindow.h"

void PlayerMainWindow::play() {
    mode = Play;
    printStatus();
    timer.start(1000);
}

void PlayerMainWindow::pause() {
    mode = Pause;
    printStatus();
    timer.stop();
}

void PlayerMainWindow::stop() {
    mode = Stop;
    position = 0;
    slider->setValue(0);
    printStatus();
    timer.stop();
}

void PlayerMainWindow::rewind() {
    mode = Rewind;
    timer.stop();
    timer.start(200);
    printStatus();
}

void PlayerMainWindow::forward() {
    mode = Forward;
    timer.stop();
    timer.start(200);
    printStatus();
}

void PlayerMainWindow::seek(int value) {
    position = value;
    printStatus();
}

void PlayerMainWindow::setPosition(int pos) {
    if (pos < MIN_POSITION) position = MIN_POSITION;
    else if (pos > MAX_POSITION) position = MAX_POSITION;
    else position = pos;
}

int PlayerMainWindow::getPosition() const{
    return position;
}

void PlayerMainWindow::printStatus() const {
    QString out;
    switch (mode) {
        case Play:
            out = "Play";
            break;
        case Pause:
            out = "Pause";
            break;
        case Stop:
            out = "Stop";
            break;
        case Rewind:
            out = "Rewind";
            break;
        case Forward:
            out = "Forward";
            break;
    }
    out += "\n" + QString::number(getPosition());
    playerWindow->setText(out);
}

void PlayerMainWindow::simulatePlay() {
    if (mode == Play) setPosition(++position);
    else if (mode == Stop) setPosition(MIN_POSITION);
    else if (mode == Rewind) {
        setPosition(--position);
        if (position == MIN_POSITION) mode = Stop;
    }
    else if (mode == Forward) {
        setPosition(++position);
        if (position == MAX_POSITION) mode = Pause;
    }
    slider->setValue(position);
    printStatus();
}