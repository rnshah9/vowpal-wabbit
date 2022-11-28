FROM --platform=linux/amd64 ubuntu:22.04 as builder

RUN apt-get update
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y build-essential cmake libboost-math-dev libboost-test-dev libz-dev git clang

RUN git clone https://github.com/google/flatbuffers.git
WORKDIR /flatbuffers
RUN cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release
RUN make -j8
RUN make install

COPY . /repo
WORKDIR /repo/build
RUN cmake .. -DBUILD_FLATBUFFERS=1
RUN make -j8
RUN clang++ /repo/mayhem/fuzz_rotl32.cpp -fsanitize=fuzzer,address -I /repo/vowpalwabbit/common/include/vw/common/ -I /repo/vowpalwabbit/common/include/ -o /fuzz

FROM ubuntu:22.04 as package
COPY --from=builder /repo/build/utl/flatbuffer/to_flatbuff /
COPY --from=builder /fuzz /fuzz_rotl32
