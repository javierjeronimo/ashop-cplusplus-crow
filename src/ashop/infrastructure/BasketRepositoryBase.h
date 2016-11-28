//
// Created by Javier on 23/11/2016.
//

#ifndef ASHOP_CPLUSPLUS_BASKETREPOSITORYBASE_H
#define ASHOP_CPLUSPLUS_BASKETREPOSITORYBASE_H

#include "../ashop.h"

#include <memory>
#include <tuple>
#include <boost/uuid/uuid.hpp>

#include "BasketBase.h"

namespace ashop {
    /**
     * Infrastructure layer contains all repositories (databases, external data, external services...) of data the system manages.
     */
    namespace infrastructure {

        /**
         * Interface for every implementation of a basket repository.
         */
        struct DLL_PUBLIC BasketRepositoryBase {

            /**
             * Retrieves a basket by its ID.
             * @param id
             * @return Basket
             */
            virtual std::shared_ptr<BasketBase> get_by_id(const boost::uuids::uuid &id)
            = 0;

            /**
             * Updates (saves) a basket in the repository.
             * @param basket and ID
             */
            virtual std::tuple<boost::uuids::uuid, std::shared_ptr<BasketBase>> save(
                    std::shared_ptr<BasketBase> basket)= 0;
        };

    }
}

#endif //ASHOP_CPLUSPLUS_BASKETREPOSITORYBASE_H
