//! \file       sdl_initializer.h
//! \author     Kirill Diduk (kirill.diduk@mail.ru)
//! \date       27 March, 2021
//! \copyright  MIT License

#ifndef SDL_INITIALIZER_H_4E75EA50_3144_486F_92E8_37B1C5A52BB3
#define SDL_INITIALIZER_H_4E75EA50_3144_486F_92E8_37B1C5A52BB3

namespace frog {

    //! \brief  RAII-class that initializes SDL
    //!
    //! \details  A single instance of this class is created at the beginning
    //! of the program, and kept during the whole running time.  Destructor of
    //! this class performs shutdown of SDL.
    //!
    //! \warning  Although there should be exactly one instance of this class
    //! in the program, there are no measures that prevent from creating many
    //! instances.
    //!
    class sdl_initializer final {
    public:
        //! \brief  Initializes SDL subsystems
        //! \throws std::runtime_error in case SDL initialization fails
        sdl_initializer();

        //! \brief  Performs shut-down of previously initialized SDL subsystems
        ~sdl_initializer();
    };
} // namespace frog

#endif // SDL_INITIALIZER_H_4E75EA50_3144_486F_92E8_37B1C5A52BB3
