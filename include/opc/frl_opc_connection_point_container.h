#ifndef frl_opc_connection_point_container_h_
#define frl_opc_connection_point_container_h_
#include "frl_platform.h"
#if( FRL_PLATFORM == FRL_PLATFORM_WIN32 )
#include <Windows.h>
#include <list>
#include "frl_types.h"
#include "frl_lock.h"

namespace frl
{
namespace opc
{

class ConnectionPoint;
class ConnectionPointContainer : public IConnectionPointContainer
{
private:
	std::list< ConnectionPoint* > points;
	lock::Mutex cpGuard;

protected:
	void registerInterface( const IID& interface_ );
	void unregisterInterface( const IID& interface_ );
	HRESULT getCallback( const IID& interface_, IUnknown** callBack_ );
	Bool isConnected( const IID &interface_ );

public:

	ConnectionPointContainer();
	virtual ~ConnectionPointContainer();			

	// IConnectionPointContainer implementation
	virtual HRESULT STDMETHODCALLTYPE EnumConnectionPoints( 
	/* [out] */ IEnumConnectionPoints **ppEnum);

	virtual HRESULT STDMETHODCALLTYPE FindConnectionPoint( 
	/* [in] */ REFIID riid,
	/* [out] */ IConnectionPoint **ppCP);

	virtual void OnAdvise(REFIID riid, DWORD dwCookie) {}
	virtual void OnUnadvise(REFIID riid, DWORD dwCookie) {}
};

} // namespace opc
} // FatRat Library

#endif // FRL_PLATFORM_WIN32
#endif // frl_opc_connection_point_container_h_
