//
// Created by Javier on 25/11/2016.
//

#ifndef ASHOP_CPLUSPLUS_BUYERUSECASESTEST_H
#define ASHOP_CPLUSPLUS_BUYERUSECASESTEST_H

#define CATCH_CONFIG_MAIN

// WTF!!!
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winconsistent-missing-override"

#include <catch.hpp>
#include <fakeit.hpp>

#pragma clang diagnostic pop


#include "../../../src/ashop/business_logic/BuyerUseCases.h"

#include <boost/uuid/uuid_generators.hpp>


// WTF!!!
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <crow_all.h>

#pragma clang diagnostic pop


#endif //ASHOP_CPLUSPLUS_BUYERUSECASESTEST_H
