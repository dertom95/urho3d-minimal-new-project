#pragma once

#include <Urho3D/Urho3DAll.h>

static const bool default_testcomponent_bool_value = false; /* 1 */
enum TestEnum {
    te_Tower=0,
    te_Pawn,
    te_King,
};
static const TestEnum default_testcomponent_enum_value = te_Pawn;

static const float default_testcomponent_float_value = 18.95f; /* 1 */
static const int default_testcomponent_int_value2 = 1895; /* 1 */
static const String default_testcomponent_string2_value = "goal";
static const String default_testcomponent_string_value = "Fortuna!";
static const Vector2 default_testcomponent_vec2_value(1.0f,0.0f);
static const Vector3 default_testcomponent_vec3_value(1.0f,0.0f,0.0f);

class TestComponent : public LogicComponent
{
    URHO3D_OBJECT(TestComponent,LogicComponent);
public:
    static void RegisterObject(Context *context);

    TestComponent(Context* ctx);

private:
    virtual void DelayedStart() override;
    virtual void Update(float dt) override;

public:
    virtual int add(int a1,int a2);

private:
    bool bool_value=default_testcomponent_bool_value;
    float float_value=default_testcomponent_float_value;
    String string_value=default_testcomponent_string_value;
    String string2_value=default_testcomponent_string2_value;
    TestEnum enum_value=default_testcomponent_enum_value;

protected:
    int int_value2=default_testcomponent_int_value2;

public:
    Vector3 vec3_value=default_testcomponent_vec3_value;
    Vector2 vec2_value=default_testcomponent_vec2_value;
};
static const String default_ccmarker_name = "";
static const bool default_ccmarker_use_node_name = true; /* 1 */

class CCMarker : public Component
{
    URHO3D_OBJECT(CCMarker,Component);
public:
    static void RegisterObject(Context *context);

    CCMarker(Context* ctx);



private:
    bool use_node_name=default_ccmarker_use_node_name;
    String name=default_ccmarker_name;


};
static const float default_character_current_energy = 0.0f; /* 1 */
static const float default_character_max_energy = 5.0f; /* 1 */
static const String default_character_name = "";

class Character : public Component
{
    URHO3D_OBJECT(Character,Component);
public:
    static void RegisterObject(Context *context);

    Character(Context* ctx);



private:
    String name=default_character_name;
    float max_energy=default_character_max_energy;
    float current_energy=default_character_current_energy;


};

void register_components(Context* ctx);
