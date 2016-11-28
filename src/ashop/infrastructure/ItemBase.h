//
// Created by Javier on 23/11/2016.
//

#ifndef ASHOP_CPLUSPLUS_ITEM_H
#define ASHOP_CPLUSPLUS_ITEM_H

#include "../ashop.h"

#include <string>

#include <boost/units/quantity.hpp>
#include <boost/units/systems/cgs/mass.hpp>
#include <boost/units/systems/cgs/volume.hpp>

namespace ashop {
    namespace infrastructure {

        /**
         * Price of an item.
         * This includes:
         *  - amount of money
         *  - currency
         *  - if price is (only one of):
         *    - per unit: how many units are included in the price
         *    - per mass: how many grams
         *    - per volume: how many cubic-centimeters (10-3 liters)
         */
        struct DLL_PUBLIC ItemPriceBase {
            ItemPriceBase(double ammount, std::string currency)
                    : ammount(ammount),
                      currency(currency) {};

            /** Ammount in currency */
            double ammount = 0.0;

            /** Currency */
            std::string currency = "EUR";

            /** Price per units */
            unsigned short                                    unit_price   = 0;
            boost::units::quantity<boost::units::cgs::mass>   mass_price   = 0.0 * boost::units::cgs::gram;
            boost::units::quantity<boost::units::cgs::volume> volume_price = 0.0 * boost::units::cgs::cubic_centimeter;
        };

        /**
         * An item of the shop
         */
        struct DLL_PUBLIC ItemBase {

            /** Display name of the item */
            std::string name;

            /** Item's price */
            ItemPriceBase price = ItemPriceBase(0.0, "EUR");
        };

    }
}

#endif //ASHOP_CPLUSPLUS_ITEM_H
