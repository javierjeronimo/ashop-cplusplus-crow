//
// Created by Javier on 21/11/2016.
//

#ifndef ASHOP_CPLUSPLUS_API_H
#define ASHOP_CPLUSPLUS_API_H

#include "../ashop.h"

// WTF!!!
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <crow_all.h>

#pragma clang diagnostic pop

#include "../business_logic/BuyerUseCases.h"

namespace ashop {

    /**
     * It is the presentation level which is coupled with API technologies: Crow framework, and thus, Boost ASIO for networking, JSON serialization, and so.
     */
    namespace presentation {

        /**
         * A Shop REST API
         */
        class Api {

        public:

            /**
             * Constructor
             * @param app Crow app to use as central controller
             * @param buyer_use_cases Dependency injection
             * @return
             */
            Api(crow::SimpleApp &app,
                ashop::business_logic::BuyerUseCases &buyer_use_cases);

        protected:
            /**
             * Initializes API routes
             */
            void initializeRouting();

            /**
             * CONTROLLER: Help
             * @return
             */
            void controller_help_get(const crow::request &request, crow::response &response);

            /**
             * CONTROLLER: Get shopping basket contents
             * @param request
             * @param response
             * @param basket_id
             */
            void controller_basket_get(const crow::request &request, crow::response &response, std::string basket_id);

        protected:
            /** Crow app */
            crow::SimpleApp &app;

            /** Business Use Cases */
            ashop::business_logic::BuyerUseCases &buyer_use_cases;
        };

    }
}

#endif //ASHOP_CPLUSPLUS_API_H
