
from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.addints_pb2 import AddInts_Request
from cyber.demo_base_proto.addints_pb2 import AddInts_Responce

def cb(req):
    num1 = req.num1
    num2 = req.num2
    print("num1: ", num1, ", num2: ", num2)
    sum = num1 + num2
    multi = num1 * num2
    responce = AddInts_Responce()
    responce.sum = sum
    responce.multi = multi
    return responce

if __name__ == "__main__":
    cyber.init()
    print("server doing...")
    server_node = cyber.Node("service_node_py")
    server = server_node.create_service("addints", AddInts_Request, AddInts_Responce, cb)
    server_node.spin()
    cyber.shutdown()