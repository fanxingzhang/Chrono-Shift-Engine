#ifndef CSELL_CORE_WINDOW_HPP
#define CSELL_CORE_WINDOW_HPP

#include <string>

#include <CSE/CSU/logger.hpp>

#include <CSE/CSELL/core/inputcallbackhandler.hpp>

namespace CSELL { namespace Core {
    class Window {
    public:
        struct Settings {
            unsigned int width;
            unsigned int height;
            std::string title;
            bool resizeable;
        };

    private:
        InputCallbackHandler *callbackHandler;
        bool successfulInit;

    protected:
        virtual ~Window();
        virtual bool initializeImplementation(Window::Settings settings) = 0;
        virtual void destroyImplementation() = 0;
        virtual bool updateImplementation() = 0;
        virtual double getTimeImplementation() = 0;
        virtual bool useContextImplementation() = 0;
        virtual bool setCursorModeImplementation(bool enable) = 0;

    public:
        bool initialize(Window::Settings settings);
        void destroy();

        bool registerInputCallbackHandler(InputCallbackHandler *cbh);

        bool handleKeyInput(InputCallbackHandler::KeyboardKey key, InputCallbackHandler::InputAction action);
        bool handleMousePosInput(double xpos, double ypos, double xrel, double yrel);
        bool handleMouseButtonInput(InputCallbackHandler::MouseButton button, InputCallbackHandler::InputAction action);
        bool handleMouseScrollInput(double xoffset, double yoffset);
        bool handleMouseEnterLeaveInput(bool entered);

        bool handleWindowResizeInput(unsigned int width, unsigned int height);
        bool handleWindowCloseInput();

        bool update();
        double getTime();
        bool useContext();
        bool setCursorMode(bool enable);
    };
}}

#endif
