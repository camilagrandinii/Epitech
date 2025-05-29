#include "ICP.hpp"
#include <PizzaOrder.hpp>

Plazza::MessageQueue::MessageQueue() {
    queueId = msgget(MESSAGE_QUEUE_KEY, IPC_CREAT | 0666);
    if (queueId == -1) {
        std::cerr << "Error creating/opening message queue." << std::endl;
        exit(EXIT_FAILURE);
    }
}

Plazza::MessageQueue::~MessageQueue() {
    if (msgctl(queueId, IPC_RMID, nullptr) == -1) {
            std::cerr << "Error removing message queue." << std::endl;
    }
}

void Plazza::MessageQueue::sendMessage(long messageType, const std::string& messageText) {
    Message message;
    message.messageType = messageType;
    strncpy(message.messageText, messageText.c_str(), MAX_MESSAGE_SIZE - 1);
    message.messageText[MAX_MESSAGE_SIZE - 1] = '\0';

    // Send the message
    if (msgsnd(queueId, &message, sizeof(Message) - sizeof(long), 0) == -1) {
        std::cerr << "Error sending message." << std::endl;
    }
}

std::string Plazza::MessageQueue::receiveMessage(long messageType) {
    Message message;
    // Receive the message
    if (msgrcv(queueId, &message, sizeof(Message) - sizeof(long), messageType, 0) == -1) {
        std::cerr << "Error receiving message." << std::endl;
        return "";
    }
    return std::string(message.messageText);
}

bool Plazza::MessageQueue::hasMessage() {
    Plazza::Message message;
    if (msgrcv(queueId, &message, sizeof(message.messageText), 0, IPC_NOWAIT | MSG_NOERROR) == -1) {
        if (errno == ENOMSG) {
            return false;
        } else {
            perror("msgrcv failed");
        }
    }
    return true;
}

// messageQueue << order; // send
void Plazza::MessageQueue::operator<<(PizzaOrder &pizzaOrder)
{
    sendMessage(1, pizzaOrder.serialize());
}

// messageQueue >> order; // receive
Plazza::PizzaOrder Plazza::MessageQueue::operator>>(std::unique_ptr<Plazza::PizzaOrder> &pizzaOrder)
{
    std::string answerMessage = receiveMessage(1);
    return pizzaOrder.get()->deserialize(answerMessage);
}

// send status
void Plazza::MessageQueue::operator<<(Status &status)
{
    sendMessage(2, status.serialize());
}

// receive status
Plazza::Status Plazza::MessageQueue::operator>>(Status &status)
{
    std::string answerMessage = receiveMessage(2);
    return status.deserialize(answerMessage);
}

// send status request
void Plazza::MessageQueue::operator<<(std::string &request)
{
    sendMessage(3, "statusRequest");
}

// receive status request
std::string Plazza::MessageQueue::operator>>(std::string &request)
{
    return receiveMessage(3);
}