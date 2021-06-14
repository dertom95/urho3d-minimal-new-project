#pragma once

#include <Urho3D/Urho3DAll.h>

static const ResourceRef default_testcomponent_idleanim(Animation::GetTypeStatic(),"");
static const ResourceRef default_testcomponent_material(Material::GetTypeStatic(),"");
static const ResourceRef default_testcomponent_model(Model::GetTypeStatic(),"");
static const ResourceRef default_testcomponent_particleeffect(ParticleEffect::GetTypeStatic(),"");
static const ResourceRef default_testcomponent_sound(Sound::GetTypeStatic(),"");
enum TestEnum {
    te_Tower=0,
    te_Pawn,
    te_King,
};
static const TestEnum default_testcomponent_testtype = te_Pawn;
static const ResourceRef default_testcomponent_tex(Texture2D::GetTypeStatic(),"");
static const ResourceRef default_testcomponent_texcube(TextureCube::GetTypeStatic(),"");
static const bool default_testcomponent_bool_value = false;
static const float default_testcomponent_float_value = 18.95f;
static const int default_testcomponent_int_value2 = 1895;
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
    //
    virtual void DelayedStart() override;
    //
    virtual void Update(float dt) override;
    //
    void SomeConstMethod() const;
    //
    ResourceRef GetIdleAnim() const;
    //
    void SetIdleAnim(ResourceRef value);
    //
    ResourceRef GetMaterial() const;
    //
    void SetMaterial(ResourceRef value);
    //
    ResourceRef GetModel() const;
    //
    void SetModel(ResourceRef value);
    //
    ResourceRef GetParticleEffect() const;
    //
    void SetParticleEffect(ResourceRef value);
    //
    ResourceRef GetSound() const;
    //
    void SetSound(ResourceRef value);
    //
    TestEnum GetTestType() const;
    //
    void SetTestType(TestEnum value);
    //
    ResourceRef GetTex() const;
    //
    void SetTex(ResourceRef value);
    //
    ResourceRef GetTexCube() const;
    //
    void SetTexCube(ResourceRef value);
    //
    String GetStringValue2() const;
    //
    void SetStringValue(String value);

public:
    // Addition of a1+a2. Return the result
    virtual int add(int a1,int a2);

private:
    //
    bool bool_value=default_testcomponent_bool_value;
    //
    float float_value=default_testcomponent_float_value;
    //
    String string_value=default_testcomponent_string_value;
    //
    String string2_value=default_testcomponent_string2_value;
    // Component Type
    TestEnum TestType=default_testcomponent_testtype;
    //
    ResourceRef IdleAnim=default_testcomponent_idleanim;
    //
    ResourceRef Tex=default_testcomponent_tex;
    //
    ResourceRef Model=default_testcomponent_model;
    //
    ResourceRef TexCube=default_testcomponent_texcube;
    //
    ResourceRef Material=default_testcomponent_material;
    //
    ResourceRef ParticleEffect=default_testcomponent_particleeffect;
    //
    ResourceRef Sound=default_testcomponent_sound;

protected:
    //
    int int_value2=default_testcomponent_int_value2;

public:
    // Position Indicator Bla
    Vector3 vec3_value=default_testcomponent_vec3_value;
    //
    Vector2 vec2_value=default_testcomponent_vec2_value;
};
static const float default_character_currentspeed = 0;
static const ResourceRef default_character_idleanim(Animation::GetTypeStatic(),"");
static const float default_character_maxspeed = 10;
static const String default_character_name = "";
static const ResourceRef default_character_runanim(Animation::GetTypeStatic(),"");
static const ResourceRef default_character_walkanim(Animation::GetTypeStatic(),"");

class Character : public Component
{
    URHO3D_OBJECT(Character,Component);
public:
    static void RegisterObject(Context *context);

    Character(Context* ctx);

private:
    //
    ResourceRef GetIdleAnim() const;
    //
    void SetIdleAnim(ResourceRef value);
    //
    ResourceRef GetRunAnim() const;
    //
    void SetRunAnim(ResourceRef value);
    //
    ResourceRef GetWalkAnim() const;
    //
    void SetWalkAnim(ResourceRef value);


private:
    //
    String Name=default_character_name;
    //
    float MaxSpeed=default_character_maxspeed;
    //
    float CurrentSpeed=default_character_currentspeed;
    //
    ResourceRef IdleAnim=default_character_idleanim;
    //
    ResourceRef WalkAnim=default_character_walkanim;
    //
    ResourceRef RunAnim=default_character_runanim;


};
static const int default_supercharacter_superint = 10;

class SuperCharacter : public Character
{
    URHO3D_OBJECT(SuperCharacter,Character);
public:
    static void RegisterObject(Context *context);

    SuperCharacter(Context* ctx);



private:
    //
    int SuperInt=default_supercharacter_superint;


};
static const bool default_basetrigger_one_time = false;

class BaseTrigger : public Component
{
    URHO3D_OBJECT(BaseTrigger,Component);
public:
    static void RegisterObject(Context *context);

    BaseTrigger(Context* ctx);



private:
    //
    bool one_time=default_basetrigger_one_time;


};
enum DefaultTriggerType {
    tt_powerup,
    tt_death,
    tt_bonus_life,
    tt_paralyze,
};
static const DefaultTriggerType default_defaulttrigger_trigger_type = tt_powerup;

class DefaultTrigger : public BaseTrigger
{
    URHO3D_OBJECT(DefaultTrigger,BaseTrigger);
public:
    static void RegisterObject(Context *context);

    DefaultTrigger(Context* ctx);



private:
    //
    DefaultTriggerType trigger_type=default_defaulttrigger_trigger_type;


};
enum ActionTriggerType {
    at_open,
    at_close,
    at_enable_physics,
};
static const ActionTriggerType default_actiontrigger_action_trigger = at_open;
static const String default_actiontrigger_object_obj = "";

class ActionTrigger : public BaseTrigger
{
    URHO3D_OBJECT(ActionTrigger,BaseTrigger);
public:
    static void RegisterObject(Context *context);

    ActionTrigger(Context* ctx);



private:
    //
    ActionTriggerType action_trigger=default_actiontrigger_action_trigger;
    //
    String object_OBJ=default_actiontrigger_object_obj;


};

void register_components(Context* ctx);
