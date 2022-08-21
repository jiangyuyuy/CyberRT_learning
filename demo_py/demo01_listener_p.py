from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.student_pb2 import Student

def cb(stu):
    print("Name: ", stu.name, ", age: ", stu.age, ", height: ", stu.height)
    for i, book in enumerate(stu.book):
        print("book<", i, "> : ", book)
    print("-" * 30)


def listener():
    listener_node = cyber.Node("listener_node_p")
    listener = listener_node.create_reader("topic_2", Student, cb)

    listener_node.spin()

if __name__ == "__main__":
    cyber.init()
    listener()
    cyber.shutdown()