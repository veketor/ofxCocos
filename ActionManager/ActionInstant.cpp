#include "ActionInstant.h"
#include "ofLog.h"

OFXCOCOS_NS_BEGIN
ACTIONS_NS_BEGIN

ActionInstant *ActionInstant::clone() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": ActionInstant doesn't support clone.";
    return nullptr;
}

ActionInstant *ActionInstant::reverse() const
{
    ofLogError("ofxActionManager") << __FUNCTION__ << ": ActionInstant doesn't support reverse.";
    return nullptr;
}

bool ActionInstant::isDone() const
{
    return true;
}

void ActionInstant::step(float dt)
{
    (void)dt;
    const float updateDt = 1;
    update(updateDt);
}

void ActionInstant::update(float time)
{
    (void)time;
}

ACTIONS_NS_END
OFXCOCOS_NS_END
