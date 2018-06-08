class Signature:
    def __init__(self, s=None):
        self.char_freq = dict()
        if s is not None:
            for c in s:
                self.add_char(c)

    def add_char(self, c):
        if c in self.char_freq:
            self.char_freq[c] += 1
        else:
            self.char_freq[c] = 1

    def remove_char(self, c):
        if c in self.char_freq:
            self.char_freq[c] -= 1
        else:
            raise KeyError('Character {} not found'.format(c))

    def equal(self, other):
        return self.char_freq == other.char_freq

def is_permutation_substring(a, b):
    sig_a = Signature(a)
    sig_b = Signature(b[:len(a)])
    if sig_a.equal(sig_b):
        return True
    for i in range(len(b)-len(a)):
        sig_b.remove_char(b[i])
        sig_b.add_char(b[i+len(a)])
        if sig_a.equal(sig_b):
            return True
    return False

def main():
    print(is_permutation_substring('abc', 'cabbie'))
    print(is_permutation_substring('abc', 'caddie'))

if __name__ == '__main__':
    main()
