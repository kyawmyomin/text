#!/usr/bin/env python
# -*- coding: utf-8 -*-

from generate_unicode_normalization_data import cccs
from generate_unicode_normalization_data import expand_decomp_canonical
from generate_unicode_normalization_data import get_decompositions


# TODO: These are from the latest FractionalUCA.txt.  When updaing it, these
# need to be updated too:

constants_header_form = '''\
// Warning! This file is autogenerated.
#ifndef BOOST_TEXT_DETAIL_COLLATION_CONSTANTS_HPP
#define BOOST_TEXT_DETAIL_COLLATION_CONSTANTS_HPP

#include <array>

#include <cstdint>


namespace boost {{ namespace text {{ namespace detail {{

    enum collation_constants : uint32_t {{
        min_variable_collation_weight = 0x03040000,
        max_variable_collation_weight = 0x0b6d4b00,

        OR_CJK_Compatibility_Ideographs = {},
        OR_CJK_Unified_Ideographs_Extension_D = {},

        // Symbolic sentinel values produced by the parser.
        first_tertiary_ignorable = 0xfffffff4,
        last_tertiary_ignorable = 0xfffffff5,
        first_secondary_ignorable = 0xfffffff6,
        last_secondary_ignorable = 0xfffffff7,
        first_primary_ignorable = 0xfffffff8,
        last_primary_ignorable = 0xfffffff9,
        first_variable = 0xfffffffa,
        last_variable = 0xfffffffb,
        first_regular = 0xfffffffc,
        last_regular = 0xfffffffd,
        first_implicit = 0xffffffe,

        invalid_code_point = 0xffffffff,
        no_secondary_ignorables = invalid_code_point,

        initial_first_tertiary_ignorable = 0,
        initial_last_tertiary_ignorable = 0xfffb,
        initial_first_secondary_ignorable = no_secondary_ignorables,
        initial_last_secondary_ignorable = no_secondary_ignorables,
        initial_first_primary_ignorable = 0x0332,
        initial_last_primary_ignorable = 0x00b7,
        initial_first_variable = 0x0009,
        initial_last_variable = 0x10A7F,
        initial_first_regular = 0x0060,
        initial_last_regular = 0x1B2FB,
        initial_first_implicit = 0x3400,

        implicit_weights_spacing_times_ten = {},
        implicit_weights_first_primary_byte = {},
        implicit_weights_final_lead_byte = {}
    }};

    struct implicit_weights_segment
    {{
        uint32_t first_;
        uint32_t last_;
        uint32_t primary_offset_;
    }};

    extern std::array<implicit_weights_segment, {}>
        const implicit_weights_segments;

}}}}}}

#endif
'''

collation_elements_file_form = '''\
// Warning! This file is autogenerated.
#include <boost/text/detail/collation_constants.hpp>
#include <boost/text/detail/collation_data.hpp>

#include <unordered_map>


namespace boost {{ namespace text {{ namespace detail {{

extern std::array<implicit_weights_segment, {1}> const implicit_weights_segments = {{{{
{0}
}}}};

const std::array<compressed_collation_element, {3}> g_collation_elements = {{{{
{2}
}}}};

compressed_collation_element const * g_collation_elements_first =
    g_collation_elements.data();

}}}}}}
'''

multiple_cp_key_file_form = '''\
// Warning! This file is autogenerated.
#include <boost/text/detail/collation_constants.hpp>
#include <boost/text/detail/collation_data.hpp>

#include <unordered_map>


namespace boost {{ namespace text {{

// For the compression schemes used elsewhere in sort key generation to work,
// these must be well-formed.  See:
// http://www.unicode.org/reports/tr10/#Eliminating_level_separators
// http://www.unicode.org/reports/tr10/#L2/L3_in_8_bits

namespace detail {{
    std::unordered_set<detail::collation_trie_node> const g_collation_initial_nodes = {{
{0}
    }};
}}

static const std::array<detail::collation_trie_node, {2}>
g_collation_noninitial_trie_nodes_array = {{{{
{1}
}}}};

namespace detail {{
    collation_trie_node const * g_collation_trie_nodes =
        g_collation_noninitial_trie_nodes_array.data(); 
}}

}}}}
'''

def ccc(cccs_dict, cp):
    if cp in cccs_dict:
        return cccs_dict[cp]
    return 0

