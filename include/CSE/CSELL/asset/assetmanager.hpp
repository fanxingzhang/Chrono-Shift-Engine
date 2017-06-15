#ifndef CSELL_ASSETS_ASSETMANAGER_HPP
#define CSELL_ASSETS_ASSETMANAGER_HPP

#include <map>

#include <CSE/CSELL/asset/asset.hpp>
#include <CSE/CSELL/asset/image.hpp>
#include <CSE/CSELL/asset/text.hpp>

namespace CSELL { namespace Assets {
    class AssetManager {
        static unsigned int assetCount;
        static bool isInitialized;
        static std::map<unsigned int, Asset*> assets;

        static bool ensureInit();

        AssetManager();
        ~AssetManager();
    public:
        static void init();
        static void shutDown();
        static void freeAsset(Asset *asset);

        static ImageAsset *loadImage(const char *path, bool isPNG);
        static TextAsset *loadFile(const char *path);
    };
}}
#endif
