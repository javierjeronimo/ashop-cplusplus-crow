#include <iostream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/parsers.hpp>

#include <crow_all.h>

namespace po = boost::program_options;

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

    CROW_ROUTE(app, "/")
            ([]() {
                return "Hello world!";
            });

    app.port(18080).run();
}


int processOptions(int argc, const char *argv[]) {
    po::options_description helpDescription("Allowed options");
    helpDescription.add_options()
            ("help", "produce help message");

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, helpDescription), vm);
    po::notify(vm);

    if (vm.count("help")) {
        std::cout << helpDescription << "\n";
        return 1;
    }

    return 0;
}
