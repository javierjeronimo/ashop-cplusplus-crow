//
// Created by Javier on 23/11/2016.
//

#ifndef ASHOP_CPLUSPLUS_BASKETREPOSITORYMEMORY_H
#define ASHOP_CPLUSPLUS_BASKETREPOSITORYMEMORY_H

#include "../../../ashop.h"

#include "../../BasketRepositoryBase.h"

#include <map>

namespace ashop {
    namespace infrastructure {
        namespace impl {
            namespace memory {

                /** Basket repository implemented in memory */
                class DLL_PUBLIC BasketRepositoryMemory : public ashop::infrastructure::BasketRepositoryBase {
                public:
                    /**
                     * Returns (or creates) a basket by id
                     * @param id
                     * @return Existing o new empty basket by id.
                     *         nullptr if basket doesn't exist
                     */
                    std::shared_ptr<BasketBase> get_by_id(const boost::uuids::uuid &id) override;

                    /**
                     * Does nothing...
                     * @param basket
                     * @return Same basket and ID...
                     */
                    std::tuple<boost::uuids::uuid, std::shared_ptr<BasketBase>> save(
                            std::shared_ptr<BasketBase> basket) override;

                private:
                    /**
                     * Pesists a basket both in map and reverse-map
                     * @param id
                     * @param basket
                     */
                    void persist_basket(const boost::uuids::uuid &id,
                                        const std::shared_ptr<ashop::infrastructure::BasketBase> &basket);

                private:
                    std::map<boost::uuids::uuid, std::shared_ptr<BasketBase>> baskets;
                    std::map<std::shared_ptr<BasketBase>, boost::uuids::uuid> baskets_ids;
                };
            }
        }
    }
}

#endif //ASHOP_CPLUSPLUS_BASKETREPOSITORYMEMORY_H
