//
// Created by Javier on 23/11/2016.
//

#ifndef ASHOP_CPLUSPLUS_ITEMREPOSITORYBASE_H
#define ASHOP_CPLUSPLUS_ITEMREPOSITORYBASE_H

#include "../ashop.h"

#include <string>

#include "ItemBase.h"

namespace ashop {
    namespace infrastructure {

        struct DLL_PUBLIC ItemRepositoryBase {
            /**
             * Retrieves an item by its ID.
             * @param id
             * @return item
             */
            virtual std::shared_ptr<ItemBase> getById(const std::string id)= 0;

            /**
             * Updates (saves) an item in the repository.
             * @param item
             */
            virtual std::shared_ptr<ItemBase> update(std::shared_ptr<ItemBase> item)= 0;
        };

    }
}


#endif //ASHOP_CPLUSPLUS_ITEMREPOSITORYBASE_H
