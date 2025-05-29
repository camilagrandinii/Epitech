/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef PROCESSKITCHEN_HPP
    #define PROCESSKITCHEN_HPP

    #include <memory>
    #include <unistd.h>
    #include "ICP.hpp"
    #include "Kitchen.hpp"

namespace Plazza
{
    class ProcessKitchen {
        private:
            Kitchen *kitchen = nullptr;
            MessageQueue *messageQueue = nullptr;
            pid_t pid = -1;
        public:
            ProcessKitchen(Kitchen *kitchen, MessageQueue *messageQueue);
            ProcessKitchen(const ProcessKitchen &other);
            ~ProcessKitchen();

            [[nodiscard]] const Kitchen &getKitchen(void) const noexcept;
            [[nodiscard]] const MessageQueue &getMessageQueue(void) const noexcept;
    };
}


#endif /* PROCESSKITCHEN_HPP */
