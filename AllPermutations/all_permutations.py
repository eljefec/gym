# Generate all strings of length n using characters from 0 to k-1.
def all_permutations(n, k):
    if n == 1:
        return [str(i) for i in range(k)]
    prev_perms = all_permutations(n - 1, k)
    return [p + str(i) for i in range(k) for p in prev_perms]

    # More procedural equivalent of above return statement:
    # perms = []
    # for p in prev_perms:
    #     for i in range(k):
    #         perms.append(p + str(i))
    # return perms

def test(n, k):
    print(n, k, all_permutations(n, k))

if __name__ == '__main__':
    test(5, 2)
