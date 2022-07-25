#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initUI();
    currentImage = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initUI()
{
    this->resize(800, 600);
    // setup menubar
    fileMenu = menuBar()->addMenu("&File");
    viewMenu = menuBar()->addMenu("&View");
    editMenu = menuBar()->addMenu("&Edit");
    helpMenu = menuBar()->addMenu("&Help");

    // setup toolbar
    fileToolBar = addToolBar("File");
    viewToolBar = addToolBar("View");
    editToolBar = addToolBar("Edit");

    // main area for image display
    imageScene = new QGraphicsScene(this);
    imageView = new QGraphicsView(imageScene);
    setCentralWidget(imageView);

    // setup status bar
    mainStatusBar = statusBar();
    mainStatusLabel = new QLabel(mainStatusBar);
    mainStatusBar->addPermanentWidget(mainStatusLabel);
    mainStatusLabel->setText("Image Information will be here!");

    createActions();

    fileMenu->addAction(openAction);
    fileMenu->addAction(saveAsAction);
    fileMenu->addAction(exitAction);

    viewMenu->addAction(zoomInAction);
    viewMenu->addAction(zoomOutAction);
    viewMenu->addAction(previousImageAction);
    viewMenu->addAction(nextImageAction);

    editMenu->addAction(blurAction);

    helpMenu->addAction(aboutAction);

    fileToolBar->addAction(openAction);
    fileToolBar->addAction(saveAsAction);
    fileToolBar->addAction(exitAction);

    viewToolBar->addAction(zoomInAction);
    viewToolBar->addAction(zoomOutAction);
    viewToolBar->addAction(previousImageAction);
    viewToolBar->addAction(nextImageAction);

    editToolBar->addAction(blurAction);
}

void MainWindow::createActions()
{
    openAction = new QAction("&Open", this);
    saveAsAction = new QAction("&Save As", this);
    exitAction = new QAction("E&xit", this);
    zoomInAction = new QAction("Zoom In", this);
    zoomOutAction = new QAction("Zoom Out", this);
    previousImageAction = new QAction("Previous Image", this);
    nextImageAction = new QAction("Next Image", this);
    blurAction = new QAction("Blur", this);
    aboutAction = new QAction("About", this);

    connect(exitAction, SIGNAL(triggered(bool)), QApplication::instance(), SLOT(quit()));
    connect(openAction, SIGNAL(triggered(bool)), this, SLOT(openImage()));
    connect(zoomInAction, SIGNAL(triggered(bool)), this, SLOT(zoomIn()));
    connect(zoomOutAction, SIGNAL(triggered(bool)), this, SLOT(zoomOut()));
    connect(saveAsAction, SIGNAL(triggered(bool)), this, SLOT(saveAs()));
    connect(previousImageAction, SIGNAL(triggered(bool)), this, SLOT(previousImage()));
    connect(nextImageAction, SIGNAL(triggered(bool)), this, SLOT(nextImage()));
    connect(blurAction, SIGNAL(triggered(bool)), this, SLOT(blurImage()));
    connect(aboutAction, SIGNAL(triggered(bool)), this, SLOT(about()));

    setupShortcuts();
}

void MainWindow::showImage(QString path)
{
    imageScene->clear();
    imageView->resetTransform();
    QPixmap image(path);
    currentImage = imageScene->addPixmap(image);
    imageScene->update();
    imageView->setSceneRect(image.rect());
    QString status = QString("%1, %2x%3, %4 Bytes").arg(path).arg(image.width()).arg(image.height()).arg(QFile(path).size());
    mainStatusLabel->setText(status);
    currentImagePath = path;
}

void MainWindow::setupShortcuts()
{
    QList<QKeySequence> shortcuts;
    shortcuts << Qt::Key_Plus << Qt::Key_Equal;
    zoomInAction->setShortcuts(shortcuts);

    shortcuts.clear();
    shortcuts << Qt::Key_Minus << Qt::Key_Underscore;
    zoomOutAction->setShortcuts(shortcuts);

    shortcuts.clear();
    shortcuts << Qt::Key_Up << Qt::Key_Left;
    previousImageAction->setShortcuts(shortcuts);

    shortcuts.clear();
    shortcuts << Qt::Key_Down << Qt::Key_Right;
    nextImageAction->setShortcuts(shortcuts);
}

