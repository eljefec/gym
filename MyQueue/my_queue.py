class Node:
    def __init__(self, val):
        self.val = val
        self.prev = None
        self.next = None

class MyQueue:
    def __init__(self):
        self.back = None
        self.front = None

    # O(1)
    def push_back(self, val):
        old_back = self.back
        new_back = Node(val)
        self.back = new_back
        if old_back is None:
            self.front = new_back
        else:
            old_back.prev = new_back
        new_back.next = old_back

    # O(1)
    def pop_front(self):
        if self.front is None:
            return None
        result = self.front.val
        new_front = self.front.prev
        self.front = new_front
        if new_front is not None:
            new_front.next = None
        else:
            self.back = None
        return result;

    # O(1)
    def pop_back(self):
        if self.back is None:
            return None
        result = self.back.val
        new_back = self.back.next
        self.back = new_back
        if new_back is not None:
            new_back.prev = None
        else:
            self.front = None
        return result

    # O(N)
    def stringify(self):
        result = ''
        curr = self.front
        while curr is not None:
            result += curr.val
            curr = curr.prev
        return result

def testPushThenStringify():
    q = MyQueue()
    for c in 'string':
        q.push_back(c)
        print(q.stringify())
    result = 'dummy'
    while result is not None:
        result = q.pop_front()
        print(result)

def testPushThenPop():
    q = MyQueue()
    for s in ['string', 'babble', 'wonka']:
        for c in s:
            q.push_back(c)
            print(q.stringify())
        print(q.pop_front())
        print(q.pop_back())
        print(q.stringify())

def testPushThenEmptyThenPush(pop_front):
    q = MyQueue()
    for s in ['string', 'babble', 'wonka']:
        for c in s:
            q.push_back(c)
            print(q.stringify())
        result = 'dummy'
        while result is not None:
            if pop_front:
                result = q.pop_front()
            else:
                result = q.pop_back()
            print(result)

if __name__ == '__main__':
    testPushThenStringify()
    testPushThenPop()
    testPushThenEmptyThenPush(True)
    testPushThenEmptyThenPush(False)

