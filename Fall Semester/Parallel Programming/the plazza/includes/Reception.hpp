/*
** EPITECH PROJECT, 2024
** file
** File description:
** file
*/

#ifndef RECEPTION_HPP
    #define RECEPTION_HPP

    #include <mutex>
    #include <thread>
    #include <condition_variable>
    #include "Cook.hpp"
    #include "Kitchen.hpp"
    #include "Plazza.hpp"

    #define FIFO_PARENT "/tmp/fifo_parent"
    #define FIFO_CHILD "/tmp/fifo_child"

    #define ORDERS std::vector<Plazza::Order>
    #define KITCHEN std::vector<Plazza::Kitchen>
    #define PIZZALIST std::vector<Plazza::APizza>

namespace Plazza {
    /**
     * @class Reception
     * @brief Manages the reception and distribution of pizza orders to various kitchens.
     */
    class Reception {
        private:
            Option option; ///< Options for the reception
            ORDERS orders; ///< List of orders
            PIZZALIST pizzaList; ///< List of available pizzas
            int orderNumber = 0; ///< Current order number
            int kitchenNumber = 0; ///< Current kitchen number

            pthread_t thread; ///< Thread for the reception operations

        public:
            std::vector<pthread_t> kitchenThread; ///< Vector of kitchen threads
            KITCHEN kitchens; ///< List of kitchens
            /**
             * @brief Constructor for the Reception class.
             * @param option Reference to the Option object.
             * @param pizzaList Reference to the list of available pizzas.
             */
            Reception(Option &option, PIZZALIST &pizzaList);

            /**
             * @brief Destructor for the Reception class.
             */
            ~Reception();

            /**
             * @brief Finds an available kitchen.
             * @return The ID of an available kitchen.
             */
            int findAKitchen(void);

            /**
             * @brief Runs the reception operations.
             */
            void Run(void);

            /**
             * @brief Assigns an order to a kitchen.
             * @param order Reference to the pizza order.
             */
            void assignOrderToKitchen(PIZZAORDER &order);

            /**
             * @brief Gets the list of orders.
             * @return Reference to the list of orders.
             */
            [[nodiscard]] ORDERS &getOrders(void) noexcept;

            /**
             * @brief Gets the list of kitchens.
             * @return Constant reference to the list of kitchens.
             */
            [[nodiscard]] const KITCHEN &getKitchen(void) const noexcept;

            /**
             * @brief Parses the input string.
             * @param str The input string to parse.
             * @return True if parsing is successful, false otherwise.
             */
            [[nodiscard]] bool parseInput(const std::string &str);

            std::mutex mutex; ///< Mutex for thread synchronization
            std::condition_variable cond_vars; ///< Condition variable for thread synchronization

            int parentFd; ///< Parent file descriptor
            int childFd; ///< Child file descriptor
            std::vector<int> activeKitchenId; ///< Vector of active kitchen IDs
            bool stop = false; ///< Flag to stop the reception operations
    };
}

/**
 * @brief Parses the configuration file to get a list of available pizzas.
 * @param pathToConfFile The path to the configuration file.
 * @return A vector of available pizzas.
 */
std::vector<Plazza::APizza> parseConfigurationFile(std::filesystem::path pathToConfFile);

#endif /* RECEPTION_HPP */
