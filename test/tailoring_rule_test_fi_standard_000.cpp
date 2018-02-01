
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
            data::fi::standard_collation_tailoring(),
            "fi::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, fi_standard_000_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x0335},
        std::vector<uint32_t>(1, 0x0111),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0044, 0x0335},
        std::vector<uint32_t>(1, 0x0111),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0111),
        std::vector<uint32_t>(1, 0x0110),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0111),
        std::vector<uint32_t>(1, 0x0110),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x0335},
        std::vector<uint32_t>(1, 0x01e5),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0047, 0x0335},
        std::vector<uint32_t>(1, 0x01e5),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01e5),
        std::vector<uint32_t>(1, 0x01e4),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01e5),
        std::vector<uint32_t>(1, 0x01e4),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0335},
        std::vector<uint32_t>(1, 0x014b),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x004e, 0x0335},
        std::vector<uint32_t>(1, 0x014b),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x014b),
        std::vector<uint32_t>(1, 0x014a),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x014b),
        std::vector<uint32_t>(1, 0x014a),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0054, 0x0335},
        std::vector<uint32_t>(1, 0x0167),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0054, 0x0335},
        std::vector<uint32_t>(1, 0x0167),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0167),
        std::vector<uint32_t>(1, 0x0166),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0167),
        std::vector<uint32_t>(1, 0x0166),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0059),
        std::vector<uint32_t>(1, 0x00fc),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0059),
        std::vector<uint32_t>(1, 0x00fc),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00fc),
        std::vector<uint32_t>(1, 0x00dc),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00fc),
        std::vector<uint32_t>(1, 0x00dc),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x005a, 0x0335},
        std::vector<uint32_t>(1, 0x0292),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x005a, 0x0335},
        std::vector<uint32_t>(1, 0x0292),
        table(), collation_strength::primary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>(1, 0x01b7),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0292),
        std::vector<uint32_t>(1, 0x01b7),
        table(), collation_strength::secondary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00e5),
        table(), collation_strength::primary),
        -1);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00e5),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e5),
        std::vector<uint32_t>(1, 0x00c5),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e5),
        std::vector<uint32_t>(1, 0x00c5),
        table(), collation_strength::secondary),
        0);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00c5),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c5),
        std::vector<uint32_t>(1, 0x00e4),
        table(), collation_strength::primary),
        -1);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00e4),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e4),
        std::vector<uint32_t>(1, 0x00c4),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e4),
        std::vector<uint32_t>(1, 0x00c4),
        table(), collation_strength::secondary),
        0);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00c4),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c4),
        std::vector<uint32_t>(1, 0x00e6),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c4),
        std::vector<uint32_t>(1, 0x00e6),
        table(), collation_strength::primary),
        0);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00e6),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e6),
        std::vector<uint32_t>(1, 0x00c6),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00e6),
        std::vector<uint32_t>(1, 0x00c6),
        table(), collation_strength::secondary),
        0);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00c6),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00c6),
        std::vector<uint32_t>(1, 0x00f6),
        table(), collation_strength::primary),
        -1);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00f6),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f6),
        std::vector<uint32_t>(1, 0x00d6),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f6),
        std::vector<uint32_t>(1, 0x00d6),
        table(), collation_strength::secondary),
        0);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00d6),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00d6),
        std::vector<uint32_t>(1, 0x00f8),
        table(), collation_strength::secondary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00d6),
        std::vector<uint32_t>(1, 0x00f8),
        table(), collation_strength::primary),
        0);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00f8),
        table(), collation_strength::quaternary),
        1);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f8),
        std::vector<uint32_t>(1, 0x00d8),
        table(), collation_strength::tertiary),
        -1);
    // equal to preceeding cps at next-lower strength
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x00f8),
        std::vector<uint32_t>(1, 0x00d8),
        table(), collation_strength::secondary),
        0);
    // before initial reset cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x01c0),
        std::vector<uint32_t>(1, 0x00d8),
        table(), collation_strength::quaternary),
        1);
}
