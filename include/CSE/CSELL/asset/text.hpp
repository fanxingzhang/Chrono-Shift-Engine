#ifndef CSELL_ASSETS_TEXT_HPP
#define CSELL_ASSETS_TEXT_HPP

#include <CSE/CSELL/asset/asset.hpp>

class AssetManager;

namespace CSELL { namespace Assets {
    class TextAsset : public Asset {
    friend class AssetManager;
    protected:
        TextAsset();
        ~TextAsset();
    };
}}

#endif