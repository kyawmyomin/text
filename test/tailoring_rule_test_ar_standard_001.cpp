
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
            data::ar::standard_collation_tailoring(),
            "ar::standard_collation_tailoring()", error, warning);
    return retval;
}
TEST(tailoring, ar_standard_000_000)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x064c),
        std::vector<uint32_t>(1, 0xfe72),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x064c, 0x0651},
        std::vector<uint32_t>(1, 0xfc5e),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x064d),
        std::vector<uint32_t>(1, 0xfe74),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x064d, 0x0651},
        std::vector<uint32_t>(1, 0xfc5f),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x064e),
        std::vector<uint32_t>(1, 0xfe76),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x064e, 0x0651},
        std::vector<uint32_t>(1, 0xfc60),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x064f),
        std::vector<uint32_t>(1, 0xfe78),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x064f, 0x0651},
        std::vector<uint32_t>(1, 0xfc61),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0650),
        std::vector<uint32_t>(1, 0xfe7a),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0650, 0x0651},
        std::vector<uint32_t>(1, 0xfc62),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0651),
        std::vector<uint32_t>(1, 0xfe7c),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x0651, 0x0670},
        std::vector<uint32_t>(1, 0xfc63),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0652),
        std::vector<uint32_t>(1, 0xfe7e),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0671),
        std::vector<uint32_t>(1, 0xfb50),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb50),
        std::vector<uint32_t>(1, 0xfb51),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0679),
        std::vector<uint32_t>(1, 0xfb66),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb66),
        std::vector<uint32_t>(1, 0xfb67),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb67),
        std::vector<uint32_t>(1, 0xfb68),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb68),
        std::vector<uint32_t>(1, 0xfb69),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x067a),
        std::vector<uint32_t>(1, 0xfb5e),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb5e),
        std::vector<uint32_t>(1, 0xfb5f),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb5f),
        std::vector<uint32_t>(1, 0xfb60),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb60),
        std::vector<uint32_t>(1, 0xfb61),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x067b),
        std::vector<uint32_t>(1, 0xfb52),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb52),
        std::vector<uint32_t>(1, 0xfb53),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb53),
        std::vector<uint32_t>(1, 0xfb54),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb54),
        std::vector<uint32_t>(1, 0xfb55),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x067e),
        std::vector<uint32_t>(1, 0xfb56),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb56),
        std::vector<uint32_t>(1, 0xfb57),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb57),
        std::vector<uint32_t>(1, 0xfb58),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb58),
        std::vector<uint32_t>(1, 0xfb59),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x067f),
        std::vector<uint32_t>(1, 0xfb62),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb62),
        std::vector<uint32_t>(1, 0xfb63),
        table(), collation_strength::quaternary),
        0);
}

TEST(tailoring, ar_standard_001_001)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb63),
        std::vector<uint32_t>(1, 0xfb64),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb64),
        std::vector<uint32_t>(1, 0xfb65),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0680),
        std::vector<uint32_t>(1, 0xfb5a),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb5a),
        std::vector<uint32_t>(1, 0xfb5b),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb5b),
        std::vector<uint32_t>(1, 0xfb5c),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb5c),
        std::vector<uint32_t>(1, 0xfb5d),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0683),
        std::vector<uint32_t>(1, 0xfb76),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb76),
        std::vector<uint32_t>(1, 0xfb77),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb77),
        std::vector<uint32_t>(1, 0xfb78),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb78),
        std::vector<uint32_t>(1, 0xfb79),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0684),
        std::vector<uint32_t>(1, 0xfb72),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb72),
        std::vector<uint32_t>(1, 0xfb73),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb73),
        std::vector<uint32_t>(1, 0xfb74),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb74),
        std::vector<uint32_t>(1, 0xfb75),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0686),
        std::vector<uint32_t>(1, 0xfb7a),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb7a),
        std::vector<uint32_t>(1, 0xfb7b),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb7b),
        std::vector<uint32_t>(1, 0xfb7c),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb7c),
        std::vector<uint32_t>(1, 0xfb7d),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0687),
        std::vector<uint32_t>(1, 0xfb7e),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb7e),
        std::vector<uint32_t>(1, 0xfb7f),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb7f),
        std::vector<uint32_t>(1, 0xfb80),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb80),
        std::vector<uint32_t>(1, 0xfb81),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0688),
        std::vector<uint32_t>(1, 0xfb88),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb88),
        std::vector<uint32_t>(1, 0xfb89),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x068c),
        std::vector<uint32_t>(1, 0xfb84),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb84),
        std::vector<uint32_t>(1, 0xfb85),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x068d),
        std::vector<uint32_t>(1, 0xfb82),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb82),
        std::vector<uint32_t>(1, 0xfb83),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x068e),
        std::vector<uint32_t>(1, 0xfb86),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb86),
        std::vector<uint32_t>(1, 0xfb87),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0691),
        std::vector<uint32_t>(1, 0xfb8c),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb8c),
        std::vector<uint32_t>(1, 0xfb8d),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x0698),
        std::vector<uint32_t>(1, 0xfb8a),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb8a),
        std::vector<uint32_t>(1, 0xfb8b),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06a4),
        std::vector<uint32_t>(1, 0xfb6a),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb6a),
        std::vector<uint32_t>(1, 0xfb6b),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb6b),
        std::vector<uint32_t>(1, 0xfb6c),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb6c),
        std::vector<uint32_t>(1, 0xfb6d),
        table(), collation_strength::quaternary),
        0);
}

