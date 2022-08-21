#include "cyber/demo_base_proto/student.pb.h"
using namespace std;

int main(int argc, char *argv[])
{
    apollo::cyber::demo_base_proto::Student stu;
    stu.set_name("JiangYu");
    stu.set_age(20);
    stu.set_height(1.80);
    stu.add_book("Math");
    stu.add_book("Chinese");

    string name = stu.name();
    uint64_t age = stu.age();
    double height = stu.height();

    cout << "name: " << name << endl;
    cout << "age: " << age << endl;
    cout << "height: " << height << endl;
    for(int i = 0;i < stu.book_size(); i++)
    {
        string book = stu.book(i);
        cout << "book<" << i << "> : " << book << endl;
    }
    cout << endl;
    return 0;
}
