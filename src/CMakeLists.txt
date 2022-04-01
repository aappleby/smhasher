project(SMHasher)

include_directories(3rd-party/crc32c/include)
include_directories(3rd-party/crc32c/third_party/benchmark/include)
include_directories(3rd-party/crc32c/third_party/glog/src)
include_directories(3rd-party/highwayhash)
include_directories(3rd-party)

cmake_minimum_required(VERSION 2.4)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS "--std=c++20 -g3 -O0")

add_library(
  SMHasherSupport
  AvalancheTest.cpp
  Bitslice.cpp
  Bitvec.cpp
  CityTest.cpp
  City.cpp
  crc.cpp
  DifferentialTest.cpp
  Hashes.cpp
  KeysetTest.cpp
  lookup3.cpp
  md5.cpp
  MurmurHash1.cpp
  MurmurHash2.cpp
  MurmurHash3.cpp
  Platform.cpp
  Random.cpp
  sha1.cpp
  SpeedTest.cpp
  Spooky.cpp
  SpookyTest.cpp
  Stats.cpp
  SuperFastHash.cpp
  Types.cpp
  PMurHash.c
  3rd-party/crc32c/src/crc32c.cc
  3rd-party/crc32c/src/crc32c_arm64.cc
  3rd-party/crc32c/src/crc32c_benchmark.cc
  3rd-party/crc32c/src/crc32c_portable.cc
  3rd-party/crc32c/src/crc32c_sse42.cc
       3rd-party/highwayhash/highwayhash/arch_specific.cc
       3rd-party/highwayhash/highwayhash/c_bindings.cc
       3rd-party/highwayhash/highwayhash/hh_neon.cc
       3rd-party/highwayhash/highwayhash/hh_portable.cc
       3rd-party/highwayhash/highwayhash/hh_vsx.cc
       3rd-party/highwayhash/highwayhash/instruction_sets.cc
       3rd-party/highwayhash/highwayhash/os_mac.cc
       3rd-party/highwayhash/highwayhash/os_specific.cc
       3rd-party/highwayhash/highwayhash/scalar_sip_tree_hash.cc
       3rd-party/highwayhash/highwayhash/sip_hash.cc
       3rd-party/highwayhash/highwayhash/sip_hash_fuzzer.cc
       3rd-party/highwayhash/highwayhash/sip_tree_hash.cc
        3rd-party/crc32_chromium/crc32_simd.h 3rd-party/crc32_chromium/crc32_simd.cpp)

EXECUTE_PROCESS( COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE)
message( STATUS"Architecture: ${ARCHITECTURE}" )
if ( ${ARCHITECTURE} STREQUAL "arm64" )
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_ARMV8_CRC32C")
    add_library(crc32c_pg 3rd-party/crc32c_pg/pg_crc32c_armv8.cpp)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -DUSE_SSE42_CRC32C")
    add_library(crc32c_pg 3rd-party/crc32c_pg/pg_crc32c_sse42.c)
endif()

add_executable(
  SMHasher
  main.cpp
)

target_link_libraries(
  SMHasher
  SMHasherSupport
  crc32c_pg
)
