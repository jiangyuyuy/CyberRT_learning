#include "cyber/cyber.h"
#include "cyber/component/component.h"
#include "cyber/demo_base_proto/student.pb.h"

using apollo::cyber::Component;
using apollo::cyber::demo_base_proto::Student;


class CommonCpt:public Component<Student>{
public:
    bool Init() override;
    bool Proc(const std::shared_ptr<Student>& stu) override;
};

CYBER_REGISTER_COMPONENT(CommonCpt)