void MainWindow::openImage()
{
    QFileDialog dialog(this);
    dialog.setWindowTitle("Open Image");
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter(tr("Supported Image Files (*.png *.bmp *.jpg)"));
    QStringList filePaths;
    if(dialog.exec()) {
        filePaths = dialog.selectedFiles();
        showImage(filePaths.at(0));
    }
}

void MainWindow::zoomIn()
{
    imageView->scale(1.2, 1.2);
}

void MainWindow::zoomOut()
{
    imageView->scale(0.8, 0.8);
}

void MainWindow::saveAs()
{
    if(currentImage == nullptr) {
        QMessageBox::information(this, "Information", "Nothing to save.");
        return;
    }
    QFileDialog dialog(this);
    dialog.setWindowTitle("Save Image As ...");
    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setNameFilter(tr("Images (*.png *.bmp *.jpg)"));
    QStringList fileNames;
    if(dialog.exec()) {
        fileNames = dialog.selectedFiles();
        static QRegularExpression re(".+\\.(png|bmp|jpg)");
        if(re.match(fileNames.at(0)).hasMatch()) {
            currentImage->pixmap().save(fileNames.at(0));
        } else {
            QMessageBox::information(this, "Information", "Save error: bad format or filename.");
        }
    }
}

void MainWindow::previousImage()
{
    QFileInfo current(currentImagePath);
    QDir dir = current.absoluteDir();
    QStringList nameFilters;
    nameFilters << "*.png" << "*.bmp" << "*.jpg";
    QStringList fileNames = dir.entryList(nameFilters, QDir::Files, QDir::Name);
    int idx = fileNames.indexOf(QRegularExpression(QRegularExpression::escape(current.fileName())));
    if(idx > 0) {
        showImage(dir.absoluteFilePath(fileNames.at(idx - 1)));
    } else {
        QMessageBox::information(this, "Information", "Current image is the first one.");
    }
}

void MainWindow::nextImage()
{
    QFileInfo current(currentImagePath);
    QDir dir = current.absoluteDir();
    QStringList nameFilters;
    nameFilters << "*.png" << "*.bmp" << "*.jpg";
    QStringList fileNames = dir.entryList(nameFilters, QDir::Files, QDir::Name);
    int idx = fileNames.indexOf(QRegularExpression(QRegularExpression::escape(current.fileName())));
    if(idx < fileNames.length()-1) {
        showImage(dir.absoluteFilePath(fileNames.at(idx + 1)));
    } else {
        QMessageBox::information(this, "Information", "Current image is the last one.");
    }
}

void MainWindow::blurImage()
{
    if(currentImage == nullptr) {
        QMessageBox::information(this, "Information", "No image to edit.");
        return;
    }
    QPixmap pixmap = currentImage->pixmap();
    QImage image = pixmap.toImage();
    image = image.convertToFormat(QImage::Format_RGB888);
    cv::Mat mat = cv::Mat(image.height(), image.width(), CV_8UC3, image.bits(), image.bytesPerLine());
    cv::Mat tmp;
    cv::blur(mat, tmp, cv::Size(8, 8));
    mat = tmp;
    QImage image_blurred(mat.data, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
    pixmap = QPixmap::fromImage(image_blurred);
    imageScene->clear();
    imageView->resetTransform();
    currentImage = imageScene->addPixmap(pixmap);
    imageScene->update();
    imageView->setSceneRect(pixmap.rect());
    QString status = QString("(editted image), %1x%2").arg(pixmap.width()).arg(pixmap.height());
    mainStatusLabel->setText(status);
}

void MainWindow::about()
{
    QString text = "Image Viewer\nDeveloped by Ignacio Belitzky\n\n";
    text += "This program comes with absolutely no warranty.\n";
    text += "See the GNU General Public License v3.0 for details.";
    QMessageBox::about(this, "About", text);
}

