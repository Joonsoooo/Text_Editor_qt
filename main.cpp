#include "text_editor.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    text_editor window;
    window.show();
    return app.exec();
}
