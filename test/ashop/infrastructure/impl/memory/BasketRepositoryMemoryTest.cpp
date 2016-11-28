//
// Created by Javier on 27/11/2016.
//

#include "BasketRepositoryMemoryTest.h"

namespace ashopi = ashop::infrastructure;

using namespace fakeit;
using namespace std;


SCENARIO("basket repository (in memory) use cases") {

    GIVEN("an implementation") {
        ashopi::impl::memory::BasketRepositoryMemory test_object{};

        WHEN("we ask for a basket with an empty ID") {
            auto basket = test_object.get_by_id(boost::uuids::uuid{});

            THEN("we don't get back any basket") {
                REQUIRE(nullptr == basket);
            }
        }

        WHEN("we save a basket") {
            auto basket = make_shared<ashopi::BasketBase>();

            auto result = test_object.save(basket);
            THEN("we can get it back by id") {
                REQUIRE(basket == test_object.get_by_id(get<0>(result)));
            }
        }
    }
}
