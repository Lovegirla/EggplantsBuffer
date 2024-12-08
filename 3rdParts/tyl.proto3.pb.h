// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tyl.proto3

#ifndef GOOGLE_PROTOBUF_INCLUDED_tyl_2eproto3
#define GOOGLE_PROTOBUF_INCLUDED_tyl_2eproto3

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021011 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_tyl_2eproto3
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_tyl_2eproto3 {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_tyl_2eproto3;
class TYL;
struct TYLDefaultTypeInternal;
extern TYLDefaultTypeInternal _TYL_default_instance_;
PROTOBUF_NAMESPACE_OPEN
template<> ::TYL* Arena::CreateMaybeMessage<::TYL>(Arena*);
PROTOBUF_NAMESPACE_CLOSE

// ===================================================================

class TYL final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:TYL) */ {
 public:
  inline TYL() : TYL(nullptr) {}
  ~TYL() override;
  explicit PROTOBUF_CONSTEXPR TYL(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  TYL(const TYL& from);
  TYL(TYL&& from) noexcept
    : TYL() {
    *this = ::std::move(from);
  }

  inline TYL& operator=(const TYL& from) {
    CopyFrom(from);
    return *this;
  }
  inline TYL& operator=(TYL&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const TYL& default_instance() {
    return *internal_default_instance();
  }
  static inline const TYL* internal_default_instance() {
    return reinterpret_cast<const TYL*>(
               &_TYL_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(TYL& a, TYL& b) {
    a.Swap(&b);
  }
  inline void Swap(TYL* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(TYL* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  TYL* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<TYL>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const TYL& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom( const TYL& from) {
    TYL::MergeImpl(*this, from);
  }
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message& to_msg, const ::PROTOBUF_NAMESPACE_ID::Message& from_msg);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::PROTOBUF_NAMESPACE_ID::Arena* arena, bool is_message_owned);
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(TYL* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "TYL";
  }
  protected:
  explicit TYL(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kValueFieldNumber = 3,
    kNameFieldNumber = 2,
    kIdFieldNumber = 1,
  };
  // repeated int32 value = 3;
  int value_size() const;
  private:
  int _internal_value_size() const;
  public:
  void clear_value();
  private:
  int32_t _internal_value(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      _internal_value() const;
  void _internal_add_value(int32_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      _internal_mutable_value();
  public:
  int32_t value(int index) const;
  void set_value(int index, int32_t value);
  void add_value(int32_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
      value() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
      mutable_value();

  // string name = 2;
  void clear_name();
  const std::string& name() const;
  template <typename ArgT0 = const std::string&, typename... ArgT>
  void set_name(ArgT0&& arg0, ArgT... args);
  std::string* mutable_name();
  PROTOBUF_NODISCARD std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // int32 id = 1;
  void clear_id();
  int32_t id() const;
  void set_id(int32_t value);
  private:
  int32_t _internal_id() const;
  void _internal_set_id(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:TYL)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  struct Impl_ {
    ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t > value_;
    mutable std::atomic<int> _value_cached_byte_size_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
    int32_t id_;
    mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_tyl_2eproto3;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// TYL

// int32 id = 1;
inline void TYL::clear_id() {
  _impl_.id_ = 0;
}
inline int32_t TYL::_internal_id() const {
  return _impl_.id_;
}
inline int32_t TYL::id() const {
  // @@protoc_insertion_point(field_get:TYL.id)
  return _internal_id();
}
inline void TYL::_internal_set_id(int32_t value) {
  
  _impl_.id_ = value;
}
inline void TYL::set_id(int32_t value) {
  _internal_set_id(value);
  // @@protoc_insertion_point(field_set:TYL.id)
}

// string name = 2;
inline void TYL::clear_name() {
  _impl_.name_.ClearToEmpty();
}
inline const std::string& TYL::name() const {
  // @@protoc_insertion_point(field_get:TYL.name)
  return _internal_name();
}
template <typename ArgT0, typename... ArgT>
inline PROTOBUF_ALWAYS_INLINE
void TYL::set_name(ArgT0&& arg0, ArgT... args) {
 
 _impl_.name_.Set(static_cast<ArgT0 &&>(arg0), args..., GetArenaForAllocation());
  // @@protoc_insertion_point(field_set:TYL.name)
}
inline std::string* TYL::mutable_name() {
  std::string* _s = _internal_mutable_name();
  // @@protoc_insertion_point(field_mutable:TYL.name)
  return _s;
}
inline const std::string& TYL::_internal_name() const {
  return _impl_.name_.Get();
}
inline void TYL::_internal_set_name(const std::string& value) {
  
  _impl_.name_.Set(value, GetArenaForAllocation());
}
inline std::string* TYL::_internal_mutable_name() {
  
  return _impl_.name_.Mutable(GetArenaForAllocation());
}
inline std::string* TYL::release_name() {
  // @@protoc_insertion_point(field_release:TYL.name)
  return _impl_.name_.Release();
}
inline void TYL::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  _impl_.name_.SetAllocated(name, GetArenaForAllocation());
#ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
  if (_impl_.name_.IsDefault()) {
    _impl_.name_.Set("", GetArenaForAllocation());
  }
#endif // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:TYL.name)
}

// repeated int32 value = 3;
inline int TYL::_internal_value_size() const {
  return _impl_.value_.size();
}
inline int TYL::value_size() const {
  return _internal_value_size();
}
inline void TYL::clear_value() {
  _impl_.value_.Clear();
}
inline int32_t TYL::_internal_value(int index) const {
  return _impl_.value_.Get(index);
}
inline int32_t TYL::value(int index) const {
  // @@protoc_insertion_point(field_get:TYL.value)
  return _internal_value(index);
}
inline void TYL::set_value(int index, int32_t value) {
  _impl_.value_.Set(index, value);
  // @@protoc_insertion_point(field_set:TYL.value)
}
inline void TYL::_internal_add_value(int32_t value) {
  _impl_.value_.Add(value);
}
inline void TYL::add_value(int32_t value) {
  _internal_add_value(value);
  // @@protoc_insertion_point(field_add:TYL.value)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
TYL::_internal_value() const {
  return _impl_.value_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >&
TYL::value() const {
  // @@protoc_insertion_point(field_list:TYL.value)
  return _internal_value();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
TYL::_internal_mutable_value() {
  return &_impl_.value_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int32_t >*
TYL::mutable_value() {
  // @@protoc_insertion_point(field_mutable_list:TYL.value)
  return _internal_mutable_value();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_tyl_2eproto3
