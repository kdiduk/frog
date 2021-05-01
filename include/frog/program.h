//! \file       program.h
//! \brief      Contains definition of `program` class.
//!
//! \date       27 March, 2021
//! \copyright  MIT License

#ifndef PROGRAM_H_E791021A_5735_423D_9C51_2BEB58D663DB
#define PROGRAM_H_E791021A_5735_423D_9C51_2BEB58D663DB

#include <memory>

#include "frog/vec.h"

namespace frog {

    class renderer;
    class scene;

    //! \brief Main class (entry point) responsible for running the program.
    //!
    //! \details The class `program` implements the main event loop (game loop)
    //! of the game. It also performs initialization and finalization of all
    //! the subsystems.
    //!
    //! There should be only one single instance of this class which is then
    //! accessible using static method `instance()`.
    //!
    //! \warning Attempt to create more than one instance of this class will
    //! throw `runtime_error` exception.
    //!
    class program final {
    public:
        program(int argc, char** argv);
        ~program();

        //! \brief Runs the game with the specified scene.
        //!
        //! \details This method starts the main game loop.
        //!
        //! \note Attempt to call this method twice recursively
        //! will throw `runtime_exception`.
        //!
        //! \param s - starting scene of the game
        //! \return 0 in case of success or error code in case of failure
        int run(std::shared_ptr<scene> s);

        //! \brief Returns the renderer object associated with the window
        //! of the program.
        //!
        const class renderer& renderer() const;

        void change_scene(std::shared_ptr<scene> s);

        //! \brief Returns program's window logical size in pixels
        vec<short> window_size() const;

        //! \brief Returns a pointer to the instance of the class `program`
        //! or `nullptr` if no such instance has been created yet.
        //!
        static program* instance();

    private:
        static program* m_instance;

        struct impl;
        std::unique_ptr<impl> m_pimpl;
    };
} // namespace frog

#endif // PROGRAM_H_E791021A_5735_423D_9C51_2BEB58D663DB
