from collections import defaultdict

# L strings.
# Assume longest string is S.
def group_anagrams(strings):
    # O(L*S*log(S))
    sorted_list = []
    for s in strings:
        sorted_list.append(''.join(sorted(s)))

    # O(L*1*log(A))
    anagram_groups = defaultdict(list)
    for s, orig in zip(sorted_list, strings):
        if s in anagram_groups:
            group = anagram_groups[s]
            group.add(orig)
        else:
            anagram_groups[s] = set([orig])

    return anagram_groups

print(group_anagrams(['abc', 'cba']))
