import random

class Problem:
	def __init__(self, category, description):
		self.category = category
		self.description = description

	def __repr__(self):
		return str(self.category) + ',' + self.description

class ProblemPicker:
	def __init__(self, problem_file):
		self.problems = []
		with open(problem_file, 'rt') as f:
			for line in f:
				tokens = line.split('\t')
				if len(tokens) == 2:
					problem = Problem(tokens[0], tokens[1])
					self.problems.append(problem)
				else:
					prev_problem = self.problems[len(self.problems) - 1]
					prev_problem.description += tokens[2]
		self.random = random.Random()

	def pick_problem(self):
		return self.random.choice(self.problems)

if __name__ == '__main__':
	picker = ProblemPicker('problems.txt')
	p = picker.pick_problem()
	print()
	if p.category == '4':
		print('Category: System Design')
	print('Description: ', p.description)