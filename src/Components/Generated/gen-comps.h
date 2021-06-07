#pragma once

#include <Urho3D/Urho3DAll.h>

static const bool defaultbool_value = false; /* 1 */
enum TestEnum {
    te_Tower=0,
    te_Pawn,
    te_King,
};
static const TestEnum defaultenum_value = te_Pawn;

static const float defaultfloat_value = 18.95f; /* 1 */
static const int defaultint_value2 = 1895; /* 1 */
static const String defaultstring_value = "Fortuna!";
static const Vector2 defaultvec2_value(1.0f,0.0f);
static const Vector3 defaultvec3_value(1.0f,0.0f,0.0f);

class TestComponent : public Component
{
    URHO3D_OBJECT(TestComponent,Component);
public:
    static void RegisterObject(Context *context);

    TestComponent(Context* ctx);

//    const Vector3& GetGroupOffset() const  { return groupOffset;}
//    void SetGroupOffset(const Vector3& groupOffset);

private:
    Vector3 vec3_value=defaultvec3_value;
    Vector2 vec2_value=defaultvec2_value;
    int int_value2=defaultint_value2;
    bool bool_value=defaultbool_value;
    float float_value=defaultfloat_value;
    String string_value=defaultstring_value;
    TestEnum enum_value=defaultenum_value;
};
static const String defaultname = "";
static const bool defaultuse_node_name = true; /* 1 */

class CCMarker : public Component
{
    URHO3D_OBJECT(CCMarker,Component);
public:
    static void RegisterObject(Context *context);

    CCMarker(Context* ctx);

//    const Vector3& GetGroupOffset() const  { return groupOffset;}
//    void SetGroupOffset(const Vector3& groupOffset);

private:
    bool use_node_name=defaultuse_node_name;
    String name=defaultname;
};

void register_components(Context* ctx);
