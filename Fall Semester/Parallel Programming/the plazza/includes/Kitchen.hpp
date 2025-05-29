/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef KITCHEN_HPP
    #define KITCHEN_HPP

    #include <map>
    #include <mutex>
    #include <thread>
    #include <condition_variable>
    #include <ctime>
    #include <chrono>
    #include <vector>
    #include "Order.hpp"
    #include "Plazza.hpp"
/**
 * @namespace Plazza
 * The Plazza namespace contains all classes, structures, and enumerations used in the Plazza project.
 */
namespace Plazza {

    /**
     * @class DeltaTime
     * @brief Manages time tracking for various events.
     */
    class DeltaTime {
        private:
            // Private members

        public:
            /**
             * @brief Default constructor for DeltaTime.
             */
            DeltaTime();

            /**
             * @brief Default destructor for DeltaTime.
             */
            ~DeltaTime() = default;

            std::time_t afk; ///< AFK start time
            std::time_t afk_c; ///< AFK current time
            std::time_t ingredientsRegen; ///< Ingredients regeneration start time
            std::time_t ingredientsRegen_c; ///< Ingredients regeneration current time

            /**
             * @brief Updates the current AFK time.
             */
            inline void updateAFKTime() { this->afk_c = std::time(0); }

            /**
             * @brief Resets the AFK time.
             */
            inline void resetAFKTime() { this->afk = this->afk_c; this->afk_c = std::time(0); }

            /**
             * @brief Updates the ingredients regeneration time.
             */
            inline void updateIngredientsRegen() { this->ingredientsRegen = this->ingredientsRegen_c; this->ingredientsRegen_c = std::time(0); }

            /**
             * @brief Resets the ingredients regeneration time.
             */
            void resetIngredientsRegen();
    };

    /**
     * @enum MessageType
     * @brief Enumerates the types of messages that can be exchanged.
     */
    enum MessageType {
        statusRequest, ///< Request for status
        statusAnswer, ///< Answer to status request
        order, ///< Order message
        pizzaDone, ///< Notification that pizza is done
        kitchenClosing ///< Notification that kitchen is closing
    };

    /**
     * @struct header_t
     * @brief Structure representing the header of a message.
     */
    struct header_t {
        int kitchenId; ///< ID of the kitchen sending/receiving the message
        MessageType type; ///< Type of the message
        int bodySize; ///< Size of the message body
    };

    /**
     * @struct statusAnswer_t
     * @brief Structure representing the status answer message.
     */
    struct statusAnswer_t {
        header_t header; ///< Message header
        int cookOccupied; ///< Number of cooks occupied
        char ingredients[1024]; ///< Ingredients status
    };

    /**
     * @struct order_t
     * @brief Structure representing an order message.
     */
    struct order_t {
        header_t header; ///< Message header
        PIZZAORDER order; ///< Pizza order details
        int orderId; ///< ID of the order
    };

    /**
     * @struct pizzaDone_t
     * @brief Structure representing a pizza done message.
     */
    struct pizzaDone_t {
        header_t header; ///< Message header
        int orderId; ///< ID of the order
        int pizzaId; ///< ID of the pizza
    };

    /**
     * @class Kitchen
     * @brief Manages the operations of a kitchen.
     */
    class Kitchen {
        private:
            Option option; ///< Options for the kitchen
            pid_t pid; ///< Process ID for the kitchen

        public:
            /**
             * @brief Constructor for the Kitchen class.
             * @param option Reference to the Option object.
             * @param cfd Child file descriptor.
             * @param pfd Parent file descriptor.
             * @param id ID of the kitchen.
             * @param pizzaName Name of the pizza.
             * @param cookingTime Time required for cooking.
             * @param orderId ID of the order.
             */
            Kitchen(Option &option, int cfd, int pfd, int id, std::string pizzaName, int cookingTime, int orderId);

            /**
             * @brief Destructor for the Kitchen class.
             */
            ~Kitchen();

            /**
             * @brief Custom copy constructor.
             * @param other The other Kitchen object to copy from.
             */
            Kitchen(const Kitchen& other);

            /**
             * @brief Custom copy assignment operator.
             * @param other The other Kitchen object to copy from.
             * @return Reference to the assigned Kitchen object.
             */
            Kitchen& operator=(const Kitchen& other);

            std::string pizzaName; ///< Name of the pizza
            DeltaTime time; ///< Time tracking for the kitchen
            int cookingTime; ///< Time required for cooking
            int orderId; ///< ID of the order
            int cookOccupied = 0; ///< Number of cooks occupied
            std::map<Ingredients, int> ingredients; ///< Ingredients available in the kitchen

            int childFd; ///< Child file descriptor
            int parentFd; ///< Parent file descriptor
            int kitchenId; ///< ID of the kitchen
            pthread_t thread; ///< Thread for the kitchen operations
            std::mutex mutex; ///< Mutex for thread synchronization
            std::condition_variable cond_vars; ///< Condition variable for thread synchronization
    };
}

#endif /* KITCHEN_HPP */
