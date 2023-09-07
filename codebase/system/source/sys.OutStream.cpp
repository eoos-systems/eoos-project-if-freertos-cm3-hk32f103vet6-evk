/**
 * @file      sys.OutStream.cpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2022-2023, Sergey Baigudin, Baigudin Software
 */
#include "sys.OutStream.hpp"
#include "lib.BaseString.hpp"

namespace eoos
{
namespace sys
{

OutStream::OutStream(Type type) 
    : NonCopyable<NoAllocator>()
    , api::OutStream<char_t>()
    , stream_( NULLPTR ) {
    bool_t const isConstructed( construct(type) );
    setConstructed( isConstructed );
}

OutStream::~OutStream()
{
}

bool_t OutStream::isConstructed() const
{
    return Parent::isConstructed();
}

api::OutStream<char_t>& OutStream::operator<<(char_t const* source)
{
    if( isConstructed() )
    {
//TODO        static_cast<void>( ::fputs(source, stream_) );
    }
    return *this;
}

api::OutStream<char_t>& OutStream::operator<<(int32_t value)
{
    lib::BaseString<char_t,16> str(value);
    return this->operator<<( str.getChar() );
}    

api::OutStream<char_t>& OutStream::flush()
{
    if( isConstructed() )
    {
//TODO        static_cast<void>( ::fflush(stream_) );
    }
    return *this;
}

bool_t OutStream::construct(Type type)
{
    bool_t res( false );
    while(true)
    {   
        if( !isConstructed() )
        {   ///< UT Justified Branch: HW dependency
            break;
        }
//TODO        if(type == TYPE_COUT)
//TODO        {
//TODO            stream_ = ::stdout;
//TODO        }
//TODO        else
//TODO        {
//TODO            stream_ = ::stderr;
//TODO        }            
//TODO        res = true;
        break;
    }
    return res;
}

} // namespace sys
} // namespace eoos
