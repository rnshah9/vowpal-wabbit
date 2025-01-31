#include "vw/core/vw.h"

#include <jni.h>

// some JNI helper

// properly de-alloc resource also in case of exceptions
class StringGuard
{
  JNIEnv* _env;
  jstring _source;
  const char* _cstr;
  size_t _length;

public:
  StringGuard(JNIEnv* env, jstring source);
  ~StringGuard();

  const char* c_str();
  size_t length();
};

// properly de-alloc resource also in case of exceptions
class CriticalArrayGuard
{
  JNIEnv* _env;
  jarray _arr;
  void* _arr0;

public:
  CriticalArrayGuard(JNIEnv* env, jarray arr);
  ~CriticalArrayGuard();

  void* data();
};

// bind VW instance and example together to reduce the number of variables passed around
class VowpalWabbitExampleWrapper
{
public:
  VW::workspace* _all;
  example* _example;

  VowpalWabbitExampleWrapper(VW::workspace* all, example* example) : _all(all), _example(example) {}
};