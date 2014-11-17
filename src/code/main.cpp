#include "src/include/mainwindow.h"
#include <QApplication>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QDesktopWidget>

#define VERSION "1.0"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("QWebApp");
    a.setApplicationVersion("0.1");

    QCommandLineParser parser;
    parser.setApplicationDescription("Fast and slick customizable minimalistic web browser used for making desktop launchers for web apps");
    parser.addHelpOption();
    parser.addVersionOption();
    parser.addPositionalArgument("url", QApplication::translate("main", "Address of the web site"));

    QCommandLineOption showButtonsOpt(QStringList() << "c" << "controlbar" << "ctlbar" << "ctrlbar",QApplication::translate("main", "Show control bar (buttons and label)"));
    parser.addOption(showButtonsOpt);
    QCommandLineOption setLabelOpt(QStringList() << "l" << "setlabel" << "labeltext" << "setlabeltext", QApplication::translate("main", "Set the label text (if control bar enabled)"), QApplication::translate("main", "label"));
    parser.addOption(setLabelOpt);
    QCommandLineOption setTitleOpt(QStringList() << "t" << "settitle" << "titletext" << "settitletext", QApplication::translate("main", "Set the window title"), QApplication::translate("main", "title"));
    parser.addOption(setTitleOpt);
    QCommandLineOption setIconOpt(QStringList() << "i" << "seticon" << "icon", QApplication::translate("main", "Set the icon (from theme)"), QApplication::translate("main", "icon"));
    parser.addOption(setIconOpt);
    QCommandLineOption setFileIconOpt(QStringList() << "I" << "setfileicon" << "fileicon", QApplication::translate("main", "Set the icon (from a file)"), QApplication::translate("main", "file"));
    parser.addOption(setFileIconOpt);
    QCommandLineOption setXSizeOpt(QStringList() << "x" << "sizex" << "xsize", QApplication::translate("main", "Set the window horizontal size (in pixels))"), QApplication::translate("main", "size"));
    parser.addOption(setXSizeOpt);
    QCommandLineOption setYSizeOpt(QStringList() << "y" << "sizey" << "ysize", QApplication::translate("main", "Set the window vertical size (in pixels))"), QApplication::translate("main", "size"));
    parser.addOption(setYSizeOpt);
    QCommandLineOption centerOpt(QStringList() << "C" << "center", QApplication::translate("main", "Launch the window in the center of the display"));
    parser.addOption(centerOpt);
    QCommandLineOption setXPosOpt(QStringList() << "X" << "posx" << "xpos", QApplication::translate("main", "Set the window X coordinate on the display (in pixels))"), QApplication::translate("main", "coordinate"));
    parser.addOption(setXPosOpt);
    QCommandLineOption setYPosOpt(QStringList() << "Y" << "posy" << "ypos", QApplication::translate("main", "Set the window Y coordinate on the display (in pixels))"), QApplication::translate("main", "coordinate"));
    parser.addOption(setYPosOpt);

    QString labeltext = QString("QWebApp ").append(VERSION).append(" ");
    QString icontype = "theme";
    QString icon = "web-browser";
    QString url = "http://thebest404pageever.com/";
    QString title = QString("QWebApp ").append(VERSION).append(" ");
    int xsize = 200;
    int ysize = 200;
    int xpos = 100;
    int ypos = 100;
    bool center = false;

    parser.process(a);
    const QStringList args = parser.positionalArguments();
    bool showButtons = parser.isSet(showButtonsOpt);
    if (parser.isSet(showButtonsOpt) && parser.isSet(setLabelOpt)) {
            labeltext = parser.value(setLabelOpt).append(" ");
    }

    if (parser.isSet(centerOpt) && ! parser.isSet(setXPosOpt) && ! parser.isSet(setYPosOpt)) {
        center = true;
    }

    if (parser.isSet(setXPosOpt) && ! parser.isSet(centerOpt)) {
        xpos = parser.value(setXPosOpt).toInt();
    }

    if (parser.isSet(setYPosOpt) && ! parser.isSet(centerOpt)) {
        ypos = parser.value(setYPosOpt).toInt();
    }

    if (parser.isSet(setXSizeOpt)) {
        xsize = parser.value(setXSizeOpt).toInt();
    }

    if (parser.isSet(setYSizeOpt)) {
        ysize = parser.value(setYSizeOpt).toInt();
    }

    if (args.length() > 0) {
        url = args.at(0);
    }

    if (parser.isSet(setIconOpt)) {
        icontype = "theme";
        icon = parser.value(setIconOpt);
    } else if (parser.isSet(setFileIconOpt)) {
        icontype = "file";
        icon = parser.value(setFileIconOpt);
    }

    if (parser.isSet(setTitleOpt)) {
        title = parser.value(setTitleOpt);
    }

    MainWindow w(showButtons, url, labeltext, icontype, icon, title);
    w.show();
    if (center) {
        w.move(QApplication::desktop()->availableGeometry().center() - w.rect().center());
    } else {
        w.move(xpos, ypos);
    }
    w.resize(xsize, ysize);
    return a.exec();
}

