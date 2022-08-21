package(default_visibility = ["//visibility:public"])

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "demo00_helloworld",
    srcs = ["demo00_helloworld.cc"],
    deps = ["//cyber"],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "demo01_talker",
    srcs = ["demo01_talker.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:student_cc",
        ],
)

cc_binary(
    name = "demo01_listener",
    srcs = ["demo01_listener.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:student_cc",
        ],
)


cc_binary(
    name = "demo03_server",
    srcs = ["demo03_server.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:addints_proto_cc",
        ],
)

cc_binary(
    name = "demo03_client",
    srcs = ["demo03_client.cc"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:addints_proto_cc",
        ],
)

cc_binary(
    name = "demo05_param_server",
    srcs = ["demo05_param_server.cc"],
    deps = [
        "//cyber",
        "//cyber/parameter",
        ],
)