CJK_Compatibility_Ideographs = [
    0xFA0E, 0xFA0F, 0xFA11, 0xFA13, 0xFA14, 0xFA1F, 0xFA21, 0xFA23,
    0xFA24, 0xFA27, 0xFA28, 0xFA29
]
OR_CJK_Compatibility_Ideographs = \
  reduce(lambda x,y: x | y, CJK_Compatibility_Ideographs, 0)

CJK_Unified_Ideographs_Extension_D = [
    0x2B740, 0x2B741, 0x2B742, 0x2B743, 0x2B744, 0x2B745, 0x2B746, 0x2B747,
    0x2B748, 0x2B749, 0x2B74A, 0x2B74B, 0x2B74C, 0x2B74D, 0x2B74E, 0x2B74F,
    0x2B750, 0x2B751, 0x2B752, 0x2B753, 0x2B754, 0x2B755, 0x2B756, 0x2B757,
    0x2B758, 0x2B759, 0x2B75A, 0x2B75B, 0x2B75C, 0x2B75D, 0x2B75E, 0x2B75F,
    0x2B760, 0x2B761, 0x2B762, 0x2B763, 0x2B764, 0x2B765, 0x2B766, 0x2B767,
    0x2B768, 0x2B769, 0x2B76A, 0x2B76B, 0x2B76C, 0x2B76D, 0x2B76E, 0x2B76F,
    0x2B770, 0x2B771, 0x2B772, 0x2B773, 0x2B774, 0x2B775, 0x2B776, 0x2B777,
    0x2B778, 0x2B779, 0x2B77A, 0x2B77B, 0x2B77C, 0x2B77D, 0x2B77E, 0x2B77F,
    0x2B780, 0x2B781, 0x2B782, 0x2B783, 0x2B784, 0x2B785, 0x2B786, 0x2B787,
    0x2B788, 0x2B789, 0x2B78A, 0x2B78B, 0x2B78C, 0x2B78D, 0x2B78E, 0x2B78F,
    0x2B790, 0x2B791, 0x2B792, 0x2B793, 0x2B794, 0x2B795, 0x2B796, 0x2B797,
    0x2B798, 0x2B799, 0x2B79A, 0x2B79B, 0x2B79C, 0x2B79D, 0x2B79E, 0x2B79F,
    0x2B7A0, 0x2B7A1, 0x2B7A2, 0x2B7A3, 0x2B7A4, 0x2B7A5, 0x2B7A6, 0x2B7A7,
    0x2B7A8, 0x2B7A9, 0x2B7AA, 0x2B7AB, 0x2B7AC, 0x2B7AD, 0x2B7AE, 0x2B7AF,
    0x2B7B0, 0x2B7B1, 0x2B7B2, 0x2B7B3, 0x2B7B4, 0x2B7B5, 0x2B7B6, 0x2B7B7,
    0x2B7B8, 0x2B7B9, 0x2B7BA, 0x2B7BB, 0x2B7BC, 0x2B7BD, 0x2B7BE, 0x2B7BF,
    0x2B7C0, 0x2B7C1, 0x2B7C2, 0x2B7C3, 0x2B7C4, 0x2B7C5, 0x2B7C6, 0x2B7C7,
    0x2B7C8, 0x2B7C9, 0x2B7CA, 0x2B7CB, 0x2B7CC, 0x2B7CD, 0x2B7CE, 0x2B7CF,
    0x2B7D0, 0x2B7D1, 0x2B7D2, 0x2B7D3, 0x2B7D4, 0x2B7D5, 0x2B7D6, 0x2B7D7,
    0x2B7D8, 0x2B7D9, 0x2B7DA, 0x2B7DB, 0x2B7DC, 0x2B7DD, 0x2B7DE, 0x2B7DF,
    0x2B7E0, 0x2B7E1, 0x2B7E2, 0x2B7E3, 0x2B7E4, 0x2B7E5, 0x2B7E6, 0x2B7E7,
    0x2B7E8, 0x2B7E9, 0x2B7EA, 0x2B7EB, 0x2B7EC, 0x2B7ED, 0x2B7EE, 0x2B7EF,
    0x2B7F0, 0x2B7F1, 0x2B7F2, 0x2B7F3, 0x2B7F4, 0x2B7F5, 0x2B7F6, 0x2B7F7,
    0x2B7F8, 0x2B7F9, 0x2B7FA, 0x2B7FB, 0x2B7FC, 0x2B7FD, 0x2B7FE, 0x2B7FF,
    0x2B800, 0x2B801, 0x2B802, 0x2B803, 0x2B804, 0x2B805, 0x2B806, 0x2B807,
    0x2B808, 0x2B809, 0x2B80A, 0x2B80B, 0x2B80C, 0x2B80D, 0x2B80E, 0x2B80F,
    0x2B810, 0x2B811, 0x2B812, 0x2B813, 0x2B814, 0x2B815, 0x2B816, 0x2B817,
    0x2B818, 0x2B819, 0x2B81A, 0x2B81B, 0x2B81C, 0x2B81D
]

