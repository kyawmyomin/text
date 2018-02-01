
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
            data::th::standard_collation_tailoring(),
            "th::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, th_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e5a),
        std::vector<uint32_t>(1, 0x0e2f),
        table(), collation_strength::primary),
        -1);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e5a),
        std::vector<uint32_t>(1, 0x0e2f),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e5b),
        std::vector<uint32_t>(1, 0x0e46),
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e4e),
        std::vector<uint32_t>(1, 0x0e4c),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e4e),
        std::vector<uint32_t>(1, 0x0e4c),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e30),
        std::vector<uint32_t>(1, 0x0e4d),
        table(), collation_strength::primary),
        -1);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e30),
        std::vector<uint32_t>(1, 0x0e4d),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e32),
        std::vector<uint32_t>(1, 0x0e45),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e32),
        std::vector<uint32_t>(1, 0x0e45),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0e32, 0x0e4d},
        std::vector<uint32_t>{0x0e4d, 0x0e32},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0e32, 0x0e4d},
        std::vector<uint32_t>{0x0e4d, 0x0e32},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0e4d, 0x0e32},
        std::vector<uint32_t>(1, 0x0e33),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0e4d, 0x0e32},
        std::vector<uint32_t>(1, 0x0e33),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0e45, 0x0e4d},
        std::vector<uint32_t>{0x0e4d, 0x0e45},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0e45, 0x0e4d},
        std::vector<uint32_t>{0x0e4d, 0x0e45},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0e44),
        std::vector<uint32_t>(1, 0x0e3a),
        table(), collation_strength::primary),
        -1);
}
