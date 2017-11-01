from collections import deque

IN_ORDER=0
PRE_ORDER=1
POST_ORDER=2

class Node:
    def __init__(self, value, left, right):
        self.value = value
        self.left = left
        self.right = right

    def output(self, order):
        if order == PRE_ORDER:
            print(self.value),

        if self.left:
            self.left.output(order)

        if order == IN_ORDER:
            print(self.value),

        if self.right:
            self.right.output(order)

        if order == POST_ORDER:
            print(self.value),

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, value):
        if self.root:
            node = self.root
            while True:
                if node.value < value:
                    if node.right:
                        node = node.right
                    else:
                        break
                elif node.value > value:
                    if node.left:
                        node = node.left
                    else:
                        break
                elif node.value == value:
                    # Ignore duplicate.
                    return

            if node.value < value:
                node.right = Node(value, None, None)
            elif node.value > value:
                node.left = Node(value, None, None)
        else:
            self.root = Node(value, None, None)

    def inorder(self):
        self.root.output(IN_ORDER)
        print

    def preorder(self):
        self.root.output(PRE_ORDER)
        print

    def postorder(self):
        self.root.output(POST_ORDER)
        print

    def by_level(self):
        q = deque([self.root])
        while q:
            level = deque()
            level.extend(q)
            q.clear()
            for node in level:
                print(node.value),
                print(' '),
                if node.left:
                    q.append(node.left)
                if node.right:
                    q.append(node.right)
            print

if __name__ == '__main__':
    bst = BinarySearchTree()
    for v in [10, 5, 15, 2, 7, 12, 17, 1, 3, 6, 8, 11, 13, 16, 18]:
        bst.insert(v)

    print 'inorder'
    bst.inorder()

    print 'preorder'
    bst.preorder()

    print 'postorder'
    bst.postorder()

    print 'by_level'
    bst.by_level()
