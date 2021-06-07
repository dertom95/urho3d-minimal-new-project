#include "LuaAPI.h"

SomeObject::SomeObject(int _count):count(_count){}

int Add(int a,int b) {
   return a+b;
}

void NodeTranslate(Node* node, Vector3 translate)
{
    node->Translate(translate);
}
