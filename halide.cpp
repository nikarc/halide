#include <QFileDialog>
#include <QStandardPaths>
#include <QLabel>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTimer>

#include "halide.h"
#include "./ui_halide.h"
#include "ImageView/ZoomableGraphicsView.h"
#include "cameraRawImage.h"
#include "RawFileExtensions.h"

Halide::Halide(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Halide)
    , m_cameraRawImage(new CameraRawImage)
    , m_graphicsView(new ZoomableGraphicsView)
    , m_graphicsScene(new QGraphicsScene)
{
    ui->setupUi(this);

    m_graphicsView->setScene(m_graphicsScene);
    m_graphicsView->setAlignment(Qt::AlignCenter);
    m_graphicsView->setRenderHint(QPainter::Antialiasing);
    m_graphicsView->setRenderHint(QPainter::SmoothPixmapTransform);
    m_graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    // m_graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);
    m_graphicsView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    this->setCentralWidget(ui->centralwidget);
}

Halide::~Halide()
{
    delete ui;
}

void Halide::on_actionOpen_triggered()
{
    QStringList fileFilters;

    fileFilters << "Image Files (*.png *.jpg *.jpeg *.bmp)";

    QString rawFilter = "RAW Files (";
    for (const auto& ext : ImageProcessing::rawFileExtensions) {
        rawFilter += QString("*%1 ").arg(QString::fromUtf8(ext.data(), ext.size()));
    }
    rawFilter = rawFilter.trimmed() + ")";
    fileFilters << rawFilter;

    fileFilters.prepend("All Supported Files (" + rawFilter.mid(11, rawFilter.length() - 12) + " *.png *.jpg *.jpeg *.bmp)");

    QString filter = fileFilters.join(";;");

    QString picturesLocation = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    QString filename = QFileDialog::getOpenFileName(this, tr("Open Image"),
                                                    picturesLocation,
                                                    filter);


    QImage image = m_cameraRawImage->convertRawToQImage(filename.toStdString().c_str());
    QPixmap pixmap(QPixmap::fromImage(image));

    if (pixmap.isNull()) {
        QMessageBox::warning(this, tr("Open Image"),
                             tr("The image file could not be loaded."));
        return;
    }

    m_graphicsScene->clear();

    QGraphicsPixmapItem* pixmapItem = new QGraphicsPixmapItem(pixmap);
    pixmapItem->setTransformationMode(Qt::SmoothTransformation);
    m_graphicsScene->addItem(pixmapItem);

        // Defer the fitInView call to ensure the view has been properly resized
    QTimer::singleShot(0, this, [=]() {
        m_graphicsView->fitInView(pixmapItem, Qt::KeepAspectRatio);
    });

    // Show the graphics view and close button
    m_graphicsView->setVisible(true);

    ui->imageLayout->addWidget(m_graphicsView);
}

