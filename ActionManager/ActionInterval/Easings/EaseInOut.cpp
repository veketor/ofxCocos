#include "EaseInOut.h"

OFXCOCOS_NS_BEGIN
ACTIONS_NS_BEGIN

EaseInOut::EaseInOut()
{

}

EaseInOut *EaseInOut::create(ActionInterval *action, float rate)
{
    EaseInOut *easeInOut = new(std::nothrow) EaseInOut();
    if (easeInOut) {
        if (easeInOut->initWithAction(action, rate) == false) {
            SAFE_RELEASE(easeInOut);
        }
    }

    return easeInOut;
}

EaseInOut *EaseInOut::clone() const
{
    // no copy constructor
    auto a = new(std::nothrow) EaseInOut();
    a->initWithAction(m_Inner->clone(), m_Rate);
    return a;
}

void EaseInOut::update(float time)
{
    m_Inner->update(tweenfunc::easeInOut(time, m_Rate));
}

// InOut and OutIn are symmetrical
EaseInOut *EaseInOut::reverse() const
{
    return EaseInOut::create(m_Inner->reverse(), m_Rate);
}

ACTIONS_NS_END
OFXCOCOS_NS_END
