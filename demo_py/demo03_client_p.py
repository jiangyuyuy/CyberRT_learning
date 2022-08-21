
import sys
from cyber.python.cyber_py3 import cyber
from cyber.demo_base_proto.addints_pb2 import AddInts_Request
from cyber.demo_base_proto.addints_pb2 import AddInts_Responce

if __name__ == "__main__":

    if len(sys.argv) != 3:
        print("Please input two numbers!")
        sys.exit(1)
    
    cyber.init()
    print("Client doing...")
    client_node = cyber.Node("client_node_py")
    client = client_node.create_client("addints", AddInts_Request, AddInts_Responce)
    
    req = AddInts_Request()
    req.num1 = int(sys.argv[1])
    req.num2 = int(sys.argv[2])
    print("num1: ", req.num1, ", num2: ", req.num2)
    responce = client.send_request(req)
    print("sum: ", responce.sum)
    print("multi: ", responce.multi)

    cyber.shutdown()