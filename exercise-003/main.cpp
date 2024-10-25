#include <fmt/chrono.h>
#include <fmt/format.h>

#include <algorithm> /* needed for the std::sort */
#include <random>
#include <vector> /* Does provide std::vector */

#include "CLI/CLI.hpp"
#include "config.h"
#include "myvector.hpp"

auto main(int argc, char** argv) -> int
{
    CLI::App app{PROJECT_NAME}; /* create an instance of an App with the variable name app*/
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError& e)
    {
        return app.exit(e);
    }

    MyVector vec;
    
    return 0; /* exit gracefully*/
}
