
from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.student_pb2 import Student
import time

def talker():
    talker_node = cyber.Node("talker_node_p")
    talker = talker_node.create_writer("topic_2", Student)

    seq = 0
    while not cyber.is_shutdown():
        seq += 1
        print(f"message No.{seq}")
        stu = Student()
        stu.name = "Jiang"
        stu.age = 18
        stu.height = 1.80
        stu.book.append("Math")
        stu.book.append("Chinese")

        talker.write(stu)
        time.sleep(2.0)


if __name__ == "__main__":
    cyber.init()
    talker()
    cyber.shutdown()