//
// Created by Javier on 22/11/2016.
//

#ifndef ASHOP_CPLUSPLUS_BUYERUSECASES_H
#define ASHOP_CPLUSPLUS_BUYERUSECASES_H

#include "../ashop.h"

#include "../infrastructure/BasketRepositoryBase.h"
#include "../infrastructure/BasketBase.h"

#include <memory>
#include <boost/optional.hpp>
#include <boost/uuid/uuid.hpp>

namespace ashop {

    /**
     * Business logic layer includes:
     *  - Use cases: orchestration of calls to services and repositories to implement every use case
     *  - Services/Domain: common logic coupled
     */
    namespace business_logic {

        class DLL_PUBLIC BuyerUseCases {

        public:
            /**
             * Constructor
             * @param basket_repository Dependency injection: repository storing baskets (maybe a RDBS)
             */
            BuyerUseCases(ashop::infrastructure::BasketRepositoryBase &basket_repository);

            /**
             * Returns a given shopping basket.
             * @param uuid Unique ID of basket
             * @return Basket if it exists
             */
            boost::optional<std::shared_ptr<ashop::infrastructure::BasketBase>> get_basket(
                    const boost::uuids::uuid &uuid);

        protected:
            /** Baskets repository */
            ashop::infrastructure::BasketRepositoryBase &basket_repository;
        };

    }
}


#endif //ASHOP_CPLUSPLUS_BUYERUSECASES_H
