/**
 * @file      sys.Semaphore.hpp
 * @author    Sergey Baigudin, sergey@baigudin.software
 * @copyright 2017-2023, Sergey Baigudin, Baigudin Software
 */
#ifndef SYS_SEMAPHORE_HPP_
#define SYS_SEMAPHORE_HPP_

#include "sys.NonCopyable.hpp"
#include "api.Semaphore.hpp"

namespace eoos
{
namespace sys
{

/**
 * @class Semaphore
 * @brief Semaphore class.
 * 
 * @tparam A Heap memory allocator class.
 */
template <class A>
class Semaphore : public NonCopyable<A>, public api::Semaphore
{
    typedef NonCopyable<A> Parent;

public:

    /**
     * @brief Constructor.
     *
     * @param permits The initial number of permits available.
     */
    explicit Semaphore(int32_t permits);

    /**
     * @brief Destructor.
     */
    virtual ~Semaphore();

    /**
     * @copydoc eoos::api::Object::isConstructed()
     */
    virtual bool_t isConstructed() const;

    /**
     * @copydoc eoos::api::Semaphore::acquire()
     */
    virtual bool_t acquire();

    /**
     * @copydoc eoos::api::Semaphore::release()
     */
    virtual void release();

protected:

    using Parent::setConstructed;

private:

    /**
     * @brief Constructs this object.
     *
     * @return true if object has been constructed successfully.
     */
    bool_t construct();

    /**
     * @brief Initializes kernel semaphore resource.
     * 
     * @return True if initialized sucessfully. 
     */
    bool_t initialize();

    /**
     * @brief Deinitializes kernel semaphore resource.
     */
    void deinitialize();

    /**
     * @brief Test if semaphore is fair.
     *
     * @return Fairness flag.
     */
    static bool_t isFair();

    /**
     * @brief Releases one permit.
     *
     * @return True on success.
     */
    bool_t post();

    /**
     * @brief Fairness flag.
     */
    bool_t isFair_;
    
    /**
     * @brief Number of permits available.
     */
    int32_t permits_;

    /**
     * @brief Semaphore resource identifier.
     */
//TODO    ::sem_t sem_;    
    uint32_t sem_;

};

template <class A>
Semaphore<A>::Semaphore(int32_t permits) 
    : NonCopyable<A>()
    , api::Semaphore()
    , isFair_(false)
    , permits_(permits)
    , sem_(){
    bool_t const isConstructed( construct() );
    setConstructed( isConstructed );
}

template <class A>
Semaphore<A>::~Semaphore()
{
    deinitialize();
}

template <class A>
bool_t Semaphore<A>::isConstructed() const ///< SCA MISRA-C++:2008 Justified Rule 10-3-1
{
    return Parent::isConstructed();
}

template <class A>
bool_t Semaphore<A>::acquire()
{
    bool_t res( false );
    if( isConstructed() )
    {
//TODO        int_t const error( ::sem_wait(&sem_) );
//TODO        if(error == 0) 
//TODO        { 
//TODO            res = true; 
//TODO        }
    }
    return res;
}

template <class A>
void Semaphore<A>::release()
{
    if( isConstructed() )
    {
        bool_t const isPosted( post() );
        if ( !isPosted )
        {   ///< UT Justified Branch: OS dependency
            setConstructed(false);
        }
    }
}

template <class A>
bool_t Semaphore<A>::construct()
{
    bool_t res( false );
    do {
        if( !isConstructed() )
        {   ///< UT Justified Branch: HW dependency
            break;
        }
        if( !initialize() )
        {
            break;
        }
        isFair_ = isFair();
        res = true;
    } while(false);
    return res;
}

template <class A>
bool_t Semaphore<A>::initialize()
{
//TODO    int_t const error( ::sem_init(&sem_, 0, static_cast<uint_t >(permits_)) );
//TODO    return error == 0;
    return false;
}

template <class A>
void Semaphore<A>::deinitialize()
{
//TODO    static_cast<void>( ::sem_destroy(&sem_) );
}


template <class A>
bool_t Semaphore<A>::isFair()
{
//TODO    int_t const priority( ::sched_getscheduler(0) );
//TODO    return ( (priority == SCHED_FIFO) || (priority == SCHED_RR) ) ? true : false;  ///< SCA MISRA-C++:2008 Justified Rule 16-2-2
    return false;
}

template <class A>
bool_t Semaphore<A>::post()
{
//TODO    bool_t res( true );
//TODO    int_t const error( ::sem_post(&sem_) );
//TODO    if (error != 0)
//TODO    {   ///< UT Justified Branch: OS dependency
//TODO        res = false;
//TODO    }
//TODO    return res;
    return false;
}
        
} // namespace sys
} // namespace eoos
#endif // SYS_SEMAPHORE_HPP_