OR_CJK_Unified_Ideographs_Extension_D = \
  reduce(lambda x,y: x | y, CJK_Unified_Ideographs_Extension_D, 0)


# Note: These are filled in far below.
implicit_weights_first_primary_byte = 0
implicit_weights_spacing = 2.6
implicit_weights_segments = []
implicit_weights_final_byte = 0


# http://www.unicode.org/reports/tr10/#Implicit_Weights
def implicit_ce(cp):
    def to_byte(x):
        retval = hex(x)[2:]
        if len(retval) == 1:
            retval = '0' + retval
        return retval.upper()

    for s in implicit_weights_segments:
        if s[0][0] <= cp and cp < s[0][1]:
            primary_suffix = s[1] + int((cp - s[0][0]) * implicit_weights_spacing)

            return (
                (
                    to_byte(implicit_weights_first_primary_byte),
                    to_byte(((primary_suffix >> 12) & 0xfe) | 0x1), # top 7 bits (|1 -- no zeros)
                    to_byte(((primary_suffix >> 5) & 0xfe) | 0x1), # middle 7 bits (|1 -- no zeros)
                    to_byte((primary_suffix >> 0) & 0x3f) # last 6 bits
                ),
                ('05',),
                ('05',)
            )

    return (
        (
            to_byte((implicit_weights_final_byte << 24) | (cp & 0xffffff))
        ),
        ('05',),
        ('05',)
    )

def ce(cet, cps):
    if cps in cet:
        return cet[cps]
    if len(cps) != 1:
        return None
    return implicit_ce(cps[0])

def collation_elements_for_decomposition(cccs_dict, cet, cps):
    longest_prefix = (cps[0],)
    for i in reversed(range(1, len(cps))):
        t = tuple(cps[0:i + 1])
        if t in cet:
            longest_prefix = t
            break

    i = len(longest_prefix)
    while i < len(cps):
        blocked = True
        if i == len(longest_prefix) or ccc(cccs_dict, cps[i - 1]) < ccc(cccs_dict, cps[i]):
            blocked = False
        if not blocked:
            new_longest = longest_prefix + (cps[i],)
            if new_longest in cet:
                longest_prefix = new_longest
                cps = cps.pop(i)
            else:
                i += 1
        else:
            i += 1

    cps = cps[len(longest_prefix):]

    return (ce(cet, longest_prefix), cps)

# http://www.unicode.org/reports/tr10/#Avoiding_Normalization
def cet_from_cet_and_decompositions(cccs_dict, old_cet, decomposition_mapping):
    cet = {}

    for k,v in old_cet.items():
        cet[k] = v

    for k,v in decomposition_mapping.items():
        v_initial = v
        collation_elements = []
        while len(v):
            (ces, v) = collation_elements_for_decomposition(
                cccs_dict, old_cet, v
            )
            if ces == None:
                print hex(k),map(lambda x : hex(x), v0)
            collation_elements += ces
        if type(collation_elements[0][0]) == str:
            collation_elements = (tuple(collation_elements),)
        cet[(k,)] = tuple(collation_elements)

    return cet

def trie_data(fcc_cet):
    trie_initial_cps = set()
    fanouts = {}
    trie_cp_num_parents = {}
    for k,v in fcc_cet.items():
        for i in range(0, len(k) - 1):
            if i == 0:
                trie_initial_cps.add(k[i])
            if k[i] not in fanouts:
                fanouts[k[i]] = set()
            end_of_sequence = None
            if i + 1 == len(k) - 1:
                end_of_sequence = k
            fanouts[k[i]].add((k[i + 1], end_of_sequence))
            if k[i + 1] not in trie_cp_num_parents:
                trie_cp_num_parents[k[i + 1]] = set()
            trie_cp_num_parents[k[i + 1]].add(k[i])

    trie_cp_num_parents = map(lambda x: (x[0], len(x[1])), trie_cp_num_parents.items())
    single_parent_cps = \
      sorted(map(lambda x: x[0], filter(lambda x: x[1] == 1, trie_cp_num_parents)))

    return (trie_initial_cps, fanouts)

