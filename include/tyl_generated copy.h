// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_TYL_H_
#define FLATBUFFERS_GENERATED_TYL_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 24 &&
              FLATBUFFERS_VERSION_MINOR == 3 &&
              FLATBUFFERS_VERSION_REVISION == 25,
             "Non-compatible flatbuffers version included");

struct TYL;
struct TYLBuilder;

struct TYL FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef TYLBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_ID = 4,
    VT_NAME = 6,
    VT_VALUE = 8
  };
  int32_t id() const {
    return GetField<int32_t>(VT_ID, 0);
  }
  const ::flatbuffers::String *name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_NAME);
  }
  const ::flatbuffers::Vector<int32_t> *value() const {
    return GetPointer<const ::flatbuffers::Vector<int32_t> *>(VT_VALUE);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int32_t>(verifier, VT_ID, 4) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyVector(value()) &&
           verifier.EndTable();
  }
};

struct TYLBuilder {
  typedef TYL Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_id(int32_t id) {
    fbb_.AddElement<int32_t>(TYL::VT_ID, id, 0);
  }
  void add_name(::flatbuffers::Offset<::flatbuffers::String> name) {
    fbb_.AddOffset(TYL::VT_NAME, name);
  }
  void add_value(::flatbuffers::Offset<::flatbuffers::Vector<int32_t>> value) {
    fbb_.AddOffset(TYL::VT_VALUE, value);
  }
  explicit TYLBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<TYL> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<TYL>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<TYL> CreateTYL(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int32_t id = 0,
    ::flatbuffers::Offset<::flatbuffers::String> name = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<int32_t>> value = 0) {
  TYLBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_name(name);
  builder_.add_id(id);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<TYL> CreateTYLDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    int32_t id = 0,
    const char *name = nullptr,
    const std::vector<int32_t> *value = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto value__ = value ? _fbb.CreateVector<int32_t>(*value) : 0;
  return CreateTYL(
      _fbb,
      id,
      name__,
      value__);
}

inline const TYL *GetTYL(const void *buf) {
  return ::flatbuffers::GetRoot<TYL>(buf);
}

inline const TYL *GetSizePrefixedTYL(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<TYL>(buf);
}

inline bool VerifyTYLBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<TYL>(nullptr);
}

inline bool VerifySizePrefixedTYLBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<TYL>(nullptr);
}

inline void FinishTYLBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<TYL> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedTYLBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<TYL> root) {
  fbb.FinishSizePrefixed(root);
}

#endif  // FLATBUFFERS_GENERATED_TYL_H_
