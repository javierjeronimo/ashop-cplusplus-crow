//
// Created by Javier on 22/11/2016.
//

#include "BuyerUseCases.h"

using namespace ashop::business_logic;

BuyerUseCases::BuyerUseCases(ashop::infrastructure::BasketRepositoryBase &basket_repository) :
        basket_repository(basket_repository) {

}

boost::optional<std::shared_ptr<ashop::infrastructure::BasketBase>> BuyerUseCases::get_basket(
        const boost::uuids::uuid &uuid) {

    auto basket = this->basket_repository.get_by_id(uuid);
    if (nullptr == basket) {
        return {};
    };

    return basket;
}
