#ifndef RAWFILEEXTENSIONS_H
#define RAWFILEEXTENSIONS_H

#include <array>
#include <string_view>

namespace ImageProcessing {

constexpr std::array<std::string_view, 19> rawFileExtensions = {
    ".arw",   // Sony
    ".cr2",   // Canon
    ".cr3",   // Canon
    ".dng",   // Adobe, Leica, OnePlus, etc.
    ".nef",   // Nikon
    ".orf",   // Olympus
    ".pef",   // Pentax
    ".raf",   // Fujifilm
    ".rw2",   // Panasonic
    ".srw",   // Samsung
    ".x3f",   // Sigma
    ".raw",   // Generic
    ".rwl",   // Leica
    ".kdc",   // Kodak
    ".3fr",   // Hasselblad
    ".mef",   // Mamiya
    ".mrw",   // Minolta
    ".iiq",   // Phase One
};

} // namespace ImageProcessing


#endif // RAWFILEEXTENSIONS_H
