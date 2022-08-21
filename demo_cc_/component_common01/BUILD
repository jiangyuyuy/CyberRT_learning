package(default_visibility = ["//visibility:public"])
load("//tools/install:install.bzl","install")

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_library(
    name = "common_cpt_lib",
    srcs = ["common_cpt.cc"],
    hdrs = ["common_cpt.h"],
    deps = [
        "//cyber",
        "//cyber/demo_base_proto:student_cc",
        ],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "lib_common_cpt.so",
    linkshared = True,
    linkstatic = False,
    deps = [":common_cpt_lib"],
)

filegroup(
    name="conf",
    srcs=[
        ":cpt.dag",
        ":cpt.launch",
    ],
)

install(
    name="install",
    data=[
        ":conf",
    ],
    runtime_dest="cyber/demo_cc_/component_common01",
    targets=[
        "//cyber/demo_cc_:demo01_talker_",
        ":lib_common_cpt.so",
    ],
)