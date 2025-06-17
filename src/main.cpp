#include <QApplication>
#include "widgets/playlist.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    Playlist window;
    window.resize(600, 400);
    window.show();
    return app.exec();
}
