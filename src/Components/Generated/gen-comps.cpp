
#include "gen-comps.h"

#include "../../Subsystems/LoaderTools/ComponentExporter.h"

static const char* TestEnumNames[]={
    "Tower",
    "Pawn",
    "King",
    nullptr
};

TestComponent::TestComponent(Context* ctx):LogicComponent(ctx){}

void TestComponent::RegisterObject(Context *context)
{
    context->RegisterFactory<TestComponent>("minimal");
    URHO3D_ATTRIBUTE("vec3_value", Vector3, vec3_value, default_testcomponent_vec3_value, AM_DEFAULT);
    URHO3D_ATTRIBUTE("vec2_value", Vector2, vec2_value, default_testcomponent_vec2_value, AM_DEFAULT);
    URHO3D_ATTRIBUTE("int_value2", int, int_value2, default_testcomponent_int_value2, AM_DEFAULT);
    URHO3D_ATTRIBUTE("bool_value", bool, bool_value, default_testcomponent_bool_value, AM_DEFAULT);
    URHO3D_ATTRIBUTE("float_value", float, float_value, default_testcomponent_float_value, AM_DEFAULT);
    URHO3D_ATTRIBUTE("string_value", String, string_value, default_testcomponent_string_value, AM_DEFAULT);
    URHO3D_ENUM_ATTRIBUTE("enum_value", enum_value, TestEnumNames, default_testcomponent_enum_value, AM_DEFAULT);
}

CCMarker::CCMarker(Context* ctx):Component(ctx){}

void CCMarker::RegisterObject(Context *context)
{
    context->RegisterFactory<CCMarker>("minimal");
    URHO3D_ATTRIBUTE("use_node_name", bool, use_node_name, default_ccmarker_use_node_name, AM_DEFAULT);
    URHO3D_ATTRIBUTE("name", String, name, default_ccmarker_name, AM_DEFAULT);
}

Character::Character(Context* ctx):Component(ctx){}

void Character::RegisterObject(Context *context)
{
    context->RegisterFactory<Character>("catch");
    URHO3D_ATTRIBUTE("name", String, name, default_character_name, AM_DEFAULT);
    URHO3D_ATTRIBUTE("max_energy", float, max_energy, default_character_max_energy, AM_DEFAULT);
    URHO3D_ATTRIBUTE("current_energy", float, current_energy, default_character_current_energy, AM_DEFAULT);
}

void register_components(Context* ctx){
    TestComponent::RegisterObject(ctx);
    CCMarker::RegisterObject(ctx);
    Character::RegisterObject(ctx);

    auto exporter = ctx->GetSubsystem<Urho3DNodeTreeExporter>();
    if (exporter){
        exporter->AddComponentHashToFilterList(TestComponent::GetTypeStatic());
        exporter->AddComponentHashToFilterList(CCMarker::GetTypeStatic());
        exporter->AddComponentHashToFilterList(Character::GetTypeStatic());
    }

}