def make_unique_collation_element_sequence(cet):
    new_cet = {}
    collation_elements = []

    already_processed = {}
    for k,v in cet.items():
        if v not in already_processed:
            first = len(collation_elements)
            collation_elements += v
            last = len(collation_elements)
            already_processed[v] = (first, last)
        new_cet[k] = already_processed[v]

    return (new_cet, collation_elements)

class trie_node:
    def __init__(self, cp):
        self.cp_ = cp
        self.children_ = []
        self.collation_elements_ = (0, 0)
    def __lt__(self, rhs):
        return self.cp_ < rhs.cp_
    def __str__(self):
        return print_node(self)
    def child(self, cp):
        for c in self.children_:
            if c.cp_ == cp:
                return c
        return None
    def insert(self, node):
        self.children_.append(node)
        return node

def trie_insert(trie, k, v):
    i = 0
    end = len(k)

    while i < end:
        c = trie.child(k[i])
        if c != None:
            trie = c
            i += 1
        else:
            break

    while i < end:
        trie = trie.insert(trie_node(k[i]))
        i += 1

    if trie.collation_elements_ != (0, 0) and trie.collation_elements_ != v:
        raise Exception('Error in trie construction -- data lost due to node collision.')

    trie.collation_elements_ = v

def make_trie(cet):
    trie = trie_node(-1)

    for k,v in cet.items():
        trie_insert(trie, k, v)

    return trie

def print_node(trie, indent = -1):
    if trie.cp_ == -1:
        retval = ''
    else:
        retval = '{0}cp={1} coll={2}\n'.format(
            '  ' * indent, hex(trie.cp_), trie.collation_elements_
        )
    for c in sorted(trie.children_):
        retval += print_node(c, indent + 1)
    return retval

def num_descendents(trie):
    if trie.children_ == []:
        return 0
    return len(trie.children_) + reduce(lambda x,y: x + num_descendents(y), trie.children_, 0)

def visit_trie(trie, all_nodes):
    if len(trie.children_) == 0:
        return
    sorted_children = sorted(trie.children_)
    to_append = len(sorted_children)
    N = len(all_nodes) + to_append
    for c in sorted_children:
        num_children = len(c.children_)
        num_descendents_ = num_descendents(c)
        node = trie_node(c.cp_)
        node.children_ = (N, N + num_children)
        node.collation_elements_ = c.collation_elements_
        all_nodes.append(node)
        N += num_descendents_
    for c in sorted_children:
        visit_trie(c, all_nodes)

def flatten_trie(trie):
    hash_lines = ''
    trie_lines = ''

    all_nodes = []
    visit_trie(trie, all_nodes)
    num_root_children = len(trie.children_)
    i = 0
    for n in all_nodes:
        line = '        {{ {}, {}, {}, {{ {}, {}, }} }},\n'.format(
            hex(n.cp_),
            n.children_[0] - num_root_children, n.children_[1] - num_root_children,
            n.collation_elements_[0], n.collation_elements_[1]
        )
        if i < num_root_children:
            hash_lines += line
        else:
            trie_lines += line
        i += 1

    return (hash_lines, trie_lines, len(all_nodes))

def find_singleton_keys(cet, trie):
    non_singleton_initial_cps = set(map(lambda x: x.cp_, trie.children_))
    singleton_keys = set()
    for k,v in cet.items():
        if len(k) == 1 and k[0] not in non_singleton_initial_cps:
            singleton_keys.add(k)
    return singleton_keys

def ce_to_cpp(ce):
    retval = '{0x'
    if ce[0] == ('',):
        retval += '00000000'
    else:
        retval += ''.join(ce[0])
        retval += '0' * (4 - len(ce[0])) * 2
    retval += ', 0x'
    if ce[1] == ('',):
        retval += '0000'
    else:
        retval += ''.join(ce[1])
        retval += '0' * (2 - len(ce[1])) * 2
    retval += ', 0x'
    if ce[2] == ('',):
        retval += '00'
    else:
        retval += ''.join(ce[2])
        retval += '0' * (1 - len(ce[2])) * 2
    retval += '}'
    return retval

def indices_to_list(indices, all_cps):
    return all_cps[indices[0]:indices[1]]

def group_boundary_line(line):
    return line.startswith('FDD1') and not 'FDD0' in line

