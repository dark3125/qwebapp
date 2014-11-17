#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWebHistory>
#include <QWebHistoryItem>
#include <QWebSettings>


MainWindow::MainWindow(bool showButtons, QString url, QString labelbar, QString icontype, QString icon, QString title, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MainWindow::setWindowTitle(title);
    QIcon windowIcon;
    if (icontype == "theme") {
        windowIcon = QIcon::fromTheme(icon);
    } else if (icontype == "file") {
        windowIcon = QIcon(icon);
    }

    MainWindow::setWindowIcon(windowIcon);
    if (showButtons) {
        ui->stackedWidget->setCurrentIndex(0);
        ui->label->setText(labelbar);
        ui->webView->settings()->globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
        ui->webView->setUrl(url);
    } else {
        ui->stackedWidget->setCurrentIndex(1);
        ui->webView_2->settings()->globalSettings()->setAttribute(QWebSettings::PluginsEnabled, true);
        ui->webView_2->setUrl(url);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->webView->back();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->webView->forward();
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->webView->reload();
}
