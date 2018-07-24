/// Copyright goes here
/// License goes here
/// @author John K. Grant

#ifndef _dcl_dis_data_stream_h_
#define _dcl_dis_data_stream_h_

// the class member, DataStream::BufferType is causing warnign 4251.
// disable it until a proper fix is found, as instructed from the enlightening article:
// http://www.unknownroad.com/rtfm/VisualStudio/warningC4251.html
#if _MSC_VER
#pragma warning( push )
#pragma warning( disable : 4251 )
#endif

#include <string>                 // for typedef, member
#include <vector>                 // for typedef, member
#include <DIS/Endian.h>           // for enum
#include <DIS/msLibMacro.h>       // for library symbols
#include <cstdlib>                // for size_t and NULL definition

namespace DIS
{
   /// a class to support managing a network buffer.
   /// the clients are responsible for managing the char buffer memory.
   /// this class explicitly defines operators for expected types.
   class EXPORT_MACRO DataStream
   {
   public:
      /// Setup the internal buffer's Endian type.
      /// @param stream the Endian type to use for the internal buffer,
      /// which will be used for network socket writes.
      DataStream(Endian stream);

      /// Setup the internal buffer.
      /// @param buffer the data to copy and manage.
      /// @param length the number of bytes in the buffer.
      /// @param stream the Endian type to use for the internal buffer,
      DataStream(const char* buffer, size_t length, Endian stream);
      ~DataStream();

      /// a method for reading the stored buffer data.
      /// @param offset the index distance with respect to the current read point.
      const char& operator [](unsigned int offset) const;

      /// take ownership of the data buffer.
      void SetStream(const char* buffer, size_t length, Endian order);

      // write operations
      DataStream& operator <<(bool c);
      DataStream& operator <<(char c);
      DataStream& operator <<(unsigned char c);
      DataStream& operator <<(float c);
      DataStream& operator <<(double c);
      DataStream& operator <<(int c);
      DataStream& operator <<(unsigned int c);
      DataStream& operator <<(long c);
      DataStream& operator <<(unsigned long c);
      DataStream& operator <<(unsigned short c);
      DataStream& operator <<(short c);

      // read operations
      DataStream& operator >>(bool& c);
      DataStream& operator >>(char& c);
      DataStream& operator >>(unsigned char& c);
      DataStream& operator >>(float& c);
      DataStream& operator >>(double& c);
      DataStream& operator >>(int& c);
      DataStream& operator >>(unsigned int& c);
      DataStream& operator >>(long& c);
      DataStream& operator >>(unsigned long& c);
      DataStream& operator >>(unsigned short& c);
      DataStream& operator >>(short& c);

      Endian GetStreamEndian() const;
      Endian GetMachineEndian() const;

      size_t GetWritePos() const;
      size_t GetReadPos() const;

      size_t size() const;

      void clear();

      bool empty() const;

   private:
      template<typename T, typename IterT>
      void IncrementPointer(IterT& iter)
      {
         iter += sizeof(T);
      }

      template<typename T, typename IterT>
      void DecrementPointer(IterT& iter)
      {
         iter -= sizeof(T);
      }

      /// this algorithm should only be used for primitive types,
      /// because the class size takes into account the virtual function table.
      template<typename T>
      void WriteAlgorithm(T t)
      {
         char* ch = reinterpret_cast<char*>( &t );
         DoFlip( ch , sizeof(T) );
         DoWrite( ch , sizeof(T) );
         IncrementPointer<T>( _write_pos );
      }

      /// this algorithm should only be used for primitive types,
      /// because the class size takes into account the virtual function table.
      template<typename T>
      void ReadAlgorithm(T& t)
      {
         char ch[sizeof(T)];
         DoRead( ch , sizeof(T) );
         DoFlip( ch , sizeof(T) );
         t = *reinterpret_cast<T*>( ch );
         IncrementPointer<T>( _read_pos );
      }

      /// will flip the buffer if the buffer endian is different than the machine's.
      void DoFlip(char* buf, size_t bufsize);

      void DoWrite(const char* buf, size_t bufsize);

      void DoRead(char* ch, size_t bufsize);


      typedef std::vector<char> BufferType;
      //const BufferType& GetBuffer() const;

      BufferType _buffer;

      /// the location of the read/write.
      size_t _read_pos;
      size_t _write_pos;

      /// the requirement for the managed buffer
      Endian _stream_endian;

      /// the native endian type
      Endian _machine_endian;
   };
}

#if _MSC_VER
#pragma warning( pop ) 
#endif

#endif  // _dcl_dis_data_stream_h_
