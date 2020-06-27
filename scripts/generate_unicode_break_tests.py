#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Copyright (C) 2020 T. Zachary Laine
#
# Distributed under the Boost Software License, Version 1.0. (See
# accompanying file LICENSE_1_0.txt or copy at
# http://www.boost.org/LICENSE_1_0.txt)

prop_lookup_test_form = decls = '''\
// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Warning! This file is autogenerated.
#include <boost/text/{0}_break.hpp>

#include <gtest/gtest.h>


TEST({0}, prop_lookups_{2})
{{{1}
}}
'''

prop_lookup_perf_test_form = decls = '''\
// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Warning! This file is autogenerated.
#include <boost/text/{0}_break.hpp>

#include <benchmark/benchmark.h>

#include <iostream>


void BM_{0}_prop(benchmark::State & state)
{{
    while (state.KeepRunning()) {{
{1}
    }}
    std::cout << "Divide result by {2} to get mean time.\\n";
}}


BENCHMARK(BM_{0}_prop);

BENCHMARK_MAIN()
'''

break_test_form = decls = '''\
// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Warning! This file is autogenerated.
#include <boost/text/{0}_break.hpp>

#include <gtest/gtest.h>

#include <algorithm>


TEST({0}, breaks_{2})
{{{1}
}}
'''

grapheme_iterator_test_form = decls = '''\
// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Warning! This file is autogenerated.
#include <boost/text/grapheme_iterator.hpp>
#include <boost/text/transcode_iterator.hpp>

#include <gtest/gtest.h>

#include <algorithm>


{0}
'''


bidi_test_file_form = decls = '''\
// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Warning! This file is autogenerated.
#include <boost/text/bidirectional.hpp>

#include "bidi_tests.hpp"

#include <gtest/gtest.h>

#include <algorithm>


std::vector<int> expected_levels;
std::vector<int> expected_reordered_indices;

TEST(bidi, bidi_{1:03}_000)
{{
{0}
}}
'''


bidi_test_form = '''
    {{
        // {0} ('{5}') (line {3})
        std::vector<uint32_t> const cps = {{ {1} }};
        std::vector<int> const levels =
            bidi_levels(cps.begin(), cps.end(), {4});
        int i = 0;
        for (int l : expected_levels) {{
            if (0 <= l) {{
                EXPECT_EQ(levels[i], l) << "i=" << i;
                ++i;
            }}
        }}
        EXPECT_EQ((int)levels.size(), i);

        std::vector<int> const reordered =
            bidi_reordered_indices(cps.begin(), cps.end(), {4});
        i = 0;
        for (int idx : expected_reordered_indices) {{
            // Skip FSI, LRI, RLI, and PDI.
            if (cps[idx] < 0x2066 || 0x2069 < cps[idx]) {{
                EXPECT_EQ(reordered[i], cps[idx])
                    << std::hex
                    << " 0x" << reordered[i]
                    << " 0x" << cps[idx]
                    << std::dec << " i=" << i;
            }}
            ++i;
        }}

        std::vector<int> reordered_2;
        for (auto subrange :
            boost::text::bidirectional_subranges(cps, {4})) {{
            for (auto cp : subrange) {{
                reordered_2.push_back(cp);
            }}
        }}
        i = 0;
        for (int idx : expected_reordered_indices) {{
            if (cps[idx] < 0x2066 || 0x2069 < cps[idx]) {{
                EXPECT_EQ(reordered_2[i], cps[idx])
                    << std::hex
                    << " 0x" << reordered_2[i]
                    << " 0x" << cps[idx]
                    << std::dec << " i=" << i;
            }}
            ++i;
        }}
        EXPECT_EQ(i, (int)reordered_2.size());
    }}
'''


bidi_character_test_file_form = decls = '''\
// Copyright (C) 2020 T. Zachary Laine
//
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)

// Warning! This file is autogenerated.
#include <boost/text/bidirectional.hpp>

#include "bidi_tests.hpp"

#include <gtest/gtest.h>

#include <algorithm>


TEST(bidi_character, bidi_character_{1:03}_000)
{{
{0}
}}
'''


