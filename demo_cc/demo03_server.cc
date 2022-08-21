#include "cyber/cyber.h"
#include "cyber/demo_base_proto/addints.pb.h"

using apollo::cyber::demo_base_proto::AddInts_Request;
using apollo::cyber::demo_base_proto::AddInts_Responce;

void cb(const std::shared_ptr<AddInts_Request>& request, const std::shared_ptr<AddInts_Responce>& responce)
{
    int64_t num1 = request->num1();
    int64_t num2 = request->num2();

    AINFO << "num1: " << num1 << ", num2: " << num2;
    int16_t sum = num1 + num2;
    int16_t multi = num1 * num2;
    responce->set_sum(sum);
    responce->set_multi(multi);
    std::cout << "--------------------------" << std::endl;
}

int main(int argc, char *argv[])
{
    apollo::cyber::Init(argv[0]);
    AINFO << "Server doing..." ;
    
    auto server_node = apollo::cyber::CreateNode("server_node_");
    auto server = server_node->CreateService<AddInts_Request, AddInts_Responce>("addints", cb);
    apollo::cyber::WaitForShutdown();
    return 0;
}