def group_boundary_name(line):
    first_idx = line.find(' first')
    return line[:first_idx].split('#')[1].strip()

import re
ce_regex = re.compile(r'\[([^,\]]*)(?:,([^,\]]*)(?:,([^\]]*))?)?\]')
cet_key_regex = re.compile(r'([0-9A-f]+)')

def to_ce(groups, cet):
    def bytes_to_tuple(s):
        return tuple(s.strip().split(' '))
    ce = tuple()
    if groups[0].startswith('U+'):
        if groups[0][2:] in cet:
            ce = cet[groups[0][2:]][0]
        else:
            ce = implicit_ce(int(groups[0][2:], 16))
        if groups[1] != None:
            if groups[2] != None:
                ce = (ce[0], bytes_to_tuple(groups[1]), bytes_to_tuple(groups[2]))
            else:
                ce = (ce[0], ce[1], bytes_to_tuple(groups[1]))
    else:
        ce = tuple(map(lambda x: x == None and ('00',) or bytes_to_tuple(x), groups))

    return ce

def get_frac_uca_cet(filename):
    lines = open(filename, 'r').readlines()

    cet = {}

    # Those a | b keys go here so they can be processed after the "a" part has
    # been seen.
    deferred = {}

    in_top_bytes = False
    after_top_bytes = False
    before_homeless_ces = True
    for line in lines:
        line = line[:-1]
        if '[top_byte' in line:
            in_top_bytes = True
        if in_top_bytes and '[top_byte' not in line:
            after_top_bytes = True
        if 'HOMELESS COLLATION ELEMENTS' in line:
            before_homeless_ces = False
        if not line.startswith('#') and not line.startswith('@') and len(line) != 0:
            if after_top_bytes and before_homeless_ces:
                comment_start = line.find('#')
                comment = ''
                if comment_start != -1:
                    comment = line[comment_start + 1:].strip()
                    line = line[:comment_start]
                before_semicolon = line.split(';')[0]
                key = tuple(map(
                    lambda x: int(x.group(1), 16),
                    cet_key_regex.finditer(before_semicolon)
                ))
                ces = []
                for match in ce_regex.finditer(line):
                    ces.append(to_ce(match.groups(), cet))
                ces = tuple(ces)
                if '|' in before_semicolon:
                    deferred[key] = ces
                cet[key] = ces

    for k,v in deferred.items():
        cet[k] = cet[(k[0],)] + v

    return cet

def get_group_boundary_to_token_mapping(filename):
    lines = open(filename, 'r').readlines()

    top_byte_tokens = {}
    token_names = []
    group_boundary_names = []
    group_boundary_top_bytes = {}
    implicit_bytes = []

    for line in lines:
        if line.startswith('[top_byte'):
            fields = line.split('\t')
            tokens = fields[2].split(' ')
            for i in range(len(tokens)):
                if ']' in tokens[i] or 'COMPRESS' in tokens[i]:
                    tokens = tokens[:i]
                    break
            top_byte_tokens[fields[1]] = tokens
            if tokens == ['IMPLICIT']:
                implicit_bytes.append(int(fields[1], 16))
            for tok in tokens:
                token_names.append(tok)
        if group_boundary_line(line):
            name = group_boundary_name(line)
            group_boundary_names.append(name)
            group_boundary_top_bytes[name] = line.split('[')[1][:2]

    name_map = {
        'SPACE': 'space',
        'PUNCTUATION': 'punct',
        'SYMBOL': 'symbol',
        'CURRENCY': 'currency',
        'DIGIT': 'digit',
        'Miao': 'Plrd',
        'HAN': 'Hani',
        'Khudawadi': 'Sind',
        'Phoenician': 'Phnx',
        'Tai Tham': 'Lana',
        'Old Turkic': 'Orkh',
        'SHAVIAN': 'Shaw',
    }
    for boundary in group_boundary_names:
        p = False
        top_byte = boundary in group_boundary_top_bytes and group_boundary_top_bytes[boundary] or 'NA'
        if p:
            print boundary,top_byte,top_byte_tokens[top_byte]
        all_hits = []
        for i in range(len(token_names)):
            hits = 0
            if token_names[i] in (top_byte in top_byte_tokens and top_byte_tokens[top_byte] or []):
                a = boundary.lower()
                b = token_names[i].lower()
                for c in b:
                    if c in a:
                        hits += 1
                if p:
                    print hits,a,b
            all_hits.append(hits)
        max_ = 0
        max_index = 0
        for i in range(len(all_hits)):
            if max_ < all_hits[i]:
                max_ = all_hits[i]
                max_index = i
        if max_ == 4:
            name_map[boundary] = token_names[max_index]

    return (name_map, implicit_bytes)

