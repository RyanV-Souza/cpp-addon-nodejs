#include <node.h>
namespace demo
{

  using v8::Array;
  using v8::Context;
  using v8::Exception;
  using v8::FunctionCallbackInfo;
  using v8::Isolate;
  using v8::Local;
  using v8::Number;
  using v8::Object;
  using v8::Value;

  void SumArray(const FunctionCallbackInfo<Value> &args)
  {
    Isolate *isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();

    Local<Array> array = Local<Array>::Cast(args[0]);
    uint32_t length = array->Length();
    double sum = 0;
    args.GetReturnValue().Set(Number::New(isolate, sum));
  }

  void Initialize(Local<Object> exports)
  {
    NODE_SET_METHOD(exports, "sum", SumArray);
  }

  NODE_MODULE(NODE_GYP_MODULE_NAME, Initialize)

} // namespace demo