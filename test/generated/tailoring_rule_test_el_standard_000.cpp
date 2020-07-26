// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Warning! This file is autogenerated.
#include <boost/text/collation_table.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/data/all.hpp>

#ifndef LIMIT_TESTING_FOR_CI
#include <boost/text/save_load_table.hpp>

#include <boost/filesystem.hpp>
#endif

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](std::string const & s) { std::cout << s; };
auto const warning = [](std::string const & s) {};

collation_table make_save_load_table()
{
#ifdef LIMIT_TESTING_FOR_CI
    std::string const table_str(data::el::standard_collation_tailoring());
    return tailored_collation_table(
        table_str,
        "el::standard_collation_tailoring()", error, warning);
#else
    if (!exists(boost::filesystem::path("el_standard.table"))) {
        std::string const table_str(data::el::standard_collation_tailoring());
        collation_table table = tailored_collation_table(
            table_str,
            "el::standard_collation_tailoring()", error, warning);
        save_table(table, "el_standard.table.0");
        boost::filesystem::rename("el_standard.table.0", "el_standard.table");
    }
    return load_table("el_standard.table");
#endif
}
collation_table const & table()
{
    static collation_table retval = make_save_load_table();
    return retval;
}
TEST(tailoring, el_standard_000_001)
{
}
