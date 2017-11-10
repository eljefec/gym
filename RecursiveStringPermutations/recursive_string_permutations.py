def permutations_recursive(s, i):
	if i == 0:
		return [str(s[0])]
	else:
		perms = permutations_recursive(s, i - 1)
		new_perms = []
		for perm in perms:
			j_end = len(perm)+1
			for j in range(j_end):
				left = perm[0:j]
				right = perm[j:j_end-j]
				new_perm = left + s[i] + right
				new_perms.append(new_perm)
		return new_perms

def permutations(s):
	return permutations_recursive(s, len(s) - 1)

if __name__ == '__main__':
	print(permutations('abc'))