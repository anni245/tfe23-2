#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include <random>

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    // Create an instance (app) of class CLI::App
    CLI::App app{PROJECT_NAME};
    
    auto count{20};

    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        // Add an command line option (argument) -c or --count
        app.add_option("-c, --count", count, "counter(default: 20)");
        // Evaluate the arguments
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());
    
    fmt::print("Counter: {}\n", count);

    std::vector<unsigned int> values;

    std::random_device r;

    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);

    // filling the vector with random numbers
    for(auto i{0}; i < count; i++) {
        values.push_back(uniform_dist(e1));
    }

    // output the vector
    for(auto i{0}; i < values.size(); i++) {
        fmt::print("Value of element {}: {}\n", i, values.at(i));
    }

    return 0; /* exit gracefully*/
}