bidi_character_test_form = '''
    {{
        // line {4}
        std::vector<uint32_t> const cps = {{ {0} }};
        std::vector<int> const expected_levels =
            {{ {2} }};
        std::vector<int> const levels =
            bidi_levels(cps.begin(), cps.end(), {1});
        int i = 0;
        for (int l : expected_levels) {{
            if (0 <= l) {{
                EXPECT_EQ(levels[i], l) << "i=" << i;
                ++i;
            }}
        }}
        EXPECT_EQ((int)levels.size(), i);

        std::vector<uint32_t> const expected_reordered_indices =
            {{ {3} }};
        std::vector<int> const reordered =
            bidi_reordered_indices(cps.begin(), cps.end(), {1});
        i = 0;
        for (int idx : expected_reordered_indices) {{
            EXPECT_EQ(reordered[i], cps[idx])
                << std::hex
                << " 0x" << reordered[i]
                << " 0x" << cps[idx]
                << std::dec << " i=" << i;
            ++i;
        }}
    }}
'''


def extract_cps_and_breaks(filename, batch_size = 50):
    current_batch = []
    retval = []
    lines = open(filename, 'r').readlines()
    num_lines = 0
    for line in lines:
        if num_lines == batch_size:
            retval.append(current_batch)
            current_batch = []
            num_lines = 0
        line = line[:-1]
        if not line.startswith('#') and len(line) != 0:
            comment_start = line.find('#')
            comment = ''
            if comment_start != -1:
                comment = line[comment_start + 1:].strip()
                line = line[:comment_start]
            fields = line.split(' ')[1:-1]
            cps = []
            active_break = True
            for i in range(len(fields)):
                f = fields[i]
                if f[0] in '0123456789ABCDEF':
                    cps.append((f, active_break))
                else:
                    active_break = f == '÷'
            current_batch.append((cps, line, comment))
        num_lines += 1
    if len(current_batch):
        retval.append(current_batch)
    return retval

def generate_prop_lookup_tests(cps_and_breaks, prop_, prop_names):
    for i in range(len(cps_and_breaks)):
        prop_lookup_tests = ''
        chunk = cps_and_breaks[i]
        for elem in chunk:
            (cps, line, comment) = elem
            comment_fields = comment.split(' ')
            j = 0
            for f in comment_fields:
                if f.startswith('(') and f.endswith(')'):
                    prop_lookup_tests += \
                        '\n    EXPECT_EQ(boost::text::{0}_prop(0x{1}), {2});'.format(
                            prop_, cps[j][0], prop_names[f[1:-1]]
                        )
                    j += 1
        cpp_file = open('{}_prop_lookup_{:02}.cpp'.format(prop_, i), 'w')
        cpp_file.write(prop_lookup_test_form.format(prop_, prop_lookup_tests, i))

def generate_prop_lookup_perf_tests(cps_and_breaks, prop_):
    prop_lookup_perf_tests = ''
    lines = 0
    for i in range(len(cps_and_breaks)):
        chunk = cps_and_breaks[i]
        for elem in chunk:
            (cps, line, comment) = elem
            comment_fields = comment.split(' ')
            j = 0
            for f in comment_fields:
                if f.startswith('(') and f.endswith(')'):
                    prop_lookup_perf_tests += \
                        '        benchmark::DoNotOptimize(boost::text::{0}_prop(0x{1}));\n'.format(
                            prop_, cps[j][0]
                        )
                    j += 1
                    lines += 1
    cpp_file = open('{}_prop_lookup_perf.cpp'.format(prop_, i), 'w')
    cpp_file.write(prop_lookup_perf_test_form.format(prop_, prop_lookup_perf_tests, lines))

def generate_break_tests_2(cps_and_breaks, prop_, prop_prefix = '', call_suffix = ''):
    for i in range(len(cps_and_breaks)):
        break_tests = ''
        chunk = cps_and_breaks[i]
        for elem in chunk:
            (cps, line, comment) = elem
            comment_fields = comment.split(' ')
            break_tests += '''
    // {0}
    // {1}
    {{
        std::array<uint32_t, {3}> cps = {{{{ {2} }}}};
'''.format(line, comment, ', '.join(map(lambda x: hex(int(x[0], 16)), cps)), len(cps))
            for j in range(len(cps) + 1):
                prev_break = j
                while prev_break == len(cps) or prev_break != 0 and not cps[prev_break][1]:
                    prev_break -= 1
                next_break = min(j + 1, len(cps))
                while next_break != len(cps) and not cps[next_break][1]:
                    next_break += 1
                break_tests += '''\
        EXPECT_EQ(boost::text::prev_{4}{3}_break(cps.begin(), cps.begin() + {0}, cps.end()){5} - cps.begin(), {1});
        EXPECT_EQ(boost::text::next_{4}{3}_break(cps.begin() + {1}, cps.end()){5} - cps.begin(), {2});
'''.format(j, prev_break, next_break, prop_, prop_prefix, call_suffix)
            break_tests += '    }\n\n'
        cpp_file = open('{}_break_{:02}.cpp'.format(prop_, i), 'w')
        cpp_file.write(break_test_form.format(prop_, break_tests, i))

