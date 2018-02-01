
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
            data::cy::standard_collation_tailoring(),
            "cy::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, cy_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0043),
        std::vector<uint32_t>{0x0063, 0x0068},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0063, 0x0068},
        std::vector<uint32_t>{0x0043, 0x0068},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0063, 0x0068},
        std::vector<uint32_t>{0x0043, 0x0068},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0043, 0x0068},
        std::vector<uint32_t>{0x0043, 0x0048},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0043, 0x0068},
        std::vector<uint32_t>{0x0043, 0x0048},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0044),
        std::vector<uint32_t>{0x0064, 0x0064},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0064, 0x0064},
        std::vector<uint32_t>{0x0044, 0x0064},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0064, 0x0064},
        std::vector<uint32_t>{0x0044, 0x0064},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x0064},
        std::vector<uint32_t>{0x0044, 0x0044},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x0064},
        std::vector<uint32_t>{0x0044, 0x0044},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0046),
        std::vector<uint32_t>{0x0066, 0x0066},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0066, 0x0066},
        std::vector<uint32_t>{0x0046, 0x0066},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0066, 0x0066},
        std::vector<uint32_t>{0x0046, 0x0066},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0046, 0x0066},
        std::vector<uint32_t>{0x0046, 0x0046},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0046, 0x0066},
        std::vector<uint32_t>{0x0046, 0x0046},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0047),
        std::vector<uint32_t>{0x006e, 0x0067},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0067},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0067},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0047},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0067},
        std::vector<uint32_t>{0x004e, 0x0047},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x004c),
        std::vector<uint32_t>{0x006c, 0x006c},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006c, 0x006c},
        std::vector<uint32_t>{0x004c, 0x006c},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x006c, 0x006c},
        std::vector<uint32_t>{0x004c, 0x006c},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004c, 0x006c},
        std::vector<uint32_t>{0x004c, 0x004c},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004c, 0x006c},
        std::vector<uint32_t>{0x004c, 0x004c},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0050),
        std::vector<uint32_t>{0x0070, 0x0068},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0070, 0x0068},
        std::vector<uint32_t>{0x0050, 0x0068},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0070, 0x0068},
        std::vector<uint32_t>{0x0050, 0x0068},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0050, 0x0068},
        std::vector<uint32_t>{0x0050, 0x0048},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0050, 0x0068},
        std::vector<uint32_t>{0x0050, 0x0048},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0052),
        std::vector<uint32_t>{0x0072, 0x0068},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0072, 0x0068},
        std::vector<uint32_t>{0x0052, 0x0068},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0072, 0x0068},
        std::vector<uint32_t>{0x0052, 0x0068},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0052, 0x0068},
        std::vector<uint32_t>{0x0052, 0x0048},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0052, 0x0068},
        std::vector<uint32_t>{0x0052, 0x0048},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0054),
        std::vector<uint32_t>{0x0074, 0x0068},
        table(), collation_strength::primary),
        -1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0074, 0x0068},
        std::vector<uint32_t>{0x0054, 0x0068},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0074, 0x0068},
        std::vector<uint32_t>{0x0054, 0x0068},
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0054, 0x0068},
        std::vector<uint32_t>{0x0054, 0x0048},
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0054, 0x0068},
        std::vector<uint32_t>{0x0054, 0x0048},
        table(), collation_strength::secondary),
        0);
}
