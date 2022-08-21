from cyber.demo_base_proto.student_pb2 import Student

if __name__ == "__main__":
    stu = Student()
    stu.name = "JiangYu"
    stu.book.append("C++")
    stu.book.append("Python")

    name = stu.name
    print("name: ", name)

    for i, book in enumerate(stu.book):
        print(f"book<{i+1}> : {book}")