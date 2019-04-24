cmake_minimum_required(VERSION 3.13)
project(1__Instruments_to_Stringed_Instruments)

set(CMAKE_CXX_STANDARD 14)

add_executable(1__Instruments_to_Stringed_Instruments main.cpp Instrument.cpp Instrument.h StringedInstrument.cpp StringedInstrument.h ElectricGuitar.cpp ElectricGuitar.h BassGuitar.cpp BassGuitar.h Violin.cpp Violin.h)