py_binary(
    name = "demo00_helloworld_p",
    srcs = ["demo00_helloworld_p.py"],
    deps = ["//cyber/python/cyber_py3:cyber"],
)

py_binary(
    name = "demo01_talker_p",
    srcs = ["demo01_talker_p.py"],
    deps = [
        "//cyber/python/cyber_py3:cyber",
        "//cyber/demo_base_proto:student_py"
        ],
)
py_binary(
    name = "demo01_listener_p",
    srcs = ["demo01_listener_p.py"],
    deps = [
        "//cyber/python/cyber_py3:cyber",
        "//cyber/demo_base_proto:student_py"
        ],
)

py_binary(
    name = "demo03_server_p",
    srcs = ["demo03_server_p.py"],
    deps = [
        "//cyber/python/cyber_py3:cyber",
        "//cyber/demo_base_proto:addints_proto_py"
        ],
)

py_binary(
    name = "demo03_client_p",
    srcs = ["demo03_client_p.py"],
    deps = [
        "//cyber/python/cyber_py3:cyber",
        "//cyber/demo_base_proto:addints_proto_py"
        ],
)
