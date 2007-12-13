#include "frl_platform.h"
#if( FRL_PLATFORM == FRL_PLATFORM_WIN32 )
#include "opc/frl_opc_group_item.h"
#include "../dependency/vendors/opc_foundation/opcerror.h"
#include "opc/address_space/frl_opc_address_space.h"

namespace frl
{
	namespace opc
	{
		GroupItem::GroupItem()
		{
			Init();
		}

		GroupItem::~GroupItem()
		{

		}

		void GroupItem::Init()
		{
			serverHandle = 0;
			clientHandle = 0;
			itemID = FRL_STR("");
			accessPath = FRL_STR("");
			actived = false;
			requestDataType = VT_EMPTY;
		}

		void GroupItem::Init( OPCHANDLE serverHandle_, OPCITEMDEF &itemDef )
		{
			Init();
			serverHandle = serverHandle_;
			clientHandle = itemDef.hClient;
			itemID = itemDef.szItemID;
			accessPath = itemDef.szAccessPath;
			actived = ( itemDef.bActive == TRUE );
			requestDataType = itemDef.vtRequestedDataType;
		}

		void GroupItem::isActived( Bool activedFlag )
		{
			actived = activedFlag;
		}

		frl::Bool GroupItem::isActived()
		{
			return actived;
		}
		void GroupItem::setClientHandle( OPCHANDLE handle )
		{
			clientHandle = handle;
		}

		void GroupItem::setRequestDataType( VARTYPE type )
		{
			requestDataType = type;
		}

		OPCHANDLE GroupItem::getClientHandle()
		{
			return clientHandle;
		}

		const String& GroupItem::getItemID()
		{
			return itemID;
		}

		const String& GroupItem::getAccessPath()
		{
			return accessPath;
		}

		VARTYPE GroupItem::getReguestDataType()
		{
			return requestDataType;
		}

		HRESULT GroupItem::readValue( VARIANT &value )
		{
			if( ! opcAddressSpace.isExistTag( serverHandle ) )
				return OPC_E_INVALIDHANDLE;

			return E_NOTIMPL;
		}

		HRESULT GroupItem::writeValue( const VARIANT &newValue )
		{
			return E_NOTIMPL;
		}
	} // namespace opc
} // namespace FatRat Library

#endif /* FRL_PLATFORM_WIN32 */