if __name__ == "__main__":
    (boundary_to_token, implicit_bytes) = get_group_boundary_to_token_mapping('FractionalUCA.txt')

    if implicit_bytes[-1] - implicit_bytes[0] != 4:
        raise Exception('Oops!  Broken assumption about the FractionalUCA.txt table data.')
    if implicit_bytes[0] & 0xfc != implicit_bytes[0]:
        raise Exception('Oops!  Broken assumption about the FractionalUCA.txt table data.')

    # There are 98020 code points explicitly handled in the implicit weights
    # calculations (counting ranges like CJK_Unified_Ideographs_Extension_D as
    # blocks, not individual elements), which fits in 16.58 bits.  With a
    # spacng of 8, it all fits within 20 bits.
    implicit_weights_spacing = 8

    implicit_weights_first_primary_byte = implicit_bytes[0] & 0xfc

    implicit_weights_final_byte = implicit_bytes[-1]

    implicit_weights_cp_ranges = [
        (0x17000, 0x18AFF + 1), # Tangut and Tangut Components
        (0x1B170, 0x1B2FF + 1), # Nushu
        (0x4E00, 0x9FEA + 1),   # Core Han Unified Ideographs
        (0xFA0E, 0xFA29 + 1),   # CJK_Compatibility_Ideographs
        (0x3400, 0x4DB5 + 1),   # All other Han Unified Ideographs
        (0x20000, 0x2A6D6 + 1),
        (0x2A700, 0x2B734 + 1),
        (0x2B740, 0x2B81D + 1), # CJK_Unified_Ideographs_Extension_D
        (0x2B820, 0x2CEA1 + 1),
        (0x2CEB0, 0x2EBE0 + 1)
    ]

    current_offset = 0
    implicit_weights_segments = []
    for r in implicit_weights_cp_ranges:
        implicit_weights_segments.append((r, current_offset))
        current_offset = int(current_offset + (r[1] - r[0]) * implicit_weights_spacing)

    cet = get_frac_uca_cet('FractionalUCA.txt')

    cccs_dict = cccs('DerivedCombiningClass.txt')
    (all_cps, decomposition_mapping) = \
      get_decompositions('UnicodeData.txt', cccs_dict, expand_decomp_canonical, True)
    decomposition_mapping = filter(lambda x: x[1][1], decomposition_mapping)
    decomposition_mapping = \
      map(lambda x: (x[0], indices_to_list(x[1], all_cps)), decomposition_mapping)
    decomposition_mapping = dict(decomposition_mapping)

    fcc_cet = cet_from_cet_and_decompositions(cccs_dict, cet, decomposition_mapping)

    (fcc_cet, collation_elements) = make_unique_collation_element_sequence(fcc_cet)

    hpp_file = open('collation_constants.hpp', 'w')
    hpp_file.write(constants_header_form.format(
        hex(OR_CJK_Compatibility_Ideographs),
        hex(OR_CJK_Unified_Ideographs_Extension_D),
        int(implicit_weights_spacing * 10),
        hex(implicit_weights_first_primary_byte),
        hex(implicit_bytes[-1]),
        len(implicit_weights_segments)
    ))

    item_strings = map(lambda x: ce_to_cpp(x), collation_elements)
    collation_elements_list = '    ' + ',\n    '.join(item_strings) + ',\n'
    weights_strings = map(lambda x: '{{{}, {}, {}}}'.format(hex(x[0][0]), hex(x[0][1]), x[1]), implicit_weights_segments)
    implicit_weights_segments_str = '    ' + ',\n    '.join(weights_strings) + ',\n'
    cpp_file = open('collation_data_0.cpp', 'w')
    cpp_file.write(collation_elements_file_form.format(implicit_weights_segments_str, len(implicit_weights_segments), collation_elements_list, len(collation_elements)))

    trie = make_trie(fcc_cet)

    (hash_lines, trie_lines, num_trie_lines) = flatten_trie(trie)

    singleton_keys = find_singleton_keys(fcc_cet, trie)

    cpp_file = open('collation_data_1.cpp', 'w')
    cpp_file.write(multiple_cp_key_file_form.format(hash_lines, trie_lines, num_trie_lines, len(trie.children_)))
