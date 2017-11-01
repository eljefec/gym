def generate_lowest_number(number_string, removal_goal):
    assert(removal_goal < len(number_string))

    removal_set = set()

    for _ in range(removal_goal):
        removed = False
        max_char_i = 0
        for c in number_string[1:]:
            if c < number_string[max_char_i] and max_char_i not in removal_set:
                removal_set.add(max_char_i)
                removed = True
                break
            else:
                max_char_i += 1

        if not removed:
            removal_set.add(len(number_string) - 1)

    result = ''
    for i in range(len(number_string)):
        if i not in removal_set:
            result += number_string[i]
    return result

if __name__ == '__main__':
    assert('123' == generate_lowest_number('1234', 1))
    assert('321' == generate_lowest_number('4321', 1))
    assert('012' == generate_lowest_number('4205123', 4))
    assert('104' == generate_lowest_number('216504', 3))