def contains_surrogate(cps):
    for cp in cps:
        if int(cp[0], 16) == 0xD800:
            return True
    return False

def generate_iterator_tests(cps_and_breaks, prop_):
    for i in range(len(cps_and_breaks)):
        iterator_tests = ''
        chunk = cps_and_breaks[i]
        elem_index = -1
        for elem in chunk:
            elem_index += 1
            (cps, line, comment) = elem
            comment_fields = comment.split(' ')

            break_cp_indices = []
            for j in range(len(cps)):
                if cps[j][1]: # if break
                    break_cp_indices.append(j)

            graphemes_and_end = []
            code_unit_graphemes_and_end = []
            for j in range(len(break_cp_indices)):
                last_cp = j == len(break_cp_indices) - 1
                first = break_cp_indices[j]
                last = last_cp and len(cps) or break_cp_indices[j + 1]

                graphemes_and_end.append('''\
        EXPECT_EQ(it.base(), cps + {0});
        EXPECT_EQ((*it).begin(), cps + {0});
        EXPECT_EQ((*it).end(), cps + {1});'''.format(first, last))

                code_unit_grapheme = '''\
        EXPECT_EQ(*it.base(), cps[{0}]);
        EXPECT_EQ(*it->begin(), cps[{0}]);'''.format(first)
                if not last_cp:
                    code_unit_grapheme += '''
        EXPECT_EQ(*it->end(), cps[{0}]);'''.format(last)
                code_unit_grapheme += '''
        EXPECT_EQ(it.base().base(), cus + cp_indices[{0}]);
        EXPECT_EQ(it->begin().base(), cus + cp_indices[{0}]);
        EXPECT_EQ(it->end().base(), cus + cp_indices[{1}]);'''.format(first, last)
                code_unit_graphemes_and_end.append(code_unit_grapheme)

            graphemes_and_end.append('''\
        EXPECT_EQ(it.base(), cps + {});
        EXPECT_EQ((*it).begin(), (*it).end());'''.format(len(cps)))
            code_unit_graphemes_and_end.append('''\
        EXPECT_EQ(it.base().base(), cus + cp_indices[{}]);
        EXPECT_EQ(it->begin(), (*it).end());'''.format(len(cps)))

            # forward
            iterator_tests += '''
TEST({3}, iterator_{5:02}_{6}_fwd)
{{
    // {0}
    // {1}
    {{
        uint32_t const cps[] = {{ {2} }};
        boost::text::{3}_iterator<uint32_t const *> it(cps, cps, cps + {4});

'''.format(line, comment, '0x' + ', 0x'.join(map(lambda x: x[0], cps)), prop_, len(cps), i, elem_index)
            iterator_tests += '\n\n        ++it;\n\n'.join(graphemes_and_end)
            iterator_tests += '\n    }\n}\n'

            # reverse
            iterator_tests += '''\
TEST({1}, iterator_{3:02}_{4}_rev)
{{
    {{
        // reverse
        uint32_t const cps[] = {{ {0} }};
        boost::text::{1}_iterator<uint32_t const *> it(cps, cps + {2}, cps + {2});

'''.format('0x' + ', 0x'.join(map(lambda x: x[0], cps)), prop_, len(cps), i, elem_index)
            iterator_tests += '\n\n        --it;\n\n'.join(reversed(graphemes_and_end))
            iterator_tests += '\n    }\n}\n'

            # forth and back
            iterator_tests += '''\
TEST({1}, iterator_{3:02}_{4}_fab)
{{
    {{
        // forth and back
        uint32_t const cps[] = {{ {0} }};
        boost::text::{1}_iterator<uint32_t const *> it(cps, cps, cps + {2});

'''.format('0x' + ', 0x'.join(map(lambda x: x[0], cps)), prop_, len(cps), i, elem_index)
            idx = 0
            iterator_tests += graphemes_and_end[idx]
            for j in range(len(graphemes_and_end)):
                for k in range(j):
                    iterator_tests += '\n\n        ++it;\n\n'
                    idx += 1
                    iterator_tests += graphemes_and_end[idx]
                for k in range(j):
                    iterator_tests += '\n\n        --it;\n\n'
                    idx -= 1
                    iterator_tests += graphemes_and_end[idx]
            iterator_tests += '\n    }\n}\n'

            # back and forth
            iterator_tests += '''\
TEST({1}, iterator_{3:02}_{4}_baf)
{{
    {{
        // back and forth
        uint32_t const cps[] = {{ {0} }};
        boost::text::{1}_iterator<uint32_t const *> it(cps, cps + {2}, cps + {2});

'''.format('0x' + ', 0x'.join(map(lambda x: x[0], cps)), prop_, len(cps), i, elem_index)
            idx = len(graphemes_and_end) - 1
            iterator_tests += graphemes_and_end[idx]
            for j in range(len(graphemes_and_end)):
                for k in range(j):
                    iterator_tests += '\n\n        --it;\n\n'
                    idx -= 1
                    iterator_tests += graphemes_and_end[idx]
                for k in range(j):
                    iterator_tests += '\n\n        ++it;\n\n'
                    idx += 1
                    iterator_tests += graphemes_and_end[idx]
            iterator_tests += '\n    }\n}\n'

            # from UTF8
            if contains_surrogate(cps):
                iterator_tests += \
                  '// Skipping from-utf8 test due to presence of surrogate code point.\n'
            else:
                iterator_tests += '''\
TEST({1}, iterator_{3:02}_{4}_utf8)
{{
    {{
        // from UTF8
        uint32_t const cps[] = {{ {0} }};
        char cus[1024] = {{ 0 }};
        int cp_indices[1024] = {{ 0 }};

        std::copy(
            boost::text::utf_32_to_8_iterator<uint32_t const *>(cps, cps, cps + {2}),
            boost::text::utf_32_to_8_iterator<uint32_t const *>(cps, cps + {2}, cps + {2}),
            cus);

        boost::text::null_sentinel sentinel;
        int * index_it = cp_indices;
        for (boost::text::utf_8_to_32_iterator<char const *, boost::text::null_sentinel> it(cus, cus, boost::text::null_sentinel{{}}); ; ++it) {{
            *index_it++ = it.base() - cus;
            if (it == sentinel)
                break;
        }}

        using iter_t = boost::text::utf_8_to_32_iterator<char const *, boost::text::null_sentinel>;
        boost::text::{1}_iterator<iter_t, boost::text::null_sentinel> it(
            iter_t{{cus, cus, boost::text::null_sentinel{{}}}}, iter_t{{cus, cus, boost::text::null_sentinel{{}}}}, sentinel);

'''.format('0x' + ', 0x'.join(map(lambda x: x[0], cps)), prop_, len(cps), i, elem_index)
                iterator_tests += '\n\n        ++it;\n\n'.join(code_unit_graphemes_and_end)
                iterator_tests += '\n    }\n}\n'

        cpp_file = open('{}_iterator_{:02}.cpp'.format(prop_, i), 'w')
        cpp_file.write(grapheme_iterator_test_form.format(iterator_tests, i))

