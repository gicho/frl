#ifndef frl_opc_async_request_h_
#define frl_opc_async_request_h_
#include "frl_platform.h"
#if( FRL_PLATFORM == FRL_PLATFORM_WIN32 )
#include <Windows.h>
#include <list>
#include "..\dependency\vendors\opc_foundation\opcda.h"
#include "frl_types.h"
#include "frl_exception.h"
#include "frl_non_copyable.h"
#include "frl_smart_ptr.h"

namespace frl
{
namespace opc
{
class AsyncRequest
{
private:
	DWORD id;
	DWORD cancelID;
	Bool cancelled;
	std::list< OPCHANDLE > handles;
	VARIANT *values;
	DWORD source;
public:
	FRL_EXCEPTION_CLASS( InvalidParameter );
	AsyncRequest();
	AsyncRequest( const std::list< OPCHANDLE > &handles_ );
	AsyncRequest( const AsyncRequest &request );
	~AsyncRequest();
	void setTransactionID( DWORD id_ );
	DWORD getTransactionID() const;
	DWORD getCancelID();
	Bool isCancelled();
	void isCancelled( Bool isCancelled_ );
	void init( const std::list< OPCHANDLE > &handles_ );
	void init( const std::list< OPCHANDLE > &handles_, const VARIANT *values_ );
	const std::list<OPCHANDLE>& getHandles() const;
	size_t getCounts() const;
	const VARIANT* getValues() const;
	void removeHandle( OPCHANDLE handle );
	DWORD getSource() const;
	void setSource( DWORD source_ );
	static DWORD getUniqueCancelID();
	AsyncRequest& operator = ( const AsyncRequest &rvl );
	void swap( AsyncRequest &req );
}; // class AsyncRequest

typedef frl::SmartPtr< AsyncRequest, frl::smart_ptr::OwnerRefCount > AsyncRequestListElem;
typedef std::list< AsyncRequestListElem > AsyncRequestList;

} // namespace opc
} // namespace frl

#endif // FRL_PLATFORM == FRL_PLATFORM_WIN32
#endif // frl_opc_async_request_h_
