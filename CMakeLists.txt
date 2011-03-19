project(SMHasher)

cmake_minimum_required(VERSION 2.4)

add_library(
  SMHasherSupport
  AvalancheTest.cpp
  Bitslice.cpp
  Bitvec.cpp
  crc.cpp
  DifferentialTest.cpp
  Hashes.cpp
  KeysetTest.cpp
  lookup3.cpp
  md5.cpp
  MurmurHash1.cpp
  MurmurHash2.cpp
  MurmurHash2_test.cpp
  MurmurHash3.cpp
  MurmurHash64.cpp
  MurmurHashAligned2.cpp
  MurmurHashAligned.cpp
  MurmurHashNeutral2.cpp
  MurmurHashTest.cpp
  Platform.cpp
  Random.cpp
  sha1.cpp
  SpeedTest.cpp
  Stats.cpp
  SuperFastHash.cpp
  Types.cpp
)

add_executable(
  SMHasher
  main.cpp
)

target_link_libraries(
  SMHasher
  SMHasherSupport
)
