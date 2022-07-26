#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QLabel>
#include <QFileDialog>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QGraphicsPixmapItem>
#include <QMap>
#include <QPluginLoader>
#include "opencv2/opencv.hpp"
#include "editor_plugin_interface.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    void initUI();
    void createActions();
    void showImage(QString path);
    void setupShortcuts();
    void loadPlugins();

private:
    QMenu *fileMenu;
    QMenu *viewMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QToolBar *fileToolBar;
    QToolBar *viewToolBar;
    QToolBar *editToolBar;

    QGraphicsScene *imageScene;
    QGraphicsView *imageView;

    QStatusBar *mainStatusBar;
    QLabel *mainStatusLabel;

    QGraphicsPixmapItem *currentImage;

    QString currentImagePath;

    QAction *openAction;
    QAction *saveAsAction;
    QAction *exitAction;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *previousImageAction;
    QAction *nextImageAction;
    QAction *blurAction;
    QAction *aboutAction;

    QMap<QString, EditorPluginInterface*> editPlugins;

private slots:
    void openImage();
    void zoomIn();
    void zoomOut();
    void saveAs();
    void previousImage();
    void nextImage();
    void blurImage();
    void about();
    void pluginPerform();
};
#endif // MAINWINDOW_H
