//
// Created by Javier on 23/11/2016.
//

#include <boost/uuid/random_generator.hpp>
#include "BasketRepositoryMemory.h"

using namespace std;
using namespace ashop::infrastructure::impl::memory;

std::shared_ptr<ashop::infrastructure::BasketBase>
BasketRepositoryMemory::get_by_id(const boost::uuids::uuid &id) {

    if (id.is_nil()) {
        return nullptr;
    }

    auto result = this->baskets[id];

    if (nullptr == result) {
        result = make_shared<BasketBase>();
        this->persist_basket(id, result);
    }

    return result;
}

std::tuple<boost::uuids::uuid, std::shared_ptr<ashop::infrastructure::BasketBase>> BasketRepositoryMemory::save(
        std::shared_ptr<ashop::infrastructure::BasketBase> basket) {

    auto id = this->baskets_ids[basket];

    if (id.is_nil()) {
        id = boost::uuids::random_generator()();
        this->persist_basket(id, basket);
    }

    return {id, basket};
}

void BasketRepositoryMemory::persist_basket(const boost::uuids::uuid &id,
                                            const std::shared_ptr<ashop::infrastructure::BasketBase> &basket) {
    this->baskets[id]         = basket;
    this->baskets_ids[basket] = id;
}
