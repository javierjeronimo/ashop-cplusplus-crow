//
// Created by Javier on 24/11/2016.
//

#include "BuyerUseCasesTest.h"

namespace ashopb = ashop::business_logic;
namespace ashopi = ashop::infrastructure;

using namespace fakeit;
using namespace std;


SCENARIO("buyer use cases") {

    GIVEN("an implementation and a basket repository mock") {
        Mock<ashopi::BasketRepositoryBase> basket_repository_mock;
        ashopb::BuyerUseCases              test_object(basket_repository_mock.get());

        WHEN("we ask with an empty basket ID") {
            auto uuid = boost::uuids::uuid{};

            When(Method(basket_repository_mock, get_by_id).Using(uuid)).Return(nullptr);

            auto basket = test_object.get_basket(uuid);

            THEN("we don't get back any basket") {
                REQUIRE(!basket);
            }

            THEN("the repository is asked for the basket at least once") {
                REQUIRE(Verify(Method(basket_repository_mock, get_by_id).Using(uuid)) == true);
            }
        }
    }
}
