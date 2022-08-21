#include "cyber/cyber.h"
#include "cyber/demo_base_proto/student.pb.h"

using apollo::cyber::demo_base_proto::Student;

void cb(const std::shared_ptr<Student>& stu)
{
    AINFO << "name: " << stu->name();
    AINFO << "age: " << stu->age();
    AINFO << "height: " << stu->height();
    for(int i = 0; i < stu->book_size(); i++)
    {
        AINFO << "book<" << (i+1) << "> : " << stu->book(i);
    } 
}

int main(int argc, char *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "Create listener..." ;
    auto listener_node = apollo::cyber::CreateNode("listener_node_");
    auto listener = listener_node->CreateReader<Student>("topic_1", cb);

    apollo::cyber::WaitForShutdown();
    return 0;
}