TEST(tailoring, ar_standard_001_002)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06a6),
        std::vector<uint32_t>(1, 0xfb6e),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb6e),
        std::vector<uint32_t>(1, 0xfb6f),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb6f),
        std::vector<uint32_t>(1, 0xfb70),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb70),
        std::vector<uint32_t>(1, 0xfb71),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06a9),
        std::vector<uint32_t>(1, 0xfb8e),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb8e),
        std::vector<uint32_t>(1, 0xfb8f),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb8f),
        std::vector<uint32_t>(1, 0xfb90),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb90),
        std::vector<uint32_t>(1, 0xfb91),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06ad),
        std::vector<uint32_t>(1, 0xfbd3),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbd3),
        std::vector<uint32_t>(1, 0xfbd4),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbd4),
        std::vector<uint32_t>(1, 0xfbd5),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbd5),
        std::vector<uint32_t>(1, 0xfbd6),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06af),
        std::vector<uint32_t>(1, 0xfb92),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb92),
        std::vector<uint32_t>(1, 0xfb93),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb93),
        std::vector<uint32_t>(1, 0xfb94),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb94),
        std::vector<uint32_t>(1, 0xfb95),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06b1),
        std::vector<uint32_t>(1, 0xfb9a),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb9a),
        std::vector<uint32_t>(1, 0xfb9b),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb9b),
        std::vector<uint32_t>(1, 0xfb9c),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb9c),
        std::vector<uint32_t>(1, 0xfb9d),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06b3),
        std::vector<uint32_t>(1, 0xfb96),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb96),
        std::vector<uint32_t>(1, 0xfb97),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb97),
        std::vector<uint32_t>(1, 0xfb98),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb98),
        std::vector<uint32_t>(1, 0xfb99),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06ba),
        std::vector<uint32_t>(1, 0xfb9e),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfb9e),
        std::vector<uint32_t>(1, 0xfb9f),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06bb),
        std::vector<uint32_t>(1, 0xfba0),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfba0),
        std::vector<uint32_t>(1, 0xfba1),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfba1),
        std::vector<uint32_t>(1, 0xfba2),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfba2),
        std::vector<uint32_t>(1, 0xfba3),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06be),
        std::vector<uint32_t>(1, 0xfbaa),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbaa),
        std::vector<uint32_t>(1, 0xfbab),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbab),
        std::vector<uint32_t>(1, 0xfbac),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbac),
        std::vector<uint32_t>(1, 0xfbad),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06c1),
        std::vector<uint32_t>(1, 0xfba6),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfba6),
        std::vector<uint32_t>(1, 0xfba7),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfba7),
        std::vector<uint32_t>(1, 0xfba8),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfba8),
        std::vector<uint32_t>(1, 0xfba9),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06c5),
        std::vector<uint32_t>(1, 0xfbe0),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbe0),
        std::vector<uint32_t>(1, 0xfbe1),
        table(), collation_strength::quaternary),
        0);
}

TEST(tailoring, ar_standard_001_003)
{
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06c6),
        std::vector<uint32_t>(1, 0xfbd9),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbd9),
        std::vector<uint32_t>(1, 0xfbda),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06c7),
        std::vector<uint32_t>(1, 0xfbd7),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbd7),
        std::vector<uint32_t>(1, 0xfbd8),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>{0x06c7, 0x0674},
        std::vector<uint32_t>(1, 0xfbdd),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06c8),
        std::vector<uint32_t>(1, 0xfbdb),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbdb),
        std::vector<uint32_t>(1, 0xfbdc),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06c9),
        std::vector<uint32_t>(1, 0xfbe2),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbe2),
        std::vector<uint32_t>(1, 0xfbe3),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06cb),
        std::vector<uint32_t>(1, 0xfbde),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbde),
        std::vector<uint32_t>(1, 0xfbdf),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06cc),
        std::vector<uint32_t>(1, 0xfbfc),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbfc),
        std::vector<uint32_t>(1, 0xfbfd),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbfd),
        std::vector<uint32_t>(1, 0xfbfe),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbfe),
        std::vector<uint32_t>(1, 0xfbff),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06d0),
        std::vector<uint32_t>(1, 0xfbe4),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbe4),
        std::vector<uint32_t>(1, 0xfbe5),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbe5),
        std::vector<uint32_t>(1, 0xfbe6),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbe6),
        std::vector<uint32_t>(1, 0xfbe7),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06d2),
        std::vector<uint32_t>(1, 0xfbae),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbae),
        std::vector<uint32_t>(1, 0xfbaf),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06d3),
        std::vector<uint32_t>(1, 0xfbb0),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfbb0),
        std::vector<uint32_t>(1, 0xfbb1),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0x06c0),
        std::vector<uint32_t>(1, 0xfba4),
        table(), collation_strength::quaternary),
        0);
    // greater than (or equal to, for =) preceeding cps
    EXPECT_EQ(collate(
        std::vector<uint32_t>(1, 0xfba4),
        std::vector<uint32_t>(1, 0xfba5),
        table(), collation_strength::quaternary),
        0);
}
