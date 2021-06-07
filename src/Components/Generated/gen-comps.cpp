
#include "gen-comps.h"

#include "../../Subsystems/LoaderTools/ComponentExporter.h"

static const char* TestEnumNames[]={
    "Tower",
    "Pawn",
    "King",
    nullptr
};

TestComponent::TestComponent(Context* ctx):Component(ctx){}

void TestComponent::RegisterObject(Context *context)
{
    context->RegisterFactory<TestComponent>("minimal");
    URHO3D_ATTRIBUTE("vec3_value", Vector3, vec3_value, defaultvec3_value, AM_DEFAULT);
    URHO3D_ATTRIBUTE("vec2_value", Vector2, vec2_value, defaultvec2_value, AM_DEFAULT);
    URHO3D_ATTRIBUTE("int_value2", int, int_value2, defaultint_value2, AM_DEFAULT);
    URHO3D_ATTRIBUTE("bool_value", bool, bool_value, defaultbool_value, AM_DEFAULT);
    URHO3D_ATTRIBUTE("float_value", float, float_value, defaultfloat_value, AM_DEFAULT);
    URHO3D_ATTRIBUTE("string_value", String, string_value, defaultstring_value, AM_DEFAULT);
    URHO3D_ENUM_ATTRIBUTE("enum_value", enum_value, TestEnumNames, defaultenum_value, AM_DEFAULT);
}

CCMarker::CCMarker(Context* ctx):Component(ctx){}

void CCMarker::RegisterObject(Context *context)
{
    context->RegisterFactory<CCMarker>("minimal");
    URHO3D_ATTRIBUTE("use_node_name", bool, use_node_name, defaultuse_node_name, AM_DEFAULT);
    URHO3D_ATTRIBUTE("name", String, name, defaultname, AM_DEFAULT);
}

void register_components(Context* ctx){
    TestComponent::RegisterObject(ctx);
    CCMarker::RegisterObject(ctx);

    auto exporter = ctx->GetSubsystem<Urho3DNodeTreeExporter>();
    if (exporter){
        exporter->AddComponentHashToFilterList(TestComponent::GetTypeStatic());
        exporter->AddComponentHashToFilterList(CCMarker::GetTypeStatic());
    }

}