bidi_property_cps = {
    'L': '0x0041',
    'R': '0x05BE',
    'EN': '0x0030',
    'ES': '0x002B',
    'ET': '0x0023',
    'AN': '0x0660',
    'CS': '0x002C',
    'B': '0x2029',
    'S': '0x0009',
    'WS': '0x0020',
    'ON': '0x0021',
    'BN': '0x00AD',
    'NSM': '0x0300',
    'AL': '0x0608',
    'LRO': '0x202D',
    'RLO': '0x202E',
    'LRE': '0x202A',
    'RLE': '0x202B',
    'PDF': '0x202C',
    'LRI': '0x2066',
    'RLI': '0x2067',
    'FSI': '0x2068',
    'PDI': '0x2069'
}

def generate_bidi_tests(filename, batch_size):
    current_batch = []
    test_data = []

    lines = open(filename, 'r').readlines()
    num_lines = 0
    curr_levels = []
    curr_reorder = []
    line_number = 0
    for line in lines:
        line_number += 1
        if num_lines == batch_size:
            test_data.append(current_batch)
            current_batch = []
            num_lines = 0
        line = line[:-1]
        if not line.startswith('#') and len(line) != 0:
            comment_start = line.find('#')
            comment = ''
            if comment_start != -1:
                comment = line[comment_start + 1:].strip()
                line = line[:comment_start]
            if line.startswith('@Levels:'):
                curr_levels = line[len('@Levels:'):].strip().split(' ')
            elif line.startswith('@Reorder:'):
                curr_reorder = line[len('@Reorder:'):].strip().split(' ')
            elif line.startswith('@'):
                pass
            else:
                input_,bitset = line.split(';')
                input_ = input_.split(' ')
                bitset = int(bitset)
                test_cases = {'auto': bool(bitset & 1), 'LTR': bool(bitset & 2), 'RTL' : bool(bitset & 4)}
                current_batch.append((input_, curr_levels, curr_reorder, test_cases, line, line_number))
        num_lines += 1
    if len(current_batch):
        test_data.append(current_batch)

    i = 0
    for batch in test_data:
        cpp_file = open('bidi_test_{:03}.cpp'.format(i), 'w')
        tests = ''
        curr_levels = []
        curr_reorder = []
        test_case_idx = 0
        test_idx = 0
        for test in batch:
            if test_case_idx == 10:
                test_idx += 1
                tests += '''\
}}

TEST(bidi, bidi_{:03}_{:03})
{{
'''.format(i, test_idx)
                curr_levels = []
                curr_reorder = []
                test_case_idx = 0
            test_case_idx += 1
            if all(map(lambda x: x == 'x', test[1])):
                continue
            if test[1] != curr_levels:
                levels = ', '.join(map(lambda x: x == 'x' and '-1' or x, test[1]))
                indices = ', '.join(test[2])
                tests += '''
    expected_levels = {{ {} }};
    expected_reordered_indices = {{ {} }};
'''.format(levels, indices)
                curr_levels = test[1]
            cps = ', '.join(map(lambda x: bidi_property_cps[x], test[0]))
            if test[3]['auto']:
                tests += bidi_test_form.format(test[4], cps, levels, test[5], -1, 'auto')
            if test[3]['LTR']:
                tests += bidi_test_form.format(test[4], cps, levels, test[5], 0, 'LTR')
            if test[3]['RTL']:
                tests += bidi_test_form.format(test[4], cps, levels, test[5], 1, 'RTL')
        cpp_file.write(bidi_test_file_form.format(tests, i))
        i += 1

