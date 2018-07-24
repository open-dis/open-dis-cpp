#include <DIS/DataStream.h>

#include <iostream>   // for debug output

using namespace DIS;

DataStream::DataStream(Endian stream)
   : _buffer()
   , _read_pos(0)
   , _write_pos(0)
   , _stream_endian(stream)
   , _machine_endian(LITTLE)
{
   long one(1);
   char e = (reinterpret_cast<char*>( &one ))[0];

   if( e == (char)1 )
   {
      _machine_endian = LITTLE;
   }
   else
   {
      _machine_endian = BIG;
   }
}

DataStream::DataStream(const char* buffer, size_t length, Endian stream)
   : _buffer()
   , _read_pos(0)
   , _write_pos(0)
   , _stream_endian(stream)
   , _machine_endian(LITTLE)
{
   long one(1);
   char e = (reinterpret_cast<char*>( &one ))[0];

   if( e == (char)1 )
   {
      _machine_endian = LITTLE;
   }
   else
   {
      _machine_endian = BIG;
   }

   SetStream( buffer, length, stream );
}
DataStream::~DataStream()
{
}

//const DataStream::BufferType& DataStream::GetBuffer() const
//{
//   return _buffer;
//}

Endian DataStream::GetStreamEndian() const
{
   return _stream_endian;
}

Endian DataStream::GetMachineEndian() const
{
   return _machine_endian;
}

size_t DataStream::GetWritePos() const
{
   return _write_pos;
}

size_t DataStream::GetReadPos() const
{
   return _read_pos;
}

size_t DataStream::size() const
{
   return _buffer.size();
}

void DataStream::clear()
{
   _write_pos = 0;
   _read_pos = 0;
   _buffer.clear();
}

bool DataStream::empty() const
{
   return _buffer.empty();
}

const char& DataStream::operator [](unsigned int offset) const
{
   return _buffer[_read_pos+offset];
}

// currently copies the source data.
void DataStream::SetStream(const char* buffer, size_t length, Endian stream)
{
   // reassign the endian
   _stream_endian = stream;

   _write_pos = length;
   _read_pos = 0;

   // resize the array
   if( _buffer.size() < length )
   {
      _buffer.resize( length );
   }

   // take ownership of the data
   // copy the data, expensive!
   for(unsigned int i=0; i<length; ++i)
   {
      _buffer[i] = buffer[i];
   }
}

void DataStream::DoFlip(char* buf, size_t bufsize)
{
   if( _machine_endian == _stream_endian || bufsize<2 )
   {
      return;
   }

   // flip it, this fills back to front
   char* start = &buf[0];
   char* end = &buf[bufsize-1];
   while( start < end )
   {
      /// save the beginning of the buffer
      char temp = *start;

      /// overwrite the beginning of the buffer
      *start = *end;
      *end = temp;

      ++start;
      --end;
   }
}

void DataStream::DoWrite(const char* buf, size_t bufsize)
{
   for(unsigned int i=0; i<bufsize; ++i)
   {
      // ignores the _write_pos value currently,
      // this should allow for values to always be appended to the end of the buffer.
      _buffer.push_back( buf[i] );
   }
}

void DataStream::DoRead(char* ch, size_t bufsize)
{
   for(unsigned int i=0; i<bufsize; i++)
   {
      ch[i] = _buffer[_read_pos+i];
   }
}

// write stuff
DataStream& DataStream::operator <<(char c)
{
   WriteAlgorithm( c );
   return *this;
}

DataStream& DataStream::operator <<(unsigned char c)
{
   WriteAlgorithm( c );
   return *this;
}

DataStream& DataStream::operator <<(float f) 
{
   WriteAlgorithm( f );
   return *this;
}

DataStream& DataStream::operator <<(double d) 
{
   WriteAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator <<(int d) 
{
   WriteAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator <<(unsigned int d) 
{
   WriteAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator <<(long d)
{
   WriteAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator <<(unsigned long d)
{
   WriteAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator <<(unsigned short d)
{
   WriteAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator <<(short d)
{
   WriteAlgorithm( d );
   return *this;
}

// read stuff
DataStream& DataStream::operator >>(char& c)
{
   ReadAlgorithm( c );
   return *this;
}

DataStream& DataStream::operator >>(unsigned char& c)
{
   ReadAlgorithm( c );
   return *this;
}

DataStream& DataStream::operator >>(float& f)
{
   ReadAlgorithm( f );
   return *this;
}

DataStream& DataStream::operator >>(double& d)
{
   ReadAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator >>(int& d)
{
   ReadAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator >>(unsigned int& d)
{
   ReadAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator >>(long& d)
{
   ReadAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator >>(unsigned long& d)
{
   ReadAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator >>(unsigned short& d)
{
   ReadAlgorithm( d );
   return *this;
}

DataStream& DataStream::operator >>(short& d)
{
   ReadAlgorithm( d );
   return *this;
}
