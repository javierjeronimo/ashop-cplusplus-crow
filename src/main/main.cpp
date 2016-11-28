
#include <iostream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

// WTF!!!
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wdeprecated-declarations"

#include <crow_all.h>

#pragma clang diagnostic pop

#include "../ashop/presentation/Api.h"
#include "../ashop/infrastructure/impl/memory/BasketRepositoryMemory.h"

namespace po = boost::program_options;

using namespace ashop::presentation;

/**
 * Process program options and show help in case it was asked for.
 *
 * @param argc
 * @param argv
 * @return 0 to do nothing, "exit code" in eny other case
 */
int processOptions(int argc, const char *argv[]);


/**
 * Main entry point
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char *argv[]) {

    if (int exitCode = processOptions(argc, argv)) {
        return exitCode;
    }

    crow::SimpleApp app;

    // Manual DI
    ashop::infrastructure::impl::memory::BasketRepositoryMemory basket_repository;
    ashop::business_logic::BuyerUseCases                        buyer_use_cases(basket_repository);

    // API
    Api api(app, buyer_use_cases);

    app.port(18080).run();
}


int processOptions(int argc, const char *argv[]) {
    po::options_description helpDescription("Allowed options");
    helpDescription.add_options()
            ("helpController", "produce helpController message");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, helpDescription), vm);
    po::notify(vm);

    if (vm.count("helpController")) {
        std::cout << helpDescription << "\n";
        return 1;
    }

    return 0;
}
