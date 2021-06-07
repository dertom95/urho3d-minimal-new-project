#pragma once
#include <project_options.h>

#ifdef GAME_ENABLE_LUA_SCRIPTING

#include <Urho3D/Scene/Node.h>

using namespace Urho3D;

int Add(int a,int b);
void NodeTranslate(Node* node, Vector3 translate);

class SomeObject{
public:
    SomeObject(int _count);

    int count;
    Node* node;
};
#endif

