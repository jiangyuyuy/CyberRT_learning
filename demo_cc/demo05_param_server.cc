#include "cyber/cyber.h"
#include "cyber/parameter/parameter_server.h"

using apollo::cyber::ParameterServer;
using apollo::cyber::Parameter;

int main(int argc, char *argv[]){
    apollo::cyber::Init(argv[0]);
    AINFO << "Create Parameters Server...";

    std::shared_ptr<apollo::cyber::Node> param_service_node = 
        apollo::cyber::CreateNode("param_");
    auto param_service = std::make_shared<ParameterServer>(param_service_node);

    param_service->SetParameter(Parameter("type", "apollo_car"));
    param_service->SetParameter(Parameter("height", 1.80));
    param_service->SetParameter(Parameter("lasers", 4));

    Parameter temp;
    param_service->GetParameter("type", &temp);
    AINFO << temp.Name() << "==" << temp.AsString();
    param_service->GetParameter("height", &temp);
    AINFO << temp.Name() << "==" << temp.AsDouble();
    param_service->GetParameter("lasers", &temp);
    AINFO << temp.Name() << "==" << temp.AsInt64();

    std::vector<Parameter> params;
    param_service->ListParameters(&params);

    for(auto &&param:params){
        AINFO << param.Name() << " -----> " << param.TypeName() 
        << " -----> " << param.DebugString();
    }

    param_service->SetParameter(Parameter("lasers", 100));param_service->GetParameter("lasers", &temp);
    AINFO << temp.Name() << "==" << temp.AsInt64();
    apollo::cyber::WaitForShutdown();
    return 0;

}