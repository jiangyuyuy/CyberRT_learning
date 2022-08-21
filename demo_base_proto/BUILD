load("//tools:python_rules.bzl", "py_proto_library")
package(default_visibility = ["//visibility:public"])

proto_library(
    name = "student_proto",
    srcs = ["student.proto"],
)

cc_proto_library(
    name = "student_cc",
    deps = [":student_proto"]
)

py_proto_library(
    name = "student_py",
    deps = [":student_proto"]
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "test_student",
    srcs = ["test_student.cc"],
    deps = [":student_cc"],
)

py_binary(
    name = "test_student_p",
    srcs = ["test_student_p.py"],
    deps = [":student_py"],
)


# -------------------------------------------
proto_library(
    name = "addints_proto",
    srcs = ["addints.proto"],
)

cc_proto_library(
    name = "addints_proto_cc",
    deps = [":addints_proto"]
)

py_proto_library(
    name = "addints_proto_py",
    deps = [":addints_proto"]
)