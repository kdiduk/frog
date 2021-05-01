//! \file       button.h
//! \date       21 April, 2021
//! \copyright  MIT License

#ifndef BUTTON_H_72DC6697_C21A_40C0_9804_A8AEF2623DB2
#define BUTTON_H_72DC6697_C21A_40C0_9804_A8AEF2623DB2

#include <functional>
#include <memory>
#include <vector>

#include "frog/node.h"
#include "frog/rect.h"


namespace frog {
    class texture;

    //! \brief A node that represents a touch button.
    class button : public node {
    public:
        //! \brief Creates a button with a given texture,
        //! and on a given position.
        //!
        //! \details The size of the button is determined by the size
        //! of the texture.
        //!
        //! \param tx texture of the button
        //! \param pos position of the button (top left corner) on the screen
        //!
        explicit button(std::shared_ptr<texture> tx, vec<int> pos);

        //! \brief Creates a button with a given texture and given size,
        //! on a given position.
        //!
        //! \details The texture will be stretched or shrinked to the size
        //! of the button specified.
        //!
        //! \param tx texture of the button
        //! \param pos position of the button (top left corner) on the screen
        //!
        explicit button(
                std::shared_ptr<texture> tx,
                vec<int> pos,
                vec<int> size);

        void listen_press(std::function<void()> listener);

        void remove_listeners();
    protected:
        void render(const renderer& rr) const override;

        void finger_down_event(vec<int> pos) override;
        void finger_up_event(vec<int> pos) override;

    private:
        std::shared_ptr<texture> m_texture;
        rect m_rect;
        bool m_pressed = false;
        std::vector<std::function<void()>> m_listeners;
    }; // class button
} // namespace frog

#endif // BUTTON_H_72DC6697_C21A_40C0_9804_A8AEF2623DB2
