//
// Created by Javier on 27/11/2016.
//

#include "JsonSerializer.h"

#include <vector>


using namespace ashop::presentation;
using namespace std;


std::map<std::string, json11::Json> JsonSerializer::to_map(std::shared_ptr<ashop::infrastructure::BasketBase> basket) {

    map<string, json11::Json> result;


    // Add Basket attributes
    auto      items = vector<json11::Json>{};
    for (auto i : basket->items) {
        items.push_back(JsonSerializer::to_map(i));
    }
    result["items"] = items;


    result["paid"] = basket->paid;


    return result;
}


std::map<std::string, json11::Json>
JsonSerializer::to_map(ashop::infrastructure::BasketLineBase &basket_line) {

    // Create from Item
    auto result = JsonSerializer::to_map(basket_line.item);


    // And add BasketLine attributes
    result["unit_quantity"]   = basket_line.unit_quantity;
    result["mass_quantity"]   = basket_line.mass_quantity.value();
    result["volume_quantity"] = basket_line.volume_quantity.value();


    return result;
}


std::map<std::string, json11::Json> JsonSerializer::to_map(ashop::infrastructure::ItemBase &item) {

    // Create a map from price
    auto result = JsonSerializer::to_map(item.price);

    // And add Item's attributes
    result["name"] = item.name;


    return result;
}


std::map<std::string, json11::Json> JsonSerializer::to_map(ashop::infrastructure::ItemPriceBase &item_price) {

    map<string, json11::Json> result;


    // Add ItemPrice attributes
    result["ammount"]      = item_price.ammount;
    result["currency"]     = item_price.currency;
    result["unit_price"]   = item_price.unit_price;
    result["mass_price"]   = item_price.mass_price.value();
    result["volume_price"] = item_price.volume_price.value();


    return result;
}
