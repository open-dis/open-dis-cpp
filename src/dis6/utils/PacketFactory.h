/// Copyright goes here
/// License goes here
/// @author John K. Grant
#ifndef _dcl_dis_packet_factory_h_
#define _dcl_dis_packet_factory_h_

#include <cstdint>
#include <map>  // for member

namespace dis {
class Pdu;

/// a utility to make functions
template <class BaseT, class DerivedT>
BaseT* CreateImplementation() {
  return new DerivedT();
}

/// responsible for mapping an ID value to a Pdu type.
class PacketFactory {
 public:
  /// Create a Pdu.
  /// @param id the value representing the "type" of the Pdu.  The value will be
  /// stored in the 3rd position of the buffer, as defined by the DIS
  /// specification.
  /// @return a dynamically allocated instance of a concrete Pdu.  The value
  /// will be 'NULL' if no support for creating the concrete Pdu was registered.
  Pdu* CreatePacket(uint8_t id);

  /// Clean up the memory for the Pdu.
  /// @param pdu The packet to be deleted.
  void DestroyPacket(Pdu* pdu);

  /// Add support for creating the Pdu.
  /// @param id The value identifying the type of the Pdu.
  /// @return 'false' if a packet id was already registered for the Pdu type.
  /// 'true' if support was added.
  template <class T>
  bool RegisterPacket(uint8_t id) {
    FunctionMap::value_type candidate(id, &CreateImplementation<Pdu, T>);
    std::pair<FunctionMap::iterator, bool> result = f_map_.insert(candidate);
    return result.second;
  }

  /// Remove support for creating the Pdu.
  /// @param id The value identifying the type of the Pdu.
  /// @return 'false' if no support previously existed.  'true' if support was
  /// removed.
  bool UnRegisterPacket(char id) { return (f_map_.erase(id) > 0); }

  /// Check to know if the Pdu type is supported.
  /// @param id The value representing the Pdu type.
  /// @return 'true' if support for creating a Pdu was found, 'false' if not
  /// found.
  [[nodiscard]] bool IsRegistered(uint8_t id) const;

 private:
  /// the function signature required for creating Pdu instances.
  using CREATE_FUNC = Pdu* (*)();

  /// the type to contain mappings to functions used to create Pdu instances.
  using FunctionMap = std::map<uint8_t, CREATE_FUNC>;

  /// instance of the storage mechanism for creating Pdu instances.
  FunctionMap f_map_;
};
}  // namespace dis

#endif  // _dcl_dis_packet_factory_h_