def generate_bidi_character_tests(filename, batch_size):
    current_batch = []
    test_data = []

    lines = open(filename, 'r').readlines()
    num_lines = 0
    line_number = 0
    for line in lines:
        line_number += 1
        if num_lines == batch_size:
            test_data.append(current_batch)
            current_batch = []
            num_lines = 0
        line = line[:-1]
        if not line.startswith('#') and len(line) != 0:
            fields = line.split(';')
            cps = fields[0].split(' ')
            pel = fields[1]
            if pel == '2':
                pel = '-1'
            levels = fields[3].split(' ')
            reorder = fields[4].split(' ')
            current_batch.append((cps, pel, levels, reorder, line_number))
        num_lines += 1
    if len(current_batch):
        test_data.append(current_batch)

    i = 0
    for batch in test_data:
        cpp_file = open('bidi_character_test_{:03}.cpp'.format(i), 'w')
        tests = ''
        test_case_idx = 0
        test_idx = 0
        for test in batch:
            if test_case_idx == 10:
                test_idx += 1
                tests += '''\
}}

TEST(bidi_character, bidi_character_{:03}_{:03})
{{
'''.format(i, test_idx)
                test_case_idx = 0
            test_case_idx += 1
            if all(map(lambda x: x == 'x', test[1])):
                continue
            tests += bidi_character_test_form.format(
                ', '.join(map(lambda x: '0x' + x, test[0])), test[1],
                ', '.join(map(lambda x: x == 'x' and '-1' or x, test[2])),
                ', '.join(test[3]),
                test[4]
            )
        cpp_file.write(bidi_character_test_file_form.format(tests, i))
        i += 1


import sys

grapheme_cps_and_breaks = extract_cps_and_breaks('GraphemeBreakTest.txt')
if '--perf' in sys.argv:
    generate_prop_lookup_perf_tests(grapheme_cps_and_breaks, 'grapheme')
    exit(0)
generate_break_tests_2(grapheme_cps_and_breaks, 'grapheme')
generate_iterator_tests(grapheme_cps_and_breaks, 'grapheme')

word_cps_and_breaks = extract_cps_and_breaks('WordBreakTest.txt')
generate_break_tests_2(word_cps_and_breaks, 'word')

sentence_cps_and_breaks = extract_cps_and_breaks('SentenceBreakTest.txt')
generate_break_tests_2(sentence_cps_and_breaks, 'sentence')

line_cps_and_breaks = extract_cps_and_breaks('LineBreakTest.txt', 100)
generate_break_tests_2(line_cps_and_breaks, 'line', 'allowed_', '.iter')

generate_bidi_tests('BidiTest.txt', 500)

generate_bidi_character_tests('BidiCharacterTest.txt', 700)
