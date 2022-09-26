#include <QApplication>
#include "./ui_player.h"
#include "PlayerMainWindow.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    PlayerMainWindow window(nullptr);
    Ui::MainWindow player;
    QFont font;
    player.setupUi(&window);
    player.playButton->setMaximumWidth(MAX_BUTTON_WIDTH);
    player.pauseButton->setMaximumWidth(MAX_BUTTON_WIDTH);
    player.stopButton->setMaximumWidth(MAX_BUTTON_WIDTH);
    player.rewButton->setMaximumWidth(MAX_BUTTON_WIDTH);
    player.forwardButton->setMaximumWidth(MAX_BUTTON_WIDTH);
    player.seekPosition->setMinimumWidth(MIN_SLIDER_WIDTH);
    player.playButton->setText(QChar(0x25b6));
    player.pauseButton->setText(QChar(0x23f8));
    player.stopButton->setText(QChar(0x23f9));
    player.rewButton->setText(QChar(0x23ea));
    player.forwardButton->setText(QChar(0x23e9));
    window.playerWindow = player.playerWindow;
    window.slider = player.seekPosition;
    font.setPixelSize(50);
    window.playerWindow->setFont(font);
    QObject::connect(&window.timer, &QTimer::timeout, &window, &PlayerMainWindow::simulatePlay);

    window.show();
    return QApplication::exec();
}
