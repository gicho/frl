require 'mxx_ru/cpp'

MxxRu::Cpp::exe_target("frl.test.opc_server.release.rb")\
{
	required_prj( "frl.lib.release.rb" )
	target("test_opc_server")
	include_path("../../../test/opc_server")
	runtime_mode( MxxRu::Cpp::RUNTIME_RELEASE )
	rtl_mode( MxxRu::Cpp::RTL_STATIC )
	threading_mode( MxxRu::Cpp::THREADING_MULTI )
	obj_placement( MxxRu::Cpp::CustomSubdirObjPlacement.new( "../../../output/test/opc_server",\
	"../../../output/test/opc_server/obj/#{mxx_runtime_mode}/1/2/3" ) )
	cpp_sources Dir.glob( "../../../test/opc_server/**/*.cpp" )
}
