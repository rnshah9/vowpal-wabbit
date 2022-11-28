#include "hash.h"

#include <fuzzer/FuzzedDataProvider.h>
#include <stdint.h>
#include <stdio.h>

#include <climits>

extern "C" int LLVMFuzzerTestOneInput(const uint8_t* data, size_t size)
{
  FuzzedDataProvider provider(data, size);
  uint32_t x = provider.ConsumeIntegral<uint32_t>();
  uint8_t r = provider.ConsumeIntegral<uint8_t>();
  VW::details::rotl32(x, r);

  return 0;
}