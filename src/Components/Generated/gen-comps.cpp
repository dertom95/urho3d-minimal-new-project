
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
    URHO3D_ACCESSOR_ATTRIBUTE("string_value", GetStringValue2, SetStringValue, String, default_testcomponent_string_value, AM_DEFAULT);
    URHO3D_ENUM_ACCESSOR_ATTRIBUTE("TestType",GetTestType,SetTestType,TestEnum, TestEnumNames, default_testcomponent_testtype, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("IdleAnim", GetIdleAnim, SetIdleAnim, ResourceRef, default_testcomponent_idleanim, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("Tex", GetTex, SetTex, ResourceRef, default_testcomponent_tex, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("Model", GetModel, SetModel, ResourceRef, default_testcomponent_model, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("TexCube", GetTexCube, SetTexCube, ResourceRef, default_testcomponent_texcube, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("Material", GetMaterial, SetMaterial, ResourceRef, default_testcomponent_material, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("ParticleEffect", GetParticleEffect, SetParticleEffect, ResourceRef, default_testcomponent_particleeffect, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("Sound", GetSound, SetSound, ResourceRef, default_testcomponent_sound, AM_DEFAULT);
}

Character::Character(Context* ctx):Component(ctx){}

void Character::RegisterObject(Context *context)
{
    context->RegisterFactory<Character>("catch");
    URHO3D_ATTRIBUTE("Name", String, Name, default_character_name, AM_DEFAULT);
    URHO3D_ATTRIBUTE("MaxSpeed", float, MaxSpeed, default_character_maxspeed, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("IdleAnim", GetIdleAnim, SetIdleAnim, ResourceRef, default_character_idleanim, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("WalkAnim", GetWalkAnim, SetWalkAnim, ResourceRef, default_character_walkanim, AM_DEFAULT);
    URHO3D_ACCESSOR_ATTRIBUTE("RunAnim", GetRunAnim, SetRunAnim, ResourceRef, default_character_runanim, AM_DEFAULT);
}



void register_components(Context* ctx){
    TestComponent::RegisterObject(ctx);
    Character::RegisterObject(ctx);

    auto exporter = ctx->GetSubsystem<Urho3DNodeTreeExporter>();
    if (exporter){
        exporter->AddComponentHashToFilterList(TestComponent::GetTypeStatic());
        exporter->AddComponentHashToFilterList(Character::GetTypeStatic());
    }

}

