//
// Created by Javier on 23/11/2016.
//

#ifndef ASHOP_CPLUSPLUS_BASKETPOD_H
#define ASHOP_CPLUSPLUS_BASKETPOD_H

#include "../ashop.h"

#include <memory>
#include <string>
#include <list>

#include <boost/units/quantity.hpp>
#include <boost/units/systems/cgs/mass.hpp>
#include <boost/units/systems/cgs/volume.hpp>

#include "ItemBase.h"


namespace ashop {
    namespace infrastructure {

        /**
         * A line in the basket: (item, quantity, ...)
         */
        struct DLL_PUBLIC BasketLineBase {

            /** Item */
            ItemBase item;

            /** Quantity of the item, measured in either units, kilograms or liters */
            unsigned short                                    unit_quantity   = 0;
            boost::units::quantity<boost::units::cgs::mass>   mass_quantity   = 0.0 * boost::units::cgs::gram;
            boost::units::quantity<boost::units::cgs::volume> volume_quantity =
                                                                      0.0 * boost::units::cgs::cubic_centimeter;
        };

        /**
         * A basket
         */
        struct DLL_PUBLIC BasketBase {

            /** Items within the basket */
            std::list<BasketLineBase> items{};

            /** Whether basket is paid or not */
            bool paid{false};
        };

    }
}

#endif //ASHOP_CPLUSPLUS_BASKETPOD_H
