//
// Created by Javier on 27/11/2016.
//

#ifndef ASHOP_CPLUSPLUS_BASKETJSON_H
#define ASHOP_CPLUSPLUS_BASKETJSON_H

#include "../ashop.h"

#include <string>
#include <map>

// WTF!!!
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <crow_all.h>

#pragma clang diagnostic pop

#include <json11/json11.hpp>


#include "../infrastructure/BasketBase.h"
#include "../infrastructure/ItemBase.h"

namespace ashop {
    namespace presentation {

        struct JsonSerializer {

            static std::map<std::string, json11::Json>
            to_map(std::shared_ptr<ashop::infrastructure::BasketBase> basket);

            static std::map<std::string, json11::Json> to_map(ashop::infrastructure::BasketLineBase &basket_line);

            static std::map<std::string, json11::Json> to_map(ashop::infrastructure::ItemBase &item);

            static std::map<std::string, json11::Json> to_map(ashop::infrastructure::ItemPriceBase &item);
        };

    }
}


#endif //ASHOP_CPLUSPLUS_BASKETJSON_H
