
// Warning! This file is autogenerated.
#include <boost/text/collation_tailoring.hpp>
#include <boost/text/collate.hpp>
#include <boost/text/data/all.hpp>

#include <gtest/gtest.h>

using namespace boost::text;

auto const error = [](string const & s) { std::cout << s; };
auto const warning = [](string const & s) {};

tailored_collation_element_table const & table()
{
    static tailored_collation_element_table retval =
        make_tailored_collation_element_table(
            data::ta::standard_collation_tailoring(),
            "ta::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, ta_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0b94),
        std::vector<uint32_t>(1, 0x0b82),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0b82),
        std::vector<uint32_t>(1, 0x0b83),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0bb9),
        std::vector<uint32_t>{0x0b95, 0x0bcd, 0x0bb7},
        table(), collation_strength::primary),
        -1);
}

TEST(tailoring, ta_standard_000_002)
{
}