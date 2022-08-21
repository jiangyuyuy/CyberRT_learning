#include "cyber/cyber.h"
#include "cyber/demo_base_proto/student.pb.h"

using apollo::cyber::demo_base_proto::Student;

int main(int argc, char *argv[])
{   
    apollo::cyber::Init(argv[0]);
    AINFO << "Create talker...";

    auto talker_node = apollo::cyber::CreateNode("talker_node_");

    auto talker = talker_node->CreateWriter<Student>("topic_1");

    uint64_t seq = 0;
    apollo::cyber::Rate rate(0.5);
    while(apollo::cyber::OK())
    {
        seq++;
        AINFO << "Send " << seq << "th data.";
        auto msg = std::make_shared<Student>();
        msg->set_name("Jiang");
        msg->set_age(18);
        msg->set_height(1.80);
        msg->add_book("Chinese");
        msg->add_book("English");

        talker->Write(msg);
        rate.Sleep();
    }
    apollo::cyber::WaitForShutdown();
    return 0;
}