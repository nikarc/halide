#include "cameraRawImage.h"
#include <iostream>
#include <QImage>

CameraRawImage::CameraRawImage() {}

QImage CameraRawImage::convertRawToQImage(const char* filePath)
{
    LibRaw rawProcessor;

    if (rawProcessor.open_file(filePath) != LIBRAW_SUCCESS) {
        std::cerr << "Error: Cannot open raw file." << std::endl;
        return QImage();
    }

    if (rawProcessor.unpack() != LIBRAW_SUCCESS) {
        std::cerr << "Error: Cannot unpack raw file." << std::endl;
        return QImage();
    }

    if (rawProcessor.dcraw_process() != LIBRAW_SUCCESS) {
        std::cerr << "Error: Cannot process raw file." << std::endl;
        return QImage();
    }

    libraw_processed_image_t* image = rawProcessor.dcraw_make_mem_image();
    if (!image) {
        std::cerr << "Error: Cannot create image from raw data." << std::endl;
        return QImage();
    }

    // Convert the raw image data to QImage
    QImage qImage;
    if (image->type == LIBRAW_IMAGE_BITMAP) {
        qImage = QImage(image->data, image->width, image->height, image->width * 3, QImage::Format_RGB888).rgbSwapped();
    } else {
        std::cerr << "Unsupported image format." << std::endl;
    }

    LibRaw::dcraw_clear_mem(image);
    return qImage;
}
