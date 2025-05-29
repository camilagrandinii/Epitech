/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef ICP_HPP
    #define ICP_HPP

    #include <iostream>
    #include <string>
    #include <cstring>
    #include <cstdlib>
    #include <unistd.h>
    #include <sys/types.h>
    #include <sys/ipc.h>
    #include <sys/msg.h>
    #include <utility>

    #include "Status.hpp"
    #include "PizzaOrder.hpp"

    #define MAX_MESSAGE_SIZE 1024
    #define MESSAGE_QUEUE_KEY 1234
    namespace Plazza
    {
        enum MessageType {
            order,
            status
        };

        struct Message {
        long messageType;
        char messageText[MAX_MESSAGE_SIZE];
    };

        class MessageQueue {
            private:
                int queueId;

            public:
                MessageQueue();
                ~MessageQueue();

                void sendMessage(long messageType, const std::string& messageText); // <<
                std::string receiveMessage(long messageType); // >>

                void operator<<(PizzaOrder &pizzaOrder); // send pizza
                Plazza::PizzaOrder operator>>(std::unique_ptr<Plazza::PizzaOrder>& pizzaOrder); // receive pizza
                void operator<<(Status &status); // send status
                Status operator>>(Status &status); // receive status
                void operator<<(std::string &request); // send status request
                std::string operator>>(std::string &request); // receive status request

                bool hasMessage();
        };
    }

    #endif /* ICP_HPP */