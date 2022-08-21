#include "cyber/cyber.h"
#include "cyber/demo_base_proto/addints.pb.h"

using apollo::cyber::demo_base_proto::AddInts_Request;
using apollo::cyber::demo_base_proto::AddInts_Responce;


int main(int argc, char *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "Client doing...";
    if (argc != 3)
    {
        AINFO << "Please input two numbers!";
        return 1;
    }

    auto client_node = apollo::cyber::CreateNode("client_node_");
    auto client = client_node->CreateClient<AddInts_Request, AddInts_Responce>("addints");
    
    AINFO << "Waiting Server...";

    auto request = std::make_shared<AddInts_Request>();
    request->set_num1(atoll(argv[1]));
    request->set_num2(atoll(argv[2]));
    AINFO << "Send num1: " << request->num1() << ", Send num2: " 
        << request->num2();
    auto responce = client->SendRequest(request);
    AINFO << "sum: " << responce->sum();
    AINFO << "multi: " << responce->multi();

    apollo::cyber::WaitForShutdown();
    return 0;
}