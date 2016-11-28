//
// Created by Javier on 21/11/2016.
//

#include <boost/uuid/string_generator.hpp>
#include "Api.h"
#include "../business_logic/BuyerUseCases.h"
#include "JsonSerializer.h"


using namespace ashop::presentation;


Api::Api(crow::SimpleApp &app,
         ashop::business_logic::BuyerUseCases &buyer_use_cases)
        : app(app),
          buyer_use_cases(buyer_use_cases) {

    this->initializeRouting();
}


/*
 * REST API routing intialization goes here:
 *  - URL, query-string parameters, method ==> controller
 *  - ...
 */
void Api::initializeRouting() {

    CROW_ROUTE(this->app, "/help")
            ([this](const crow::request &request, crow::response &response) {

                this->controller_help_get(request, response);
            });

    CROW_ROUTE(this->app, "/baskets/<string>")
            ([this](const crow::request &request,
                    crow::response &response,
                    std::string basket_id) {

                this->controller_basket_get(request, response, basket_id);
            });
}


void Api::controller_help_get(const crow::request &request, crow::response &response) {
    response.write("Help!");
    response.end();
}


void Api::controller_basket_get(const crow::request &request, crow::response &response, std::string basket_id) {

    auto basket = this->buyer_use_cases.get_basket(boost::uuids::string_generator()(basket_id));

    if (basket) {
        response.set_header("Content-Type", "application/json");

        json11::Json json{JsonSerializer::to_map(basket.get())};
        response.write(json.dump());
    }

    response.end();
}
