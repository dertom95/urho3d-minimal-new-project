#pragma once

#include <Urho3D/Urho3DAll.h>

static const bool default_testcomponent_bool_value = false;
enum TestEnum {
    te_Tower=0,
    te_Pawn,
    te_King,
};
static const TestEnum default_testcomponent_enum_value = te_Pawn;
static const float default_testcomponent_float_value = 18.95f;
static const int default_testcomponent_int_value2 = 1895;
static const String default_testcomponent_string_value = "Fortuna!";
static const Vector2 default_testcomponent_vec2_value(1.0f,0.0f);
static const Vector3 default_testcomponent_vec3_value(1.0f,0.0f,0.0f);

class TestComponent : public Component
{
    URHO3D_OBJECT(TestComponent,Component);

public:
    static void RegisterObject(Context *context);

    TestComponent(Context* ctx);
    virtual ~TestComponent();
private:





public:
    //
    Vector3 vec3_value=default_testcomponent_vec3_value;
    //
    Vector2 vec2_value=default_testcomponent_vec2_value;
    //
    int int_value2=default_testcomponent_int_value2;
    //
    bool bool_value=default_testcomponent_bool_value;
    //
    float float_value=default_testcomponent_float_value;
    //
    String string_value=default_testcomponent_string_value;
    //
    TestEnum enum_value=default_testcomponent_enum_value;
};
static const String default_ccmarker_name = "";
static const bool default_ccmarker_use_node_name = true;

class CCMarker : public Component
{
    URHO3D_OBJECT(CCMarker,Component);

public:
    static void RegisterObject(Context *context);

    CCMarker(Context* ctx);
    virtual ~CCMarker();
private:





public:
    //
    bool use_node_name=default_ccmarker_use_node_name;
    //
    String name=default_ccmarker_name;
};

void register_components(Context* ctx);
