#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

#include <random>

auto print_vector(std::vector<unsigned int> values) -> void;

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

    // fill the vector with random numbers and measure the time
    std::vector<unsigned int> values;

    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 100);
    const auto start_inserting{std::chrono::steady_clock::now()};
    // filling the vector with random numbers
    for(auto i{0}; i < count; i++) {
        values.push_back(uniform_dist(e1));
    }
    const auto end_inserting{std::chrono::steady_clock::now()};
    auto elapsed_inserting =std::chrono::duration_cast<std::chrono::nanoseconds>(end_inserting - start_inserting);

    // print the results
    fmt::print("\nUnsorted List with random values (0 to {}):\n", count);
    print_vector(values);
    fmt::print("time for inserting the values: {}\n", elapsed_inserting);

    // sort the vector and measure the needed tim 
    const auto start_sorting{std::chrono::steady_clock::now()};
    std::sort(values.begin(), values.end());
    const auto end_sorting{std::chrono::steady_clock::now()};
    auto elapsed_sorting = std::chrono::duration_cast<std::chrono::nanoseconds>(end_sorting - start_sorting);

    // print the result (the sorted vector and the required time)
    fmt::print("\nSorted List with random values (0 to {}):\n", count);
    print_vector(values);
    fmt::print("time for sorting the list: {}\n", elapsed_sorting);

    return 0; /* exit gracefully*/
}

auto print_vector(std::vector<unsigned int> values) -> void
{ // output the vector
    for(auto i{0}; i < values.size(); i++) {
        fmt::print("Value of element {}: {}\n", i, values.at(i));
